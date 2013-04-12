/*
 *  CBiOSGameCenterExhibitor.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import "GameCenterManager.h"
#include "CBiOSGameCenterExhibitor.h"
#include "CBLibrary.h"

CBiOSGameCenterExhibitor::CBiOSGameCenterExhibitor()
{

}

CBiOSGameCenterExhibitor::~CBiOSGameCenterExhibitor()
{

}

void CBiOSGameCenterExhibitor::login()
{
    DebugLog("call CBiOSGameCenterExhibitor::login()\n");
    [[GameCenterManager sharedInstance] login];
}

void CBiOSGameCenterExhibitor::post(CBAchievementItem* object)
{
    DebugLog("call CBiOSGameCenterExhibitor::post()\n");
    NSString *name = [[[NSString alloc] initWithUTF8String: object->getId().c_str()]autorelease];
    [[GameCenterManager sharedInstance] submitAchievement:name percentComplete:object->getPercentage()];
}

void CBiOSGameCenterExhibitor::showGameCenter()
{
    [[GameCenterManager sharedInstance]showAchievements];
}
void CBiOSGameCenterExhibitor::reportScore(string name, int score)
{
    NSString *category = [[[NSString alloc] initWithUTF8String: name.c_str()]autorelease];
    [[GameCenterManager sharedInstance]reportScore:score forCategory:category];
}
void CBiOSGameCenterExhibitor::resetAchievements()
{
    [[GameCenterManager sharedInstance]resetAchievements];
}