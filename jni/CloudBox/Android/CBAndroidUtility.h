//
//  CBAndroidUtility.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/11/11.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBANDROIDUTILITY_H_
#define _CBANDROIDUTILITY_H_

#include "CBUtilityBase.h"
#include <string>
using namespace std;

class CBAndroidUtility : public CBUtilityBase
{
public:
	CBAndroidUtility();
    ~CBAndroidUtility();
    
    static string getSystemPath(const string& fileName);
	string getLanguage();
    DeviceType getDeviceType();
    void openUrl(const string& url);
};

#endif