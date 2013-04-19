/*
 *  CBCommunityExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/19.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBCOMMUNITYEXHIBITOR_H__
#define __CBCOMMUNITYEXHIBITOR_H__

#include "CBCommunityExhibitorBase.h"

class CBCommunityExhibitor : public CBCommunityExhibitorBase
{
protected:
    CBCommunityExhibitorBase* m_implExhibitor;
public:
    CBCommunityExhibitor();
    virtual ~CBCommunityExhibitor();

    void autoLogin();
    void login();
    void logout();
    void post(CBAchievementItem* object);
    
    void postStatus(string msg);
    void postStatus(string msg,string imageName);
    void postFeed(string name,string link, string caption, string description, string msg);
};

#endif