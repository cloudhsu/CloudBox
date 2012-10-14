//
//  CBiOSEffectManager.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/6/24.
//  Copyright 2012 Orz. All rights reserved.
//

#import "CBiOSEffectManager.h"
#import "CBLibrary.h"
#import <AudioToolbox/AudioToolbox.h>
#import <Foundation/Foundation.h>

CBiOSEffectManager::CBiOSEffectManager()
:m_volume(1)
{
}

CBiOSEffectManager::~CBiOSEffectManager()
{
    //releaseAllEffect();
}

void CBiOSEffectManager::initialEffect()
{
    initOpenAL();
}

void CBiOSEffectManager::initOpenAL()
{
    AudioSessionSetActive(YES);
    ALCdevice* device = NULL;
    ALCcontext* currentContext = NULL;
    device = alcOpenDevice(NULL);
    if (device) {
        currentContext = alcCreateContext(device, NULL);
        alcMakeContextCurrent(currentContext);
    }
}

#define TestAudioFormatNativeEndian(f)  ((f.mFormatID == kAudioFormatLinearPCM) && ((f.mFormatFlags & kAudioFormatFlagIsBigEndian) == kAudioFormatFlagsNativeEndian))

void CBiOSEffectManager::loadEffect(const string fileName)
{
    if( m_effects.find(fileName) == m_effects.end() )
	{
        // load file from resources
        NSString *name = [[NSString alloc] initWithUTF8String: fileName.c_str()];
        NSString *fullName=[[NSBundle mainBundle] pathForResource:name ofType:nil];
        AudioFileID fileID;
        NSURL *afurl=[NSURL fileURLWithPath:fullName];
        OSStatus result = AudioFileOpenURL((CFURLRef)afurl, kAudioFileReadPermission, 0, &fileID);
        if (result!=0) {
            NSLog(@"cannot openf file:%@\n",fullName);
            return;
        }
        
        AudioStreamBasicDescription outFormat;
        UInt32 thePropSize = sizeof(outFormat);
        
        result = AudioFileGetProperty(fileID, kAudioFilePropertyDataFormat, &thePropSize, &outFormat);
        DebugLog("File name:%s\n",fileName.c_str());
        DebugLog("SampleRate:%f FormatID:%ld FormatFlags:%ld \n BytesPerPacket:%ld FramesPerPacket:%ld BytesPerFrame:%ld \n mChannelsPerFrame:%ld mBitsPerChannel:%ld mReserved:%ld \n", outFormat.mSampleRate, outFormat.mFormatID, outFormat.mFormatFlags, outFormat.mBytesPerPacket,
                  outFormat.mFramesPerPacket, outFormat.mBytesPerFrame, outFormat.mChannelsPerFrame,
                  outFormat.mBitsPerChannel, outFormat.mReserved);
        
        if (!TestAudioFormatNativeEndian(outFormat) && (outFormat.mBitsPerChannel > 8))
        {
            DebugLog("kEffectEngineErrInvalidFileFormat\n");
        }
        
        UInt32 maxPacketSize;
        thePropSize = sizeof(outFormat);
        result = AudioFileGetProperty(fileID, kAudioFilePropertyMaximumPacketSize, &thePropSize, &maxPacketSize);
        
        //calculate file size
        UInt64 outDataSize=0;
        thePropSize = sizeof(UInt64);
	
        result = AudioFileGetProperty(fileID, kAudioFilePropertyAudioDataByteCount, &thePropSize, &outDataSize);
        if (result!=0) {
            NSLog(@"cannot find file size\n");
            return;
        }
	
        UInt32 fileSize = (UInt32)outDataSize;
    
//        UInt32 STREAM_BUFFER_SIZE = fileSize * 2;
//        unsigned char* outdata = (unsigned char *)malloc(STREAM_BUFFER_SIZE);
//        UInt32 loadSize = STREAM_BUFFER_SIZE;
//        //UInt32 STREAM_PACKETS = maxPacketSize / outFormat.mBytesPerPacket;
//        AudioStreamPacketDescription* packetDesc;
//        UInt32 numPackets = 1;
//        UInt32 packetsLoaded = 0;
//        result = AudioFileReadPacketData(fileID, NO, &loadSize, packetDesc, packetsLoaded, &numPackets, outdata);
        // read audio data to byte array
        unsigned char *outdata = (unsigned char *)malloc(fileSize);
        OSStatus result1=noErr;
        result1 = AudioFileReadBytes(fileID, false, 0, &fileSize, outdata);
        AudioFileClose(fileID);
        if (result1!=0)
        {
            NSLog(@"cannot load effect:%@\n",fullName);
            return;
        }
        
        // generate al buffer
        ALuint bufferID;
        alGenBuffers(1, &bufferID);
        //alBufferData(bufferID, AL_FORMAT_STEREO16, outdata, fileSize, 44100);
        alBufferData(bufferID, AL_FORMAT_STEREO16, outdata, fileSize, outFormat.mSampleRate);
        //alBufferData(bufferID, AL_FORMAT_STEREO16, outdata, loadSize, outFormat.mSampleRate);
        m_bufferStorageArray.push_back(bufferID);
    
        // generate source id and binding buffer to source
        ALuint sourceID;
        alGenSources(1, &sourceID);
        alSourcei(sourceID, AL_BUFFER, bufferID);
        alSourcef(sourceID, AL_PITCH, 1.0f);
        alSourcef(sourceID, AL_GAIN, 1.0f);
        //if (loops) {
        //    alSourcei(sourceID, AL_LOOPING, AL_TRUE);
        //}
        m_effects[fileName] = sourceID;
        free(outdata);
        outdata = NULL;
    }
}
//void CBiOSEffectManager::releaseEffect(const string fileName)
//{
//    
//}
void CBiOSEffectManager::releaseAllEffect()
{
    for (std::map<string,ALuint >::iterator it = m_effects.begin(); it != m_effects.end(); ++it)
    {
        ALuint sourceID = it->second;          
        alDeleteSources(1, &sourceID);
    }
	m_effects.clear();
    
    for (int i = 0 ; i < m_bufferStorageArray.size() ; i++)
    {
        ALuint sourceID = m_bufferStorageArray[i];          
        alDeleteSources(1, &sourceID);
    }
	m_bufferStorageArray.clear();
    ALCcontext* currentContext = NULL;
    ALCdevice* device = NULL;
    alcDestroyContext(currentContext);
    //Close device
    alcCloseDevice(device);
}
void CBiOSEffectManager::playEffect(const string fileName)
{
    if( !(m_effects.find(fileName) == m_effects.end()) )
	{
        ALuint sourceID = m_effects[fileName];
        alSourcef(sourceID, AL_GAIN, m_volume);
        alSourcePlay(sourceID);
    }
}
void CBiOSEffectManager::stopEffect(const string fileName)
{
    if( !(m_effects.find(fileName) == m_effects.end()) )
	{
        ALuint sourceID = m_effects[fileName];
        alSourceStop(sourceID);
    }
}

float CBiOSEffectManager::getVolume()
{
    return m_volume;
}
void CBiOSEffectManager::setVolume(float volume)
{
    if(volume > 1)
        volume = 1.0;
    if(volume < 0)
        volume = 0.0;
    m_volume = volume;
}