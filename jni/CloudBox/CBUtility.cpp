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
#ifdef __CBIOS__
#include "CBiOSUtility.h"
#else
#include <stdlib.h>
#endif

CBUtility::CBUtility()
{
#ifdef __CBIOS__
    m_utility = new CBiOSUtility();
#else
    DebugLog("CBUtility 1\n");
	m_utility = new CBNoneUtility();
    DebugLog("CBUtility 2\n");
#endif
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
    DebugLog("rankMyGame 1\n");
    bool rated = SUserDefault.getValue<bool>(RATE_TAG, false);
    DebugLog("rankMyGame 2\n");
    int rnd = this->rand() % 100;
    DebugLog("rankMyGame 3\n");
    if(!rated && rnd > 80)
    {
        m_appleID = appleID;
        CBDialog* dialog = new CBSystemDialog();
        DebugLog("rankMyGame 3\n");
        dialog->addAlertEvent(this, &CBUtility::onRateAlertClick);
        dialog->showDialog(DialogTypeRate,"", "Rate me 5 stars?");
        DebugLog("rankMyGame 4\n");
    }
}

void CBUtility::onRateAlertClick(DialogResult result, int clickIndex)
{
    if(result == DialogResultRateNever || result == DialogResultRateMe)
    {
    	DebugLog("set rate result.\n");
        SUserDefault.setValue(RATE_TAG, true);
        DebugLog("save rate result.\n");
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
    string url = "http://itunes.apple.com/WebObjects/MZStore.woa/wa/viewSoftware?id=";
    url += (appleID + "&mt=8");
    //DebugLog("Open App: %s\n",url.c_str());
    openUrl(url);
}
void CBUtility::rateApp(const string& appleID)
{
    string url = "itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=";
    url += appleID;
    //DebugLog("Rate App: %s\n",url.c_str());
    openUrl(url);
}

int CBUtility::rand()
{
#ifdef __CBIOS__
    return abs((int)arc4random());
#else
    return (int)random();
#endif
}
