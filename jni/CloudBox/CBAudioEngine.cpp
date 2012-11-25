/*
 *  CBAudioEngine.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/9/9.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAudioEngine.h"
#include "CBEffectBase.h"
#include "CBAudioBase.h"
#include "CBFactoryMethod.h"

CBAudioEngine::CBAudioEngine():m_isMute(false),m_isLoadMusic(false)
{
    m_audioManager = CBFactoryMethod::createAudio();
    m_effectManager = CBFactoryMethod::createEffect();
}

CBAudioEngine::~CBAudioEngine()
{
    releaseEngine();
	delete m_audioManager;
    delete m_effectManager;
}

void CBAudioEngine::initialEngine()
{
    m_effectManager->initialEffect();
}

void CBAudioEngine::releaseEngine()
{
    releaseMusic();
    releaseAllEffects();
}

void CBAudioEngine::loadMusic(const string fileName)
{
    m_audioManager->loadMusic(fileName);
    m_isLoadMusic = true;
}
void CBAudioEngine::releaseMusic()
{
	if(m_isMute)
	    return;
    m_audioManager->stopMusic();
    m_audioManager->releaseMusic();
    m_isLoadMusic = false;
}
void CBAudioEngine::playMusic()
{
    if(m_isMute)
        return;
    if(m_isLoadMusic)
    	m_audioManager->playMusic();
}
void CBAudioEngine::stopMusic()
{
	if(m_isMute)
	    return;
    m_audioManager->stopMusic();
}
void CBAudioEngine::pauseMusic()
{
	if(m_isLoadMusic)
		m_audioManager->pauseMusic();
}
void CBAudioEngine::resumeMusic()
{
	if(m_isLoadMusic)
		m_audioManager->resumeMusic();
}

// for Effect
void CBAudioEngine::loadEffect(const string fileName)
{
    m_effectManager->loadEffect(fileName);
}

//void CBAudioEngine::releaseEffect(const string fileName)
//{
//    m_effectManager->releaseEffect(fileName);
//}

void CBAudioEngine::releaseAllEffects()
{
    m_effectManager->releaseAllEffect();
}
void CBAudioEngine::playEffect(const string fileName)
{
    if(m_isMute)
        return;
    m_effectManager->playEffect(fileName);
}
void CBAudioEngine::stopEffect(const string fileName)
{
	if(m_isMute)
	    return;
    m_effectManager->stopEffect(fileName);
}

float CBAudioEngine::getEffectVolume()
{
    return m_effectManager->getVolume();
}
void CBAudioEngine::setEffectVolume(float volume)
{
    m_effectManager->setVolume(volume);
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
    setEffectVolume(volume);
}

bool CBAudioEngine::getMute()
{
    return m_isMute;
}

void CBAudioEngine::setMute(bool isMute)
{
    m_isMute = isMute;
    if(m_isMute)
    {
        pauseMusic();
    }
    else
    {
        playMusic();
    }
}
