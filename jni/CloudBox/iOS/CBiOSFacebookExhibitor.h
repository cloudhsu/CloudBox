/*
 *  CBiOSFacebookExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBIOSFACEBOOKEXHIBITOR_H__
#define __CBIOSFACEBOOKEXHIBITOR_H__

#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBiOSFacebookExhibitor : public CBCommunityExhibitor
{
private:
    
public:
    CBiOSFacebookExhibitor();
    ~CBiOSFacebookExhibitor();
    
    // define function for achievement exhibtion
    void autoLogin();
    void login();
    void logout();
    void post(CBAchievementItem* object);
    
    void postStatus(string msg);
    void postStatus(string msg,string imageName);
    void postFeed(string name,string link, string caption, string description, string msg);
};

#endif