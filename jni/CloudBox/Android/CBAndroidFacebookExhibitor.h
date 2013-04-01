/*
 *  CBAndroidFacebookExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBANDROIDFACEBOOKEXHIBITOR_H__
#define __CBANDROIDFACEBOOKEXHIBITOR_H__

#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBAndroidFacebookExhibitor : public CBCommunityExhibitor
{
private:
    
public:
    CBAndroidFacebookExhibitor();
    ~CBAndroidFacebookExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif