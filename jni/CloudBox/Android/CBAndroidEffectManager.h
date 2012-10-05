//
//  CBAndroidEffectManager.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/7/11.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBANDROIDEFFECTMANAGER_H_
#define _CBANDROIDEFFECTMANAGER_H_

#include "../CBEffectBase.h"
#include "CBJNI.h"

class CBAndroidEffectManager : public CBEffectBase, public CBJNI
{
private:
	jmethodID m_loadEffect;
	jmethodID m_initialEffect;
	jmethodID m_releaseAllEffect;
	jmethodID m_playEffect;
	jmethodID m_stopEffect;
	jmethodID m_getVolume;
	jmethodID m_setVolume;
public:
    CBAndroidEffectManager();
    ~CBAndroidEffectManager();
    
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
