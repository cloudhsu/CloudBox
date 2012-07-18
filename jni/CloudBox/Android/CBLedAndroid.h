/*
 *  CBLedAndroid.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include <jni.h>
#include "../Extends/CBLedBase.h"
#include "CBJNI.h"

class CBLedAndroid : public CBLedBase, public CBJNI
{
private:
	jmethodID m_turnOn;
	jmethodID m_turnOff;
public:
	CBLedAndroid();
	~CBLedAndroid();
	void turnOnLed();
	void turnOffLed();
};
