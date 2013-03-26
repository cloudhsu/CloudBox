/*
 *  CBTwitterExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBTWEITTEREXHIBITOR_H__
#define __CBTWEITTEREXHIBITOR_H__

#include "CBAchievementExhibitor.h"
#include <string>
using namespace std;

class CBTwitterExhibitor : public CBAchievementExhibitor
{
private:
    
public:
    CBTwitterExhibitor();
    virtual ~CBTwitterExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif