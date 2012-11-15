//
//  CBiOSSoundManager.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/6/24.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBIOSSOUNDMANAGER_H_
#define _CBIOSSOUNDMANAGER_H_

#include "CBSoundBase.h"
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <map>
#include <vector>
using namespace std;

class CBiOSSoundManager : public CBSoundBase
{
private:
    map<string,ALuint> m_sounds;
    vector<ALuint> m_bufferStorageArray;
    ALCcontext *m_Context;
    ALCdevice *m_Device;
    void initOpenAL();
    float m_volume;
public:
    CBiOSSoundManager();
    ~CBiOSSoundManager();
    
    void initial();
    // using wave file.
    void loadSound(const string fileName);
    //void releaseSound(const string fileName);
    void releaseAllSound();
    void playSound(const string fileName);
    void stopSound(const string fileName);
    
    float getVolume();
    void setVolume(float volume);
};

#endif
