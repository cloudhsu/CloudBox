/*
 *  CBFacebookExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBFACEBOOKXHIBITOR_H__
#define __CBFACEBOOKXHIBITOR_H__

#include "CBAchievementExhibitor.h"
#include <string>
using namespace std;

class CBFacebookExhibitor : public CBAchievementExhibitor
{
private:
    
public:
    CBFacebookExhibitor();
    ~CBFacebookExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif