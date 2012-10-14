//
//  CBiOSEffectManager.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/6/24.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBIOSEFFECTMANAGER_H_
#define _CBIOSEFFECTMANAGER_H_

#include "CBEffectBase.h"
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <map>
#include <vector>
using namespace std;

class CBiOSEffectManager : public CBEffectBase
{
private:
    map<string,ALuint> m_effects;
    vector<ALuint> m_bufferStorageArray;
    void initOpenAL();
    float m_volume;
public:
    CBiOSEffectManager();
    ~CBiOSEffectManager();
    
    void initialEffect();
    // using wave file.
    void loadEffect(const string fileName);
    //void releaseEffect(const string fileName);
    void releaseAllEffect();
    void playEffect(const string fileName);
    void stopEffect(const string fileName);
    
    float getVolume();
    void setVolume(float volume);
};

#endif
