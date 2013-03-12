/*
 *  CBAchievementManager.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAchievementManager.h"
#include "CBLibrary.h"
#include "CBAchievements.h"
#include "CBAchievementItem.h"

string CBAchievementManager::DEFAULT_ACHIEVEMENT_SETTING_NAME = "defAchievement.plist";
string CBAchievementManager::ACHIEVEMENT_SETTING_NAME = "CBAchievement.plist";

CBAchievementManager::CBAchievementManager()
{
}

CBAchievementManager::~CBAchievementManager()
{
    CBDELETE(m_defaultAchievements);
    CBDELETE(m_currentAchievements);
}

void CBAchievementManager::loadAchievements()
{

}