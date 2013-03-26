/*
 *  CBScreenExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBSCREENEXHIBITOR_H__
#define __CBSCREENEXHIBITOR_H__

#include "CBAchievementExhibitor.h"
#include <string>
using namespace std;

class CBScreenExhibitor : public CBAchievementExhibitor
{
private:
    
public:
    CBScreenExhibitor();
    ~CBScreenExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif