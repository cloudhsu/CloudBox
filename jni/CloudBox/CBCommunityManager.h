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

class CBAchievementExhibitor;
class CBAchievementItem;
class CBFeed;
class CBCommunityExhibitorBase;

class CBCommunityManager : public CBSingleton<CBCommunityManager>, public CBSubjectMediator<CBAchievementItem>
{
private:
    vector<CBCommunityExhibitorBase*> m_exhibitors;
    CBCommunityExhibitorBase* m_facebookExhibitor;
    CBCommunityExhibitorBase* m_weiboExhibitor;
    CBCommunityExhibitorBase* m_twitterExhibitor;

    void detachExhibitor(CBCommunityExhibitorBase* exhibitor);
    void attachExhibitor(CBCommunityExhibitorBase* exhibitor);
    
    void initialFacebook();
    void initialWeibo();
    void initialTwitter();
    
public:
    CBCommunityManager();
    ~CBCommunityManager();
    
    void autoLogin();

    void loginFacebook();
    void loginWeibo();
    void loginTwitter();

    void post(string msg);
    void post(string msg, string imageName);
    //void post(CBFeed* feed);
    void post(string name,string link, string caption, string description, string msg);
};

#define SCommunityManager CBCommunityManager::instance()

#endif