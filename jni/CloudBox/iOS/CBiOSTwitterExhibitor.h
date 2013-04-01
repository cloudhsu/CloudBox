/*
 *  CBiOSTwitterExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBIOSTWITTEREXHIBITOR_H__
#define __CBIOSTWITTEREXHIBITOR_H__

#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBiOSTwitterExhibitor : public CBCommunityExhibitor
{
private:
    
public:
    CBiOSTwitterExhibitor();
    ~CBiOSTwitterExhibitor();
    
    // define function for achievement exhibtion
    void login();
    void logout();
    void post(CBAchievementItem* object);
};

#endif