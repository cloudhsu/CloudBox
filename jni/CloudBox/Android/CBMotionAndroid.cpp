/*
 *  CBMotionAndroid.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/6/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBMotionAndroid.h"
#include "def.h"
#include "../CBLibrary.h"

CBMotionAndroid::CBMotionAndroid()
{
	DebugLog("CBMotionAndroid::CBMotionAndroid()\n");
	initial("com/clouddevelop/cloudbox/CBMotion");
	m_start = g_env->GetMethodID(m_mainClass, "startAccelerometer", "()V");
	m_stop = g_env->GetMethodID(m_mainClass, "stopAccelerometer", "()V");
//	(*g_env)->DeleteLocalRef(g_env, order_class);
}
CBMotionAndroid::~CBMotionAndroid()
{
//	(*g_env)->DeleteLocalRef(g_env, m_turnOff);
//	(*g_env)->DeleteLocalRef(g_env, m_turnOn);
//	(*g_env)->DeleteLocalRef(g_env, m_mainClass);
//	(*g_env)->DeleteLocalRef(g_env, m_mainObject);
}

void CBMotionAndroid::startAccelerometer()
{
	DebugLog("CBMotionAndroid::startAccelerometer()\n");
	g_env->CallVoidMethod(m_mainObject, m_start);
}
void CBMotionAndroid::updateAccelerometer()
{

}
void CBMotionAndroid::stopAccelerometer()
{
	DebugLog("CBMotionAndroid::stopAccelerometer()\n");
	g_env->CallVoidMethod(m_mainObject, m_stop);
}
