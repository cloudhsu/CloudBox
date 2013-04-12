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
#include "CBExhibitorFactory.h"

CBGameCenterExhibitor::CBGameCenterExhibitor()
:m_implGameCenterExhibitor(NULL)
{
    m_implGameCenterExhibitor = CBExhibitorFactory::createGameCenterExhibitor();
}

CBGameCenterExhibitor::~CBGameCenterExhibitor()
{
    CBDELETE(m_implGameCenterExhibitor);
}

void CBGameCenterExhibitor::login()
{
    if(m_implGameCenterExhibitor != NULL)
        m_implGameCenterExhibitor->login();
}

void CBGameCenterExhibitor::post(CBAchievementItem* object)
{
    if(m_implGameCenterExhibitor != NULL)
        m_implGameCenterExhibitor->post(object);
}

void CBGameCenterExhibitor::showGameCenter()
{
    if(m_implGameCenterExhibitor != NULL)
        m_implGameCenterExhibitor->showGameCenter();
}
void CBGameCenterExhibitor::reportScore(string name, int score)
{
    if(m_implGameCenterExhibitor != NULL)
        m_implGameCenterExhibitor->reportScore(name, score);
}
void CBGameCenterExhibitor::resetAchievements()
{
    if(m_implGameCenterExhibitor != NULL)
        m_implGameCenterExhibitor->resetAchievements();
}