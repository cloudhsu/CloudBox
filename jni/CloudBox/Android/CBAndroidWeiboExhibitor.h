/*
 *  CBAndroidWeiboExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBANDROIDWEIBOEXHIBITOR_H__
#define __CBANDROIDWEIBOEXHIBITOR_H__

#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBAndroidWeiboExhibitor : public CBCommunityExhibitor
{
private:
    
public:
    CBAndroidWeiboExhibitor();
    ~CBAndroidWeiboExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif