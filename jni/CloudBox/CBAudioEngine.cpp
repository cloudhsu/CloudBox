/*
 *  CBAudioEngine.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAudioEngine.h"
#include "CBSoundBase.h"
#include "CBAudioBase.h"
#ifdef __CBIOS__
#include "CBiOSAudioManager.h"
#include "CBiOSSoundManager.h"
#else
#endif

CBAudioEngine::CBAudioEngine()
{
#ifdef __CBIOS__
    m_audioManager = new CBiOSAudioManager();
    m_soundManager = new CBiOSSoundManager();
#else
    m_audioManager = new CBNoneAudio();
    m_soundManager = new CBNoneSound();
#endif
}

CBAudioEngine::~CBAudioEngine()
{
    releaseEngine();
	delete m_audioManager;
    delete m_soundManager;
}

void CBAudioEngine::initialEngine()
{
    m_soundManager->initial();
}

void CBAudioEngine::releaseEngine()
{
    releaseMusic();
    releaseAllSounds();
}

void CBAudioEngine::loadMusic(const string fileName)
{
    m_audioManager->loadMusic(fileName);
}
void CBAudioEngine::releaseMusic()
{
    m_audioManager->stopMusic();
    m_audioManager->releaseMusic();
}
void CBAudioEngine::CBAudioEngine::playMusic()
{
    m_audioManager->playMusic();
}
void CBAudioEngine::stopMusic()
{
    m_audioManager->stopMusic();
}
void CBAudioEngine::pauseMusic()
{
    m_audioManager->pauseMusic();
}
void CBAudioEngine::resumeMusic()
{
    m_audioManager->resumeMusic();
}

// for sound
void CBAudioEngine::loadSound(const string fileName)
{
    m_soundManager->loadSound(fileName);
}
//void CBAudioEngine::releaseSound(const string fileName)
//{
//    m_soundManager->releaseSound(fileName);
//}
void CBAudioEngine::releaseAllSounds()
{
    m_soundManager->releaseAllSound();
}
void CBAudioEngine::playSound(const string fileName)
{
    m_soundManager->playSound(fileName);
}
void CBAudioEngine::stopSound(const string fileName)
{
    m_soundManager->stopSound(fileName);
}

float CBAudioEngine::getSoundVolume()
{
    return m_soundManager->getVolume();
}
void CBAudioEngine::setSoundVolume(float volume)
{
    m_soundManager->setVolume(volume);
}
float CBAudioEngine::getMusicVolume()
{
    return m_audioManager->getVolume();
}
void CBAudioEngine::setMusicVolume(float volume)
{
    m_audioManager->setVolume(volume);
}

void CBAudioEngine::setVolume(float volume)
{
    setMusicVolume(volume);
    setSoundVolume(volume);
}