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
	initialJNIClass("com/clouddevelop/cloudbox/CBUtility");
	m_start = g_env->GetStaticMethodID(m_mainClass, "startAccelerometer", "()V");
	m_stop = g_env->GetStaticMethodID(m_mainClass, "stopAccelerometer", "()V");
}
CBMotionAndroid::~CBMotionAndroid()
{
}

void CBMotionAndroid::startAccelerometer()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_start);
	DebugLog("CBMotionAndroid::startAccelerometer() succeed.\n");
}
void CBMotionAndroid::updateAccelerometer()
{

}
void CBMotionAndroid::stopAccelerometer()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_stop);
	DebugLog("CBMotionAndroid::stopAccelerometer() succeed.\n");
}
