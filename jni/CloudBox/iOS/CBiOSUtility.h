//
//  CBiOSUtility.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/10/17.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBIOSUTILITY_H_
#define _CBIOSUTILITY_H_

#include "CBUtilityBase.h"
#include <string>
using namespace std;

class CBiOSUtility : public CBUtilityBase
{
public:
    CBiOSUtility();
    ~CBiOSUtility();
    
    static string getSystemPath(const string& fileName);
	string getLanguage();
    DeviceType getDeviceType();
    void openUrl(const string& url);
};

#endif