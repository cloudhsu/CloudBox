/*
 *  CBUtilityBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/6/16.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBUTILITYBASE_H_
#define _CBUTILITYBASE_H_

#include <string>
using namespace std;

enum DeviceType
{
    iPhone = 0,
    iPad = 1,
    AndroidPhone = 2,
    AndroidPad = 3,
    WP8 = 4,
    Other = 5
};

class CBUtilityBase
{
private:
public:
    CBUtilityBase(){}
    virtual ~CBUtilityBase() {}
	virtual string getFilePath() = 0;
	virtual string getLanguage() = 0;
    virtual DeviceType getDeviceType() = 0;
};

class CBNoneUtility : public CBUtilityBase
{
private:
public:
	string getFilePath() { return ""; }
	string getLanguage() { return ""; }
    DeviceType getDeviceType() { return Other; }
};

#endif