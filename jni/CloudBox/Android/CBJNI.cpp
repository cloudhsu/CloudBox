/*
 *  CBJNI.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "def.h"
#include "CBJNI.h"
#include "../CBLibrary.h"

CBJNI::CBJNI()
{
}
CBJNI::~CBJNI()
{
//	(*g_env)->DeleteLocalRef(g_env, m_turnOff);
//	(*g_env)->DeleteLocalRef(g_env, m_turnOn);
//	(*g_env)->DeleteLocalRef(g_env, m_lesClass);
//	(*g_env)->DeleteLocalRef(g_env, m_led);
}

jobject CBJNI::getInstance(JNIEnv* env, jclass obj_class)
{
    jmethodID construction_id = env->GetMethodID(obj_class, "<init>", "()V");
    jobject obj = env->NewObject(obj_class, construction_id);
    return obj;
}

void CBJNI::initialJNIClass(const string& className)
{
	DebugLog("CBJNI::initial 1");
	if(g_env == NULL)
	{
		DebugLog("CBJNI::initial error");
		return;
	}
	jclass order_class = g_env->FindClass(className.c_str());
	DebugLog("CBJNI::initial 2");
	m_mainObject = getInstance(g_env, order_class);
	DebugLog("CBJNI::initial 3");
	m_mainClass = g_env->GetObjectClass(m_mainObject);
	DebugLog("CBJNI::initial 4");
}
