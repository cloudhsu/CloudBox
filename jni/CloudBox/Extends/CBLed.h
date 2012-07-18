/*
 *  CBLed.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBLED_h_
#define _CBLED_h_

class CBLedBase;

class CBLed
{
private:
	bool m_isOn;
	CBLedBase* m_led;
public:
	CBLed();
	~CBLed();
	
	bool getOn() { return m_isOn;}
	
	void switchLed();
	
	void turnOnLed();
	void turnOffLed();
};

#endif