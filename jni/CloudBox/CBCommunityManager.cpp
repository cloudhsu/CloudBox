/*
 *  CBCommunityManager.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBCommunityManager.h"
#include "CBAchievementItem.h"

CBCommunityManager::CBCommunityManager()
{
}

CBCommunityManager::~CBCommunityManager()
{
}

void CBCommunityManager::attachExhibitor( CBAchievementExhibitor* exhibitor )
{
    attachObserver(exhibitor);
}

void CBCommunityManager::detachExhibitor( CBAchievementExhibitor* exhibitor )
{
    detachObserver(exhibitor);
}

void CBCommunityManager::loginFacebook()
{
    if(m_facebookExhibitor == NULL)
    {
        m_facebookExhibitor = new CBFacebookExhibitor();
        attachExhibitor(m_facebookExhibitor);
    }
    m_facebookExhibitor->login();
}

void CBCommunityManager::loginWeibo()
{

}

void CBCommunityManager::loginTwitter()
{

}

void CBCommunityManager::post( string msg )
{

}

void CBCommunityManager::post( string msg, string imageName )
{

}

void CBCommunityManager::post( CBFeed* feed )
{

}