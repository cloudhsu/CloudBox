/*
 *  CBCommunityExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBCOMMUNITYEXHIBITOR_H__
#define __CBCOMMUNITYEXHIBITOR_H__

#include "CBAchievementExhibitor.h"

class CBCommunityExhibitor : public CBAchievementExhibitor
{
protected:
    CBCommunityExhibitor m_implExhibitor;
public:
    CBCommunityExhibitor();
    virtual ~CBCommunityExhibitor();

    virtual void login() = 0;
    virtual void logout() = 0;
    virtual void post(CBAchievementItem* object) = 0;
};

#endif