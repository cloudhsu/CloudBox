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

#define RATE_TAG "RateMe"

class CBUtility : public CBSingleton<CBUtility>
{
private:
	CBUtilityBase* m_utility;
    string m_appleID;
public:
	CBUtility();
	~CBUtility();

	string getLanguage();
    DeviceType getDeviceType();
    
    void onRateAlertClick(DialogResult result, int clickIndex);
    void openUrl(const string& url);
    void openApp(const string& appleID);
    void rateApp(const string& appleID);
    
    void rankMyGame(const string& appleID);
    
    // corss platform rand
    int rand();
    
    bool checkFileExist(string fileName);
    string getDocumentPath(const string& fileName);
    string getResourcePath(const string& fileName);
};

#define SUtility CBUtility::instance()

#endif