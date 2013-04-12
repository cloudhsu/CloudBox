/*
 *  CBGameCenterExhibitorBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBGAMECENTEREXHIBITORBASE_H__
#define __CBGAMECENTEREXHIBITORBASE_H__

#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBGameCenterExhibitorBase : public CBAchievementExhibitor
{
public:
    CBGameCenterExhibitorBase() {}
    virtual ~CBGameCenterExhibitorBase() {}
    
    // define function for game center achievement exhibition
    virtual void login() = 0;
    virtual void post(CBAchievementItem* object) = 0;
    
    virtual void showGameCenter() = 0;
    virtual void reportScore(string name, int score) = 0;
    virtual void resetAchievements() = 0;
};

class CBGameCenterExhibitorSimulator : public CBGameCenterExhibitorBase
{
public:
    CBGameCenterExhibitorSimulator() {}
    ~CBGameCenterExhibitorSimulator() {}
    
    // define function for achievement exhibtion
    void login() {}
    void post(CBAchievementItem* object) {}
    
    void showGameCenter() {}
    void reportScore(string name, int score) {}
    void resetAchievements() {}
};

#endif