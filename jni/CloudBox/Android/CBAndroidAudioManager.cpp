//
//  CBAndroidAudioManager.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/7/11.
//  Copyright 2012 Orz. All rights reserved.
//

#include "CBAndroidAudioManager.h"
#include "../CBLibrary.h"
#include "def.h"

CBAndroidAudioManager::CBAndroidAudioManager()
:CBAudioBase()
{
	initialJNIClass("com/clouddevelop/cloudbox/CBUtility");
	m_loadMusic = g_env->GetStaticMethodID(m_mainClass, "loadMusic", "(Ljava/lang/String;)V");
	m_releaseMusic = g_env->GetStaticMethodID(m_mainClass, "releaseMusic", "()V");
	m_playMusic = g_env->GetStaticMethodID(m_mainClass, "playMusic", "()V");
	m_stopMusic = g_env->GetStaticMethodID(m_mainClass, "stopMusic", "()V");
	m_pauseMusic = g_env->GetStaticMethodID(m_mainClass, "pauseMusic", "()V");
	m_resumeMusic = g_env->GetStaticMethodID(m_mainClass, "resumeMusic", "()V");
	m_getVolume = g_env->GetStaticMethodID(m_mainClass, "getMusicVolume", "()F");
	m_setVolume = g_env->GetStaticMethodID(m_mainClass, "setMusicVolume", "(F)V");
}

CBAndroidAudioManager::~CBAndroidAudioManager()
{
    releaseMusic();
}

void CBAndroidAudioManager::loadMusic(const string fileName)
{
	DebugLog("load %s",fileName.c_str());
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallStaticVoidMethod(m_mainClass, m_loadMusic, data);
	g_env->DeleteLocalRef(data);
	DebugLog("CBAndroidAudioManager load music succeed.\n");
}
void CBAndroidAudioManager::releaseMusic()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_releaseMusic);
	DebugLog("CBAndroidAudioManager release music succeed.\n");
}
void CBAndroidAudioManager::playMusic()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_playMusic);
	DebugLog("CBAndroidAudioManager play music succeed.\n");
}
void CBAndroidAudioManager::stopMusic()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_stopMusic);
	DebugLog("CBAndroidAudioManager stop music succeed.\n");
}
void CBAndroidAudioManager::pauseMusic()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_pauseMusic);
	DebugLog("CBAndroidAudioManager pause music succeed.\n");
}
void CBAndroidAudioManager::resumeMusic()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_resumeMusic);
	DebugLog("CBAndroidAudioManager resume music succeed.\n");
}

float CBAndroidAudioManager::getVolume()
{
	float volume = g_env->CallStaticFloatMethod(m_mainClass, m_getVolume);
    return volume;
}
void CBAndroidAudioManager::setVolume(float volume)
{
	g_env->CallStaticVoidMethod(m_mainClass, m_setVolume, volume);
}
