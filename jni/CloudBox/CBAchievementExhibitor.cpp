/*
 *  CBAchievementExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAchievementExhibitor.h"
#include "CBLibrary.h"

CBAchievementExhibitor::CBAchievementExhibitor()
{
}

CBAchievementExhibitor::~CBAchievementExhibitor()
{
}

void CBAchievementExhibitor::update( CBAchievementItem* object )
{
    post(object);
}