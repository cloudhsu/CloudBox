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
    DeviceiPhone = 0,
    DeviceiPad = 1,
    DeviceAndroidPhone = 2,
    DeviceAndroidPad = 3,
    DeviceWP8 = 4,
    DeviceOther = 5
};

class CBUtilityBase
{
private:
public:
    CBUtilityBase(){}
    virtual ~CBUtilityBase() {}
	//virtual string getFilePath() = 0;
	virtual string getLanguage() = 0;
    virtual DeviceType getDeviceType() = 0;
    virtual void openUrl(const string& url) = 0;
    virtual string getSystemPath(const string& fileName) = 0;
};

class CBUtilitySimulator : public CBUtilityBase
{
private:
public:
    CBUtilitySimulator(){}
    ~CBUtilitySimulator(){}
	//string getFilePath() { return ""; }
	string getLanguage() { return "en"; }
    DeviceType getDeviceType() { return DeviceOther; }
    void openUrl(const string& url) {}
    string getSystemPath(const string& fileName) { return ""; }
};

#endif