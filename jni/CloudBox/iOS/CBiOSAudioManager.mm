//
//  CBiOSAudioManager.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/6/24.
//  Copyright 2012 Orz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import "CBiOSAudioManager.h"
#import "CBLibrary.h"

AVAudioPlayer* m_musicPlayer;

CBiOSAudioManager::CBiOSAudioManager()
:CBAudioBase()
{
    m_musicPlayer = nil;
}

CBiOSAudioManager::~CBiOSAudioManager()
{
    releaseMusic();
}

void CBiOSAudioManager::loadMusic(const string fileName)
{
    if(m_musicPlayer == nil)
    {
        NSString *name = [[NSString alloc] initWithUTF8String: fileName.c_str()];
        NSError *error = nil;
        NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:nil];
        NSURL *url = [NSURL fileURLWithPath:path];
        m_musicPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];
        m_state = AudioReady;
        m_musicPlayer.volume = 1.0;
        [m_musicPlayer setNumberOfLoops: -1];
        [m_musicPlayer prepareToPlay];
    }
}
void CBiOSAudioManager::releaseMusic()
{
    if(m_musicPlayer != nil)
    {
        [m_musicPlayer release];
        m_musicPlayer = nil;
    }
}
void CBiOSAudioManager::CBiOSAudioManager::playMusic()
{
    if(m_state == AudioReady)
    {
        UInt32 category = kAudioSessionCategory_SoloAmbientSound;
        AudioSessionSetProperty (kAudioSessionProperty_AudioCategory, sizeof (category), &category);
        AudioSessionSetActive (true);
        [m_musicPlayer play];
        m_state = AudioPlaying;
        DebugLog("Play music\n");
    }
}
void CBiOSAudioManager::stopMusic()
{
    if(m_state == AudioPlaying)
    {
        [m_musicPlayer stop];
        m_musicPlayer.currentTime = 0;
        AudioSessionSetActive (false);
        m_state = AudioReady;
        DebugLog("Stop music\n");
    }
}
void CBiOSAudioManager::pauseMusic()
{
    if(m_state == AudioPlaying)
    {
        [m_musicPlayer pause];
        AudioSessionSetActive (false);
        m_state = AudioReady;
        DebugLog("Pause music\n");
    }
}
void CBiOSAudioManager::resumeMusic()
{
    if(m_state == AudioPause)
    {
        [m_musicPlayer play];
        AudioSessionSetActive (true);
        m_state = AudioReady;
        DebugLog("Resume music\n");
    }
}

float CBiOSAudioManager::getVolume()
{
    return m_musicPlayer.volume;
}
void CBiOSAudioManager::setVolume(float volume)
{
    if(volume > 1)
        volume = 1.0;
    if(volume < 0)
        volume = 0.0;
    m_musicPlayer.volume = volume;
}