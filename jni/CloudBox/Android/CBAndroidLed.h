/*
 *  CBAndroidLed.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBLEDANDROID_H_
#define _CBLEDANDROID_H_

#include <jni.h>
#include "../Extends/CBLedBase.h"
#include "CBJNI.h"

class CBAndroidLed : public CBLedBase, public CBJNI
{
private:
	jmethodID m_turnOn;
	jmethodID m_turnOff;
public:
	CBAndroidLed();
	~CBAndroidLed();
	void turnOnLed();
	void turnOffLed();
};

#endif
