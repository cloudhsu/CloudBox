/*
 *  CBSoundBox.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBSoundBox.h"
#include "SoundEngine.h"
#include "Wrapper.h"

CBSoundBox::CBSoundBox()
{
	initSoundSystem();
}


CBSoundBox::~CBSoundBox()
{
	destroySoundSystem();
}

void CBSoundBox::initSoundSystem()
{
	m_SoundVolume = 50;
	m_MusicVolume = 50;
	
	#define kListenerDistance			1.0

	SoundEngine_Initialize(44100);
	SoundEngine_SetListenerPosition(0.0, 0.0, kListenerDistance);

	m_SoundEffects.reserve(10);

}


void CBSoundBox::destroySoundSystem()
{
	for (int i=0; i<m_SoundEffects.size(); i++)
	{
		unloadSound(i);
	}
	
	m_SoundEffects.clear();

	unloadMusic();

}


void CBSoundBox::loadMusic(const char *fileName, const char *folder)
{
	const char *path = GetPath(fileName, folder);
	//const char *path = fileName;
	SoundEngine_LoadBackgroundMusicTrack(path, true, true);
}


void CBSoundBox::unloadMusic()
{
	SoundEngine_UnloadBackgroundMusicTrack();
}

void CBSoundBox::playMusic(bool looping)
{	
	setMusicVolume(m_MusicVolume);

	SoundEngine_StartBackgroundMusic();

	if (!looping)
		SoundEngine_StopBackgroundMusic(true);		// stop when the music is played once ;)

}


void CBSoundBox::stopMusic()
{
	SoundEngine_StopBackgroundMusic(false);

}


void CBSoundBox::setSoundVolume(int volume)
{
	m_SoundVolume = volume;

	float vol = (float)m_SoundVolume / 100.0f;
	SoundEngine_SetEffectsVolume(vol);
}


void CBSoundBox::setMusicVolume(int volume)
{
	m_MusicVolume = volume;

	float vol = (float)m_MusicVolume / 100.0f;
	SoundEngine_SetBackgroundMusicVolume(vol);
}


int CBSoundBox::loadSound(const char *filename, const char *folder)
{
	UInt32 _id;
	
	const char *path = GetPath(filename, folder);
	//const char *path = filename;
	SoundEngine_LoadEffect(path, &_id);

	for (int i=0;i<m_SoundEffects.size();i++)
	{
		if (!m_SoundEffects[i].mActive)
		{
			m_SoundEffects[i].mActive = true;
			m_SoundEffects[i].mSoundId = _id;
			return i;
		}
	}
	
	CBSoundEffect effect;
	effect.mActive = true;
	effect.mSoundId = _id;
	
	int index = m_SoundEffects.size();
	
	m_SoundEffects.push_back(effect);
	
	return index;
}


void CBSoundBox::unloadSound(int handle)
{
	if (handle < 0 || handle > m_SoundEffects.size()-1)
		return;

	if (m_SoundEffects[handle].mActive)
	{
		SoundEngine_UnloadEffect(m_SoundEffects[handle].mSoundId);
		m_SoundEffects[handle].mActive = false;
	}
}


void CBSoundBox::playSound(int handle)
{
	if (handle < 0 || handle > m_SoundEffects.size()-1)
		return;
	setSoundVolume(m_SoundVolume);
	SoundEngine_StartEffect(m_SoundEffects[handle].mSoundId);
}


void CBSoundBox::stopAllSound()
{
	for (int i=0;i<m_SoundEffects.size();i++)
	{
		if (m_SoundEffects[i].mActive)
			SoundEngine_StopEffect(m_SoundEffects[i].mSoundId, false);
	}
}
