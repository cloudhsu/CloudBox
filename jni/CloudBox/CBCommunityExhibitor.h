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

#include "CBCommunityExhibitorBase.h"

class CBCommunityExhibitor : public CBCommunityExhibitorBase
{
protected:
    CBCommunityExhibitorBase* m_implExhibitor;
public:
    CBCommunityExhibitor();
    virtual ~CBCommunityExhibitor();

    virtual void login();
    virtual void logout();
    virtual void post(CBAchievementItem* object);
};

#endif