/*
 *  CBFacebookExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBFacebookExhibitor.h"
#include "CBLibrary.h"

CBFacebookExhibitor::CBFacebookExhibitor()
{

}

CBFacebookExhibitor::~CBFacebookExhibitor()
{

}

void CBFacebookExhibitor::login()
{
    DebugLog("call CBDebugExhibitor::login()\n");
}
void CBFacebookExhibitor::logout()
{
    DebugLog("call CBDebugExhibitor::logout()\n");
}

void CBFacebookExhibitor::post(CBAchievementItem* object)
{
    DebugLog("call CBDebugExhibitor::post()\n");
    DebugLog("ID:%s [%.2f%%]\n",object->getId().c_str(),object->getPercentage());
    DebugLog("Current Value:[%.2f], Target Value:[%.2f] \n",object->getCurrentValue(),object->getTargetValue());
    DebugLog("Complete:[%s] \n", object->getIsComplete() ? "YES": "NO");
    DebugLog("Description:%s, Image Name:%s \n", object->getDescription().c_str(), object->getImageName().c_str());
}