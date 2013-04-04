/*
 *  CBAchievementItem.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAchievementItem.h"

CBAchievementItem::CBAchievementItem()
:m_complete(false),m_isPosted(false),m_targetValue(0.0),m_currentValue(0.0),
m_id(""),m_description(""),m_imageName("")
{
}

CBAchievementItem::~CBAchievementItem()
{
}

void CBAchievementItem::update( double newValue )
{
    if(!m_complete)
    {
        m_currentValue = newValue;
        checkComplete();
    }
}

void CBAchievementItem::reset()
{
    m_currentValue = DEFAULT_ACHIEVEMENT_VALUE;
    m_complete = false;
    m_isPosted = false;
}

void CBAchievementItem::increase( double increaseValue )
{
    if(!m_complete)
    {
        m_currentValue += increaseValue;
        checkComplete();
    }
}

void CBAchievementItem::complete()
{
    m_currentValue = m_targetValue;
    m_complete = true;
}

void CBAchievementItem::checkComplete()
{
    if(m_currentValue >= m_targetValue)
        complete();
}

double CBAchievementItem::getPercentage()
{
    return m_currentValue / m_targetValue * 100;
}

CBAchievementItem* CBAchievementItem::clone( CBAchievementItem* item )
{
    CBAchievementItem* newItem = new CBAchievementItem();
    newItem->setId(item->getId());
    newItem->setTargetValue(item->getTargetValue());
    newItem->setDescription(item->getDescription());
    return newItem;
}