/*
 *  CBGameCenterExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBGAMECENTEREXHIBITOR_H__
#define __CBGAMECENTEREXHIBITOR_H__

#include "CBGameCenterExhibitorBase.h"
#include <string>
using namespace std;

class CBGameCenterExhibitor : public CBGameCenterExhibitorBase
{
private:
    CBGameCenterExhibitorBase* m_implGameCenterExhibitor;
public:
    CBGameCenterExhibitor();
    virtual ~CBGameCenterExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void post(CBAchievementItem* object);
    
    void showGameCenter();
    void reportScore(string name, int score);
    void resetAchievements();
};

#endif