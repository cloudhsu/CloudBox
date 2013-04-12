/*
 *  CBCommunityManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/11.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBCOMMUNITYMANAGER_H__
#define __CBCOMMUNITYMANAGER_H__

#include "CBSubjectMediator.h"
#include "CBSingleton.h"
#include <string>
using namespace std;

class CBAchievementItem;
class CBFeed;

class CBCommunityManager : public CBSingleton<CBCommunityManager>, protected CBSubjectMediator<CBAchievementItem>
{
private:
    CBCommunityExhibitor* m_facebookExhibitor;

    void detachExhibitor(CBAchievementExhibitor* exhibitor);
    void attachExhibitor(CBAchievementExhibitor* exhibitor);
public:
    CBCommunityManager();
    ~CBCommunityManager();

    void loginFacebook();
    void loginWeibo();
    void loginTwitter();

    void post(string msg);
    void post(string msg, string imageName);
    void post(CBFeed* feed);
};

#define SCommunityManager CBCommunityManager::instance()

#endif