/*
 *  CBExhibitorFactory.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBEXHIBITORFACTORY_H__
#define _CBEXHIBITORFACTORY_H__

class CBAchievementExhibitor;
class CBCommunityExhibitorBase;
class CBGameCenterExhibitorBase;

class CBExhibitorFactory
{
private:
public:
    static CBCommunityExhibitorBase* createFacebookExhibitor();
    static CBCommunityExhibitorBase* createTwitterExhibitor();
    static CBCommunityExhibitorBase* createWeiboExhibitor();
    static CBGameCenterExhibitorBase* createGameCenterExhibitor();
};

#endif
