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

#include "CBConfig.h"

class CBLedBase
{
public:
    CBLedBase() {}
    virtual ~CBLedBase() {}
	virtual void turnOnLed() = 0;
	virtual void turnOffLed() = 0;
};

class CBLedSimulator : public CBLedBase
{
public:
	CBLedSimulator() {}
	~CBLedSimulator() {}
	void turnOnLed() {}
	void turnOffLed() {}
};

#endif
