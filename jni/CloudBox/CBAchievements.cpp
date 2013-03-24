/*
 *  CBAchievements.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLibrary.h"
#include "CBAchievements.h"
#include "CBAchievementItem.h"

CBAchievements::CBAchievements()
:m_info("CloudBox Achievement System"),m_version("V0.1")
{
}

CBAchievements::~CBAchievements()
{
    for (ahcievementMap::iterator it = m_achievements.begin(); it != m_achievements.end(); ++it)
    {
        CBDELETE(it->second);
    }
}

CBAchievementItem* CBAchievements::getAchievementItem( const string& id )
{
    CBAchievementItem* item = NULL;
    if( !(m_achievements.find(id) == m_achievements.end()) )
    {
        item = m_achievements[id];
    }
    return item;
}

void CBAchievements::resetAchievement( const string& id )
{
    CBAchievementItem* item = NULL;
    if( !(m_achievements.find(id) == m_achievements.end()) )
    {
        item = m_achievements[id];
        item->reset();
    }
}

void CBAchievements::resetAllAchievement()
{
    for (ahcievementMap::iterator it = m_achievements.begin(); it != m_achievements.end(); ++it)
    {
        it->second->reset();
    }
}

void CBAchievements::updateAchievement( const string& id, double newValue )
{
    CBAchievementItem* item = NULL;
    if( !(m_achievements.find(id) == m_achievements.end()) )
    {
        item = m_achievements[id];
        item->update(newValue);
    }
}

void CBAchievements::increaseAchievement( const string& id, double increaseValue )
{
    CBAchievementItem* item = NULL;
    if( !(m_achievements.find(id) == m_achievements.end()) )
    {
        item = m_achievements[id];
        item->increase(increaseValue);
    }
}

void CBAchievements::completeAchievement(const string& id)
{
    CBAchievementItem* item = NULL;
    if( !(m_achievements.find(id) == m_achievements.end()) )
    {
        item = m_achievements[id];
        item->complete();
    }
}

void CBAchievements::addAchievement( CBAchievementItem* item )
{
    m_achievements[item->getId()] = item;
}

void CBAchievements::syncAchievement( CBAchievements* achievements )
{
    for (ahcievementMap::iterator it = achievements->getAchievements().begin(); it != achievements->getAchievements().end(); ++it)
    {
        string key = it->first;
        if( (m_achievements.find(key) == m_achievements.end()) )
        {
            m_achievements[key] = CBAchievementItem::clone(it->second);
        }
    }
}