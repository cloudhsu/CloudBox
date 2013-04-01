/*
 *  CBiOSWeiboExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBIOSWEIBOEXHIBITOR_H__
#define __CBIOSWEIBOEXHIBITOR_H__

#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBiOSWeiboExhibitor : public CBCommunityExhibitor
{
private:
    
public:
    CBiOSWeiboExhibitor();
    ~CBiOSWeiboExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif