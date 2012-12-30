/*
 *  CBLed.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLed.h"
#include "CBLedBase.h"
#ifdef __CBIOS__
#include "CBLediOS.h"
#elif __CBANDROID__
#include "../Android/CBLedAndroid.h"
#endif

CBLed::CBLed()
{
	m_isOn = false;
#ifdef __CBIOS__
	m_led = new CBLediOS();
#elif __CBANDROID__
	m_led = new CBLedAndroid();
#else
	m_led = new CBNoneLed();
#endif
}

CBLed::~CBLed()
{
	delete m_led;
}

void CBLed::switchLed()
{
	if(m_isOn)
	{
		turnOffLed();
	}
	else
	{
		turnOnLed();
	}
}

void CBLed::turnOnLed()
{
	if(!m_isOn)
	{
		m_led->turnOnLed();
		m_isOn = true;
	}
}
void CBLed::turnOffLed()
{
	if(m_isOn)
	{
		m_led->turnOffLed();
		m_isOn = false;
	}
}
