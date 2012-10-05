/*
 *  CBSoundBox.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBSOUNDBOX_H_
#define _CBSOUNDBOX_H_

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
using namespace std;

class CBSoundBox : public CBSingleton<CBSoundBox>
{
private:
	struct CBSoundEffect
	{
		bool mActive;
		UInt32 mSoundId;
		
	};
	int m_SoundVolume;
	int m_MusicVolume;

	vector <CBSoundEffect> m_SoundEffects;
public:
	CBSoundBox();
	~CBSoundBox();
	// music
	void loadMusic(const char *fileName, const char *folder = NULL);
	void unloadMusic();
	void playMusic(bool looping = false);
	void stopMusic();
	void resumeMusic();

	// for sound
	int loadSound(const char *fileName, const char *folder = NULL);
	void unloadSound(int handle);
	void playSound(int handle);
	void stopAllSound();

	void setSoundVolume(int volume);
	void setMusicVolume(int volume);

	
protected:
	
	void initSoundSystem();
	void destroySoundSystem();
};

#define SSoundBox CBSoundBox::instance()

#endif
