/*
 *  CBAndroidLed.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAndroidLed.h"
#include "def.h"
#include "../CBLibrary.h"

CBAndroidLed::CBAndroidLed()
{
	initialJNIClass("com/clouddevelop/cloudbox/CloudLed");
	m_turnOn = g_env->GetMethodID(m_mainClass, "turnOn", "()V");
	m_turnOff = g_env->GetMethodID(m_mainClass, "turnOff", "()V");
}
CBAndroidLed::~CBAndroidLed()
{
}

void CBAndroidLed::turnOnLed()
{
	g_env->CallVoidMethod(m_mainObject, m_turnOn);
}
void CBAndroidLed::turnOffLed()
{
	g_env->CallVoidMethod(m_mainObject, m_turnOff);
}
