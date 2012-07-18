/*
 *  CBLediOS.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBLEDIOS_H_
#define _CBLEDIOS_H_

#include "CBLedBase.h"

class CBLediOS : public CBLedBase
{
public:
	CBLediOS();
	~CBLediOS();
	void turnOnLed();
	void turnOffLed();
};

#endif