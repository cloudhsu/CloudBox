/*
 *  CBCommunityExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBCommunityExhibitor.h"
#include "CBLibrary.h"

CBCommunityExhibitor::CBCommunityExhibitor()
:m_implExhibitor(NULL)
{
}

CBCommunityExhibitor::~CBCommunityExhibitor()
{
    CBDELETE(m_implExhibitor);
}

void CBCommunityExhibitor::login()
{
    if(m_implExhibitor != NULL)
        m_implExhibitor->login();
}
void CBCommunityExhibitor::logout()
{
    if(m_implExhibitor != NULL)
        m_implExhibitor->logout();
}

void CBCommunityExhibitor::post(CBAchievementItem* object)
{
    if(m_implExhibitor != NULL && object->getIsComplete())
    {
        m_implExhibitor->post(object);
    }
}