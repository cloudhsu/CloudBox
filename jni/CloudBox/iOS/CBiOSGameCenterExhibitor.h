/*
 *  CBiOSGameCenterExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBIOSGAMECENTEREXHIBITOR_H__
#define __CBIOSGAMECENTEREXHIBITOR_H__

#include "CBGameCenterExhibitorBase.h"
#include <string>
using namespace std;

class CBiOSGameCenterExhibitor : public CBGameCenterExhibitorBase
{
private:
    
public:
    CBiOSGameCenterExhibitor();
    ~CBiOSGameCenterExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void post(CBAchievementItem* object);
    
    void showGameCenter();
    void reportScore(string name, int score);
    void resetAchievements();
};

#endif