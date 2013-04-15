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
#include "CBAchievementExhibitor.h"
#include "CBCommunityExhibitorBase.h"
#include "CBFacebookExhibitor.h"
#include "CBWeiboExhibitor.h"
#include "CBTwitterExhibitor.h"

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

void CBCommunityManager::autoLogin()
{
    initialFacebook();
    initialWeibo();
    initialTwitter();
    m_facebookExhibitor->autoLogin();
    m_weiboExhibitor->autoLogin();
    m_twitterExhibitor->autoLogin();
}

void CBCommunityManager::initialFacebook()
{
    if(m_facebookExhibitor == NULL)
    {
        m_facebookExhibitor = new CBFacebookExhibitor();
        attachExhibitor(m_facebookExhibitor);
    }
}
void CBCommunityManager::initialWeibo()
{
    if(m_weiboExhibitor == NULL)
    {
        m_weiboExhibitor = new CBWeiboExhibitor();
        attachExhibitor(m_weiboExhibitor);
    }
}
void CBCommunityManager::initialTwitter()
{
    if(m_twitterExhibitor == NULL)
    {
        m_twitterExhibitor = new CBTwitterExhibitor();
        attachExhibitor(m_twitterExhibitor);
    }
}

void CBCommunityManager::loginFacebook()
{
    m_facebookExhibitor->login();
}

void CBCommunityManager::loginWeibo()
{
    m_weiboExhibitor->login();
}

void CBCommunityManager::loginTwitter()
{
    m_twitterExhibitor->login();
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