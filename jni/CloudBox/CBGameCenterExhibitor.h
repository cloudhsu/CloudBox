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

#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBGameCenterExhibitor : public CBCommunityExhibitor
{
private:
    
public:
    CBGameCenterExhibitor();
    ~CBGameCenterExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif