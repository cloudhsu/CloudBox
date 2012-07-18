//
//  CBAndroidAudioManager.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/7/11.
//  Copyright 2012 Orz. All rights reserved.
//

#include "CBAndroidAudioManager.h"
#include "CBLibrary.h"

CBAndroidAudioManager::CBAndroidAudioManager()
:CBAudioBase()
{
	initial("com/clouddevelop/cloudbox/CBAudioManager");
	m_loadMusic = g_env->GetMethodID(m_mainClass, "loadMusic", "(Ljava/lang/String;)V");
	m_releaseMusic = g_env->GetMethodID(m_mainClass, "releaseMusic", "()V");
	m_playMusic = g_env->GetMethodID(m_mainClass, "playMusic", "()V");
	m_stopMusic = g_env->GetMethodID(m_mainClass, "stopMusic", "()V");
	m_pauseMusic = g_env->GetMethodID(m_mainClass, "pauseMusic", "()V");
	m_resumeMusic = g_env->GetMethodID(m_mainClass, "resumeMusic", "()V");
	m_getVolume = g_env->GetMethodID(m_mainClass, "getVolume", "()F");
	m_setVolume = g_env->GetMethodID(m_mainClass, "setVolume", "(F)V");
}

CBAndroidAudioManager::~CBAndroidAudioManager()
{
    releaseMusic();
}

void CBAndroidAudioManager::loadMusic(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallObjectMethod(m_mainObject, m_loadMusic, data);
	g_env->DeleteLocalRef(data);
}
void CBAndroidAudioManager::releaseMusic()
{
	g_env->CallVoidMethod(m_mainObject, m_releaseMusic);
}
void CBAndroidAudioManager::playMusic()
{
	g_env->CallVoidMethod(m_mainObject, m_playMusic);
}
void CBAndroidAudioManager::stopMusic()
{
	g_env->CallVoidMethod(m_mainObject, m_stopMusic);
}
void CBAndroidAudioManager::pauseMusic()
{
	g_env->CallVoidMethod(m_mainObject, m_pauseMusic);
}
void CBAndroidAudioManager::resumeMusic()
{
	g_env->CallVoidMethod(m_mainObject, m_resumeMusic);
}

float CBAndroidAudioManager::getVolume()
{
	float volume = g_env->CallIntMethod(m_mainObject, m_getVolume);
    return volume;
}
void CBAndroidAudioManager::setVolume(float volume)
{
	g_env->CallObjectMethod(m_mainObject, m_setVolume, volume);
}
