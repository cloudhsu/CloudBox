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
#include "CBUtility.h"

const string CBAchievementManager::DEFAULT_ACHIEVEMENT_SETTING_NAME = "default_achievement.xml";
const string CBAchievementManager::ACHIEVEMENT_SETTING_NAME = "CBAchievement.xml";

CBAchievementManager::CBAchievementManager()
:m_defaultAchievements(NULL),m_currentAchievements(NULL),m_isInitialed(false)
{
}

CBAchievementManager::~CBAchievementManager()
{
    CBDELETE(m_defaultAchievements);
    CBDELETE(m_currentAchievements);
}

void CBAchievementManager::initialAchievementSystem()
{
    if(!m_isInitialed)
    {
        loadAchievement();
        m_isInitialed = true;
    }
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
    checkArchievementComplete(id);
}

void CBAchievementManager::increaseAchievement( const string& id, double increaseValue )
{
    m_currentAchievements->increaseAchievement(id, increaseValue);
    checkArchievementComplete(id);
}

void CBAchievementManager::completeAchievement(const string& id)
{
    m_currentAchievements->completeAchievement(id);
    checkArchievementComplete(id);
}

void CBAchievementManager::checkArchievementComplete(const string& id)
{
    CBAchievementItem* item = m_currentAchievements->getAchievementItem(id);
    if(item->getIsComplete())
    {
        DebugLog("Achievement:%s completed.\n",id.c_str());
        notify(item);
    }
    saveAchievement();
}

void CBAchievementManager::loadAchievement()
{
    CBXmlUtility* xmlUtility = new CBXmlUtility();
    m_defaultAchievements = xmlUtility->loadAchievement(defaultAchievementName());
    string myAchievements = myAchievementName();
    if(SUtility.checkFileExist(myAchievements))
    {
        m_currentAchievements = xmlUtility->loadAchievement(myAchievements);
        syncAchievement();
    }
    else
    {
        m_currentAchievements = xmlUtility->loadAchievement(defaultAchievementName());
    }
    saveAchievement();
    CBDELETE(xmlUtility);
}

void CBAchievementManager::syncAchievement()
{
    m_currentAchievements->syncAchievement(m_defaultAchievements);
}

void CBAchievementManager::saveAchievement()
{
    CBXmlUtility* xmlUtility = new CBXmlUtility();
    xmlUtility->saveAchievement(myAchievementName(), m_currentAchievements);
    CBDELETE(xmlUtility);
}

string CBAchievementManager::myAchievementName()
{
    string myAchievementName = SUtility.getDocumentPath(ACHIEVEMENT_SETTING_NAME);
    return myAchievementName;
}

string CBAchievementManager::defaultAchievementName()
{
    string myAchievementName = SUtility.getResourcePath(DEFAULT_ACHIEVEMENT_SETTING_NAME);
    return myAchievementName;
}