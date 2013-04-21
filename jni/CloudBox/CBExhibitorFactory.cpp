/*
 *  CBExhibitorFactory.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBFactory.h"
#include "CBExhibitorFactory.h"

#include "CBCommunityExhibitorBase.h"
#include "CBGameCenterExhibitorBase.h"

#ifdef __CBIOS__
#include "CBiOSGameCenterExhibitor.h"
#include "CBiOSFacebookExhibitor.h"
#elif __CBANDROID__
#include "Android/CBAndroidFacebookExhibitor.h"
#elif WIN32
#endif
// --------------------------------------------------

// --------------------------------------------------

// --------------------------------------------------
// declare name
#ifdef __CBIOS__
// for iOS
typedef CBiOSFacebookExhibitor FACEBOOK_EXHIBITOR;
typedef CBCommunityExhibitorSimulator TWITTER_EXHIBITOR;
typedef CBCommunityExhibitorSimulator WEIBO_EXHIBITOR;
typedef CBiOSGameCenterExhibitor GAMECENTER_EXHIBITOR;
#elif __CBANDROID__
// for Android
typedef CBAndroidFacebookExhibitor FACEBOOK_EXHIBITOR;
typedef CBCommunityExhibitorSimulator TWITTER_EXHIBITOR;
typedef CBCommunityExhibitorSimulator WEIBO_EXHIBITOR;
typedef CBGameCenterExhibitorSimulator GAMECENTER_EXHIBITOR;
#elif WIN32
// for default none behavior
typedef CBCommunityExhibitorSimulator FACEBOOK_EXHIBITOR;
typedef CBCommunityExhibitorSimulator TWITTER_EXHIBITOR;
typedef CBCommunityExhibitorSimulator WEIBO_EXHIBITOR;
typedef CBGameCenterExhibitorSimulator GAMECENTER_EXHIBITOR;
#else
// for default none behavior
typedef CBCommunityExhibitorSimulator FACEBOOK_EXHIBITOR;
typedef CBCommunityExhibitorSimulator TWITTER_EXHIBITOR;
typedef CBCommunityExhibitorSimulator WEIBO_EXHIBITOR;
typedef CBGameCenterExhibitorSimulator GAMECENTER_EXHIBITOR;
#endif
// --------------------------------------------------

CBCommunityExhibitorBase* CBExhibitorFactory::createFacebookExhibitor()
{
    return CBFactory::create<FACEBOOK_EXHIBITOR>();
}
CBCommunityExhibitorBase* CBExhibitorFactory::createTwitterExhibitor()
{
    return CBFactory::create<TWITTER_EXHIBITOR>();
}
CBCommunityExhibitorBase* CBExhibitorFactory::createWeiboExhibitor()
{
    return CBFactory::create<WEIBO_EXHIBITOR>();
}
CBGameCenterExhibitorBase* CBExhibitorFactory::createGameCenterExhibitor()
{
    return CBFactory::create<GAMECENTER_EXHIBITOR>();
}

