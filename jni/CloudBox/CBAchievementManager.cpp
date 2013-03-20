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
#include "CBXmlUtility.h"

const string CBAchievementManager::DEFAULT_ACHIEVEMENT_SETTING_NAME = "defAchievement.plist";
const string CBAchievementManager::ACHIEVEMENT_SETTING_NAME = "CBAchievement.plist";

CBAchievementManager::CBAchievementManager()
:m_defaultAchievements(NULL),m_currentAchievements(NULL)
{
}

CBAchievementManager::~CBAchievementManager()
{
    CBDELETE(m_defaultAchievements);
    CBDELETE(m_currentAchievements);
}

void CBAchievementManager::initialAchievementSystem()
{
    loadAchievement();
}

void CBAchievementManager::resetAllAchievement()
{
    m_currentAchievements->resetAllAchievement();
}

void CBAchievementManager::resetAchievement(const string& id)
{
    m_currentAchievements->resetAchievement(id);
}

void CBAchievementManager::updateAchievement( const string& id, double newValue )
{
    m_currentAchievements->updateAchievement(id, newValue);
}

void CBAchievementManager::increaseAchievement( const string& id, double increaseValue )
{
    m_currentAchievements->increaseAchievement(id, increaseValue);
    checkArchievementComplete(id);
}

void CBAchievementManager::checkArchievementComplete(const string& id)
{
    CBAchievementItem* item = m_currentAchievements->getAchievementItem(id);
    notify(item);
    saveAchievement();
}

void CBAchievementManager::loadAchievement()
{
    CBXmlUtility* xmlUtility = new CBXmlUtility();
    m_defaultAchievements = xmlUtility->loadAchievement(DEFAULT_ACHIEVEMENT_SETTING_NAME);
    m_currentAchievements = xmlUtility->loadAchievement(ACHIEVEMENT_SETTING_NAME);
    syncAchievement();
    CBDELETE(xmlUtility);
}

void CBAchievementManager::syncAchievement()
{
    m_currentAchievements->syncAchievement(m_defaultAchievements);
}

void CBAchievementManager::saveAchievement()
{
    CBXmlUtility* xmlUtility = new CBXmlUtility();
    xmlUtility->saveAchievement(ACHIEVEMENT_SETTING_NAME, m_currentAchievements);
    CBDELETE(xmlUtility);
}