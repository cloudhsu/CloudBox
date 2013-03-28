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
#include "CBAchievementExhibitor.h"
#include "CBScreenExhibitor.h"

const string CBAchievementManager::DEFAULT_ACHIEVEMENT_SETTING_NAME = "default_achievement.xml";
const string CBAchievementManager::ACHIEVEMENT_SETTING_NAME = "CBAchievement.xml";

CBAchievementManager::CBAchievementManager()
:m_defaultAchievements(NULL),m_currentAchievements(NULL),m_isInitialed(false),
m_screenExhibitor(NULL)
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
        initialExhibiter();
        m_isInitialed = true;
    }
}

void CBAchievementManager::initialExhibiter()
{
    initialDefaultExhibiter();
}

void CBAchievementManager::attachExhibitor( CBAchievementExhibitor* exhibitor )
{
    attachObserver(exhibitor);
}

void CBAchievementManager::detachExhibitor( CBAchievementExhibitor* exhibitor )
{
    detachObserver(exhibitor);
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
    postArchievement(id);
}

void CBAchievementManager::increaseAchievement( const string& id, double increaseValue )
{
    m_currentAchievements->increaseAchievement(id, increaseValue);
    postArchievement(id);
}

void CBAchievementManager::completeAchievement(const string& id)
{
    m_currentAchievements->completeAchievement(id);
    postArchievement(id);
}

void CBAchievementManager::postArchievement(const string& id)
{
    CBAchievementItem* item = m_currentAchievements->getAchievementItem(id);
    if(!item->getIsPosted())
    {
        notify(item);
        if(item->getIsComplete())
        {
            item->posted();
        }
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

void CBAchievementManager::updateScreenExhibitor()
{
    if(m_screenExhibitor != NULL)
        m_screenExhibitor->update();
}

void CBAchievementManager::drawScreenExhibitor()
{
    if(m_screenExhibitor != NULL)
        m_screenExhibitor->draw();
}

void CBAchievementManager::initialDefaultExhibiter()
{
    attachExhibitor(new CBDebugExhibitor());
    m_screenExhibitor = new CBScreenExhibitor();
    attachExhibitor(m_screenExhibitor);
}