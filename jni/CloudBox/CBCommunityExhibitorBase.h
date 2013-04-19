/*
 *  CBCommunityExhibitorBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/19.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBCOMMUNITYEXHIBITORBASE_H__
#define __CBCOMMUNITYEXHIBITORBASE_H__

#include "CBAchievementExhibitor.h"

class CBCommunityExhibitorBase : public CBAchievementExhibitor
{
public:
    CBCommunityExhibitorBase() {}
    virtual ~CBCommunityExhibitorBase() {}

    virtual void autoLogin() = 0;
    virtual void login() = 0;
    virtual void logout() = 0;
    virtual void post(CBAchievementItem* object) = 0;
    virtual void postStatus(string msg) = 0;
    virtual void postStatus(string msg,string imageName) = 0;
    virtual void postFeed(string name,string link, string caption, string description, string msg) = 0;
};

class CBCommunityExhibitorSimulator : public CBCommunityExhibitorBase
{
public:
    CBCommunityExhibitorSimulator() {}
    virtual ~CBCommunityExhibitorSimulator() {}
    
    void autoLogin() {}
    void login() {}
    void logout() {}
    void post(CBAchievementItem* object) {}
    void postStatus(string msg) {}
    void postStatus(string msg,string imageName) {}
    void postFeed(string name,string link, string caption, string description, string msg) {}
};

#endif
