/*
 *  CBLed.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLed.h"
#ifdef __CBIOS__
#include "CBLediOS.h"
#else
#include "../Android/CBLedAndroid.h"
#endif

CBLed::CBLed()
{
	m_isOn = false;
#ifdef __CBIOS__
	m_led = new CBLediOS();
#else
	m_led = new CBLedAndroid();
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
