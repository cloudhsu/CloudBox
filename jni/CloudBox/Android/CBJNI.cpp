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
	g_env->DeleteGlobalRef(m_mainObject);
	g_env->DeleteGlobalRef(m_mainClass);
}

jobject CBJNI::getInstance(JNIEnv* env, jclass obj_class)
{
    jmethodID construction_id = env->GetMethodID(obj_class, "<init>", "()V");
    jobject obj = env->NewObject(obj_class, construction_id);
    return obj;
}

void CBJNI::initialJNIClass(const string& className)
{
	//DebugLog("CBJNI::initial 1");
	if(g_env == NULL)
	{
		DebugLog("CBJNI::initial error %s",className.c_str());
		return;
	}
	m_className = string(className);
	jclass localClass = g_env->FindClass(className.c_str());
	jobject obj = getInstance(g_env, localClass);
	m_mainObject = g_env->NewGlobalRef(obj);
	jclass mainClass = g_env->GetObjectClass(m_mainObject);
	m_mainClass = reinterpret_cast<jclass>(g_env->NewGlobalRef(mainClass));
}
