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
}
CBLedAndroid::~CBLedAndroid()
{
}

void CBLedAndroid::turnOnLed()
{
	g_env->CallVoidMethod(m_mainObject, m_turnOn);
}
void CBLedAndroid::turnOffLed()
{
	g_env->CallVoidMethod(m_mainObject, m_turnOff);
}
