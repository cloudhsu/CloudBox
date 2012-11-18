/*
 *  CBAudioEngine.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/9/9.
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
class CBEffectBase;

class CBAudioEngine : public CBSingleton<CBAudioEngine>
{
private:
    CBAudioBase* m_audioManager;
    CBEffectBase* m_effectManager;
    bool m_isMute;
    bool m_isLoadMusic;
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

	// for Effect
	void loadEffect(const string fileName);
	//void releaseEffect(const string fileName);
	void playEffect(const string fileName);
	void stopEffect(const string fileName);

    float getEffectVolume();
    void setEffectVolume(float volume);
    float getMusicVolume();
	void setMusicVolume(float volume);
    void setVolume(float volume);
    
    void releaseAllEffects();
    
    void releaseEngine();
    void initialEngine();
    
    void setMute(bool isMute);
    bool getMute();
	
protected:

//	void initEffectSystem();
//	void destroyEffectSystem();
};

#define SAudioEngine CBAudioEngine::instance()

#endif
