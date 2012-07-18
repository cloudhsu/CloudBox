/*
 *  CBLedBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBLEDBASE_h_
#define _CBLEDBASE_h_

class CBLedBase
{
public:
	virtual void turnOnLed() = 0;
	virtual void turnOffLed() = 0;
};

#endif