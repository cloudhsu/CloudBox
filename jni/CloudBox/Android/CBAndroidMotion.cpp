/*
 *  CBAndroidMotion.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/6/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAndroidMotion.h"
#include "def.h"
#include "../CBLibrary.h"

CBAndroidMotion::CBAndroidMotion()
{
	DebugLog("CBMotionAndroid::CBMotionAndroid()\n");
	initialJNIClass("com/clouddevelop/cloudbox/CBUtility");
	m_start = g_env->GetStaticMethodID(m_mainClass, "startAccelerometer", "()V");
	m_stop = g_env->GetStaticMethodID(m_mainClass, "stopAccelerometer", "()V");
}
CBAndroidMotion::~CBAndroidMotion()
{
}

void CBAndroidMotion::startAccelerometer()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_start);
	DebugLog("CBMotionAndroid::startAccelerometer() succeed.\n");
}
void CBAndroidMotion::updateAccelerometer()
{

}
void CBAndroidMotion::stopAccelerometer()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_stop);
	DebugLog("CBMotionAndroid::stopAccelerometer() succeed.\n");
}
