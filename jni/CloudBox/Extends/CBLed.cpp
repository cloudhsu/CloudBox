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
#include "CBFactoryMethod.h"

CBLed::CBLed()
{
	m_isOn = false;
    m_led = CBFactoryMethod::createLed();
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
