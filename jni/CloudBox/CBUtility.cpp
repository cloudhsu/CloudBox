/*
 *  CBUtility.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/6/16.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBUtility.h"
#include "CBUtilityBase.h"
#include "CBDialog.h"
#include "CBSystemDialog.h"
#include "CBUserDefault.h"
#include "CBLibrary.h"
#include <math.h>
#include <fstream>
#include "CBFactoryMethod.h"
#include <stdlib.h>

CBUtility::CBUtility()
{
    m_utility = CBFactoryMethod::createUtility();
}
CBUtility::~CBUtility()
{
	delete m_utility;
}

string CBUtility::getLanguage()
{
	return m_utility->getLanguage();
}

DeviceType CBUtility::getDeviceType()
{
    return m_utility->getDeviceType();
}

void CBUtility::rankMyGame(const string& appleID)
{
    bool rated = SUserDefault.getValue<bool>(RATE_TAG, false);
    int rnd = this->rand() % 100;
    if(!rated && rnd > 80)
    {
        m_appleID = appleID;
        CBDialog* dialog = new CBSystemDialog();
        dialog->addAlertEvent(this, &CBUtility::onRateAlertClick);
        dialog->showDialog(DialogTypeRate,"", "Could you rate the app?");
    }
}

void CBUtility::onRateAlertClick(DialogResult result, int clickIndex)
{
    if(result == DialogResultRateNever || result == DialogResultRateMe)
    {
    	//DebugLog("set rate result.\n");
        SUserDefault.setValue(RATE_TAG, true);
        //DebugLog("save rate result.\n");
        SUserDefault.save();
    }
    if(result == DialogResultRateMe)
    {
        rateApp(m_appleID);
    }
}

void CBUtility::openUrl(const string& url)
{
    DebugLog("Open url: %s\n",url.c_str());
    m_utility->openUrl(url);
}
void CBUtility::openApp(const string& appleID)
{
#ifdef __CBIOS__
    // iOS rate url
    string url = "http://itunes.apple.com/WebObjects/MZStore.woa/wa/viewSoftware?id=";
    url += (appleID + "&mt=8");
#elif __CBANDROID__
    // Android rate url
    string url = "https://play.google.com/store/apps/details?id=";
#else
    string url = "";
#endif
    //DebugLog("Open App: %s\n",url.c_str());
    openUrl(url);
}
void CBUtility::rateApp(const string& appleID)
{
#ifdef __CBIOS__
    // iOS rate url
    string url = "itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=";
#elif __CBANDROID__
    // Android rate url
    string url = "market://details?id=";
#else
    string url = "";
#endif
    url += appleID;
    //DebugLog("Rate App: %s\n",url.c_str());
    openUrl(url);
}

int CBUtility::rand()
{
#ifdef __CBIOS__
    return abs((int)arc4random());
#else
    return (int)rand();
#endif
}

bool CBUtility::checkFileExist(string fileName)
{
    bool flag = false;
    fstream fin;
    fin.open(fileName.c_str(),ios::in);
    if( fin.is_open() )
    {
        flag=true;
    }
    fin.close();
    return flag;
}
string CBUtility::getDocumentPath(const string& fileName)
{
    string fullName = m_utility->getDocumentPath(fileName);
    return fullName;
}
string CBUtility::getResourcePath(const string& fileName)
{
    string fullName = m_utility->getResourcePath(fileName);
    return fullName;
}