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
	g_env->CallStaticVoidMethod(m_mainClass, m_initialEffect);
	DebugLog("CBAndroidEffectManager::initialEffect succeed!");
}

void CBAndroidEffectManager::loadEffect(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallStaticVoidMethod(m_mainClass, m_loadEffect, data);
	g_env->DeleteLocalRef(data);
	DebugLog("CBAndroidEffectManager::loadEffect succeed!");
}

void CBAndroidEffectManager::releaseAllEffect()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_releaseAllEffect);
	DebugLog("CBAndroidEffectManager::releaseAllEffect succeed!");
}
void CBAndroidEffectManager::playEffect(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallStaticVoidMethod(m_mainClass, m_playEffect, data);
	g_env->DeleteLocalRef(data);
	DebugLog("CBAndroidEffectManager::playEffect succeed!");
}
void CBAndroidEffectManager::stopEffect(const string fileName)
{
	jstring data = g_env->NewStringUTF(fileName.c_str());
	g_env->CallStaticVoidMethod(m_mainClass, m_stopEffect, data);
	g_env->DeleteLocalRef(data);
	DebugLog("CBAndroidEffectManager::stopEffect succeed!");
}

float CBAndroidEffectManager::getVolume()
{
	float volume = g_env->CallStaticFloatMethod(m_mainClass, m_getVolume);
	return volume;
}
void CBAndroidEffectManager::setVolume(float volume)
{
	g_env->CallStaticVoidMethod(m_mainClass, m_setVolume, volume);
}
