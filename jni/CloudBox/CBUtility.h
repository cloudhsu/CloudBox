/*
 *  CBUtility.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/6/16.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBUTILITY_H_
#define _CBUTILITY_H_

#include "CBUtilityBase.h"
#include "CBSingleton.h"
#include "CBDialog.h"
#include <string>
using namespace std;

class CBUtility : public CBSingleton<CBUtility>
{
private:
	CBUtilityBase* m_utility;
public:
	CBUtility();
	~CBUtility();
	string getFilePath();
	string getLanguage();
    
    DeviceType getDeviceType();
    
    static int rand();
};

#define SUtility CBUtility::instance()

#endif