//
//  CBAndroidSoundManager.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/7/11.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBANDROIDSOUNDMANAGER_H_
#define _CBANDROIDSOUNDMANAGER_H_

#include "CBSoundBase.h"
#include "CBJNI.h"

class CBAndroidSoundManager : public CBSoundBase, public CBJNI
{
private:
	jmethodID m_loadSound;
	jmethodID m_releaseAllSound;
	jmethodID m_playSound;
	jmethodID m_stopSound;
	jmethodID m_getVolume;
	jmethodID m_setVolume;
public:
    CBAndroidSoundManager();
    ~CBAndroidSoundManager();
    
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
