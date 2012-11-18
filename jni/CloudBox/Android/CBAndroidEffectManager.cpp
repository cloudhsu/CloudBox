//
//  CBAndroidEffectManager.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/6/24.
//  Copyright 2012 Orz. All rights reserved.
//

#include "CBAndroidEffectManager.h"
#include "../CBLibrary.h"
#include "def.h"

CBAndroidEffectManager::CBAndroidEffectManager()
{
//	initialJNIClass("com/clouddevelop/cloudbox/CBEffectManager");
//	m_loadEffect = g_env->GetMethodID(m_mainClass, "loadEffect", "(Ljava/lang/String;)V");
//	m_initialEffect = g_env->GetMethodID(m_mainClass, "initialEffect", "()V");
//	m_releaseAllEffect = g_env->GetMethodID(m_mainClass, "releaseAllEffect", "()V");
//	m_playEffect = g_env->GetMethodID(m_mainClass, "playEffect", "(Ljava/lang/String;)V");
//	m_stopEffect = g_env->GetMethodID(m_mainClass, "stopEffect", "(Ljava/lang/String;)V");
//	m_getVolume = g_env->GetMethodID(m_mainClass, "getVolume", "()F");
//	m_setVolume = g_env->GetMethodID(m_mainClass, "setVolume", "(F)V");
	initialJNIClass("com/clouddevelop/cloudbox/CBUtility");
	m_loadEffect = g_env->GetStaticMethodID(m_mainClass, "loadEffect", "(Ljava/lang/String;)V");
	m_initialEffect = g_env->GetStaticMethodID(m_mainClass, "initialEffect", "()V");
	m_releaseAllEffect = g_env->GetStaticMethodID(m_mainClass, "releaseAllEffect", "()V");
	m_playEffect = g_env->GetStaticMethodID(m_mainClass, "playEffect", "(Ljava/lang/String;)V");
	m_stopEffect = g_env->GetStaticMethodID(m_mainClass, "stopEffect", "(Ljava/lang/String;)V");
	m_getVolume = g_env->GetStaticMethodID(m_mainClass, "getEffectVolume", "()F");
	m_setVolume = g_env->GetStaticMethodID(m_mainClass, "setEffectVolume", "(F)V");
}

CBAndroidEffectManager::~CBAndroidEffectManager()
{
    releaseAllEffect();
}

void CBAndroidEffectManager::initialEffect()
{
	g_env->CallVoidMethod(m_mainObject, m_initialEffect);
}

void CBAndroidEffectManager::loadEffect(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallObjectMethod(m_mainObject, m_loadEffect, data);
	g_env->DeleteLocalRef(data);
}

void CBAndroidEffectManager::releaseAllEffect()
{
	g_env->CallVoidMethod(m_mainObject, m_releaseAllEffect);
}
void CBAndroidEffectManager::playEffect(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallObjectMethod(m_mainObject, m_playEffect, data);
	g_env->DeleteLocalRef(data);
}
void CBAndroidEffectManager::stopEffect(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallObjectMethod(m_mainObject, m_stopEffect, data);
	g_env->DeleteLocalRef(data);
}

float CBAndroidEffectManager::getVolume()
{
	float volume = g_env->CallFloatMethod(m_mainObject, m_getVolume);
	return volume;
}
void CBAndroidEffectManager::setVolume(float volume)
{
	g_env->CallObjectMethod(m_mainObject, m_setVolume, volume);
}
