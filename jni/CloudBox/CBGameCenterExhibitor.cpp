/*
 *  CBGameCenterExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBGameCenterExhibitor.h"
#include "CBLibrary.h"

CBGameCenterExhibitor::CBGameCenterExhibitor()
{

}

CBGameCenterExhibitor::~CBGameCenterExhibitor()
{

}

void CBGameCenterExhibitor::login()
{
    DebugLog("call CBDebugExhibitor::login()\n");
}
void CBGameCenterExhibitor::logout()
{
    DebugLog("call CBDebugExhibitor::logout()\n");
}

void CBGameCenterExhibitor::post(CBAchievementItem* object)
{
    DebugLog("call CBDebugExhibitor::post()\n");
    DebugLog("ID:%s [%.2f%%]\n",object->getId().c_str(),object->getPercentage());
    DebugLog("Current Value:[%.2f], Target Value:[%.2f] \n",object->getCurrentValue(),object->getTargetValue());
    DebugLog("Complete:[%s] \n", object->getIsComplete() ? "YES": "NO");
    DebugLog("Description:%s, Image Name:%s \n", object->getDescription().c_str(), object->getImageName().c_str());
}