//
//  CBAndroidAudioManager.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/7/11.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBANDROIDAUDIOMANAGER_H_
#define _CBANDROIDAUDIOMANAGER_H_

#include "../CBAudioBase.h"
#include "CBJNI.h"

class CBAndroidAudioManager : public CBAudioBase, public CBJNI
{
private:
	jmethodID m_loadMusic;
	jmethodID m_releaseMusic;
	jmethodID m_playMusic;
	jmethodID m_stopMusic;
	jmethodID m_pauseMusic;
	jmethodID m_resumeMusic;
	jmethodID m_getVolume;
	jmethodID m_setVolume;
public:
	CBAndroidAudioManager();
    ~CBAndroidAudioManager();
    void loadMusic(const string fileName);
    void releaseMusic();
    void playMusic();
    void stopMusic();
    void pauseMusic();
    void resumeMusic();
    
    float getVolume();
    void setVolume(float volume);
};

#endif
