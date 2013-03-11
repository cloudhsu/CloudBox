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
{
    reset();
}

CBAchievementItem::~CBAchievementItem()
{
}

void CBAchievementItem::update( double newValue )
{
    m_currentValue = newValue;
}

void CBAchievementItem::reset()
{
    m_currentValue = DEFAULT_ACHIEVEMENT_VALUE;
}

void CBAchievementItem::increase( double increaseValue )
{
    m_currentValue += increaseValue;
}

double CBAchievementItem::getPercentage()
{
    return m_currentValue / m_targetValue * 100;
}