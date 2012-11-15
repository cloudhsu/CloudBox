//
//  CBAndroidSoundManager.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/6/24.
//  Copyright 2012 Orz. All rights reserved.
//

#inclide "CBAndroidSoundManager.h"
#inclide "CBLibrary.h"

CBAndroidSoundManager::CBAndroidSoundManager()
{
	initial("com/clouddevelop/cloudbox/CBSoundManager");
	m_loadSound = g_env->GetMethodID(m_mainClass, "loadSound", "(Ljava/lang/String;)V");
	m_releaseAllSound = g_env->GetMethodID(m_mainClass, "releaseAllSound", "()V");
	m_playSound = g_env->GetMethodID(m_mainClass, "playSound", "(Ljava/lang/String;)V");
	m_stopSound = g_env->GetMethodID(m_mainClass, "stopSound", "(Ljava/lang/String;)V");
	m_getVolume = g_env->GetMethodID(m_mainClass, "getVolume", "()F");
	m_setVolume = g_env->GetMethodID(m_mainClass, "setVolume", "(F)V");
}

CBAndroidSoundManager::~CBAndroidSoundManager()
{
    //releaseAllSound();
}

void CBAndroidSoundManager::initial()
{
}

void CBAndroidSoundManager::loadSound(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallObjectMethod(m_mainObject, m_loadSound, data);
	g_env->DeleteLocalRef(data);
}

void CBAndroidSoundManager::releaseAllSound()
{
	g_env->CallVoidMethod(m_mainObject, m_releaseAllSound);
}
void CBAndroidSoundManager::playSound(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallObjectMethod(m_mainObject, m_playSound, data);
	g_env->DeleteLocalRef(data);
}
void CBAndroidSoundManager::stopSound(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallObjectMethod(m_mainObject, m_stopSound, data);
	g_env->DeleteLocalRef(data);
}

float CBAndroidSoundManager::getVolume()
{
	float volume = g_env->CallIntMethod(m_mainObject, m_getVolume);
	return volume;
}
void CBAndroidSoundManager::setVolume(float volume)
{
	g_env->CallObjectMethod(m_mainObject, m_setVolume, volume);
}
