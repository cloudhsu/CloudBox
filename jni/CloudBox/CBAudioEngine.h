/*
 *  CBAudioEngine.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBAUDIOENGINE_H_
#define _CBAUDIOENGINE_H_

#ifdef WIN32
// for win32
#elif __CBIOS__
// for ios
#include "MacTypes.h"
#else
// for android
#endif

#include "CBLibrary.h"
#include "CBSingleton.h"
#include <vector>
#include <string>
using namespace std;

class CBAudioBase;
class CBSoundBase;

class CBAudioEngine : public CBSingleton<CBAudioEngine>
{
private:
    CBAudioBase* m_audioManager;
    CBSoundBase* m_soundManager;
public:
	CBAudioEngine();
	~CBAudioEngine();
	// music
	void loadMusic(const string fileName);
	void playMusic();
	void stopMusic();
    void pauseMusic();
	void resumeMusic();
    
    void releaseMusic();

	// for sound
	void loadSound(const string fileName);
	//void releaseSound(const string fileName);
	void playSound(const string fileName);
	void stopSound(const string fileName);

    float getSoundVolume();
    void setSoundVolume(float volume);
    float getMusicVolume();
	void setMusicVolume(float volume);
    void setVolume(float volume);
    
    void releaseAllSounds();
    
    void releaseEngine();
    void initialEngine();
	
protected:

//	void initSoundSystem();
//	void destroySoundSystem();
};

#define SAudioEngine CBAudioEngine::instance()

#endif
