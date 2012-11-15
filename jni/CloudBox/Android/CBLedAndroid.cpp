/*
 *  CBLedAndroid.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLedAndroid.h"
#include "def.h"
#include "../CBLibrary.h"

CBLedAndroid::CBLedAndroid()
{
	initialJNIClass("com/clouddevelop/cloudbox/CloudLed");
	m_turnOn = g_env->GetMethodID(m_mainClass, "turnOn", "()V");
	m_turnOff = g_env->GetMethodID(m_mainClass, "turnOff", "()V");
//	(*g_env)->DeleteLocalRef(g_env, order_class);
}
CBLedAndroid::~CBLedAndroid()
{
//	(*g_env)->DeleteLocalRef(g_env, m_turnOff);
//	(*g_env)->DeleteLocalRef(g_env, m_turnOn);
//	(*g_env)->DeleteLocalRef(g_env, m_mainClass);
//	(*g_env)->DeleteLocalRef(g_env, m_mainObject);
}

void CBLedAndroid::turnOnLed()
{
	g_env->CallVoidMethod(m_mainObject, m_turnOn);
//	jmethodID mid;
//	DebugLog("led 1");
//	jclass cls = g_env->GetObjectClass(m_mainObject);
//	if(cls == NULL)
//	{
//		DebugLog("cls is null");
//	}
//	DebugLog("led 2");
//	mid = g_env->GetMethodID(cls, "turnOn", "()V");
//	if(mid == NULL)
//	{
//		DebugLog("mid is null");
//	}
//	DebugLog("led 3");
//	g_env->CallVoidMethod(m_mainObject, mid);
//	DebugLog("led 4");
}
void CBLedAndroid::turnOffLed()
{
	g_env->CallVoidMethod(m_mainObject, m_turnOff);
//	jmethodID mid;
//	jclass cls = g_env->GetObjectClass(m_mainObject);
//	if(cls == NULL)
//	{
//		DebugLog("cls is null");
//	}
//	mid = g_env->GetMethodID(cls, "turnOff", "()V");
//	if(mid == NULL)
//	{
//		DebugLog("mid is null");
//	}
//	g_env->CallVoidMethod(m_mainObject, mid);
}
