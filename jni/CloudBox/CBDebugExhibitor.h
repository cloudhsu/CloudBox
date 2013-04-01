/*
 *  CBDebugExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBDEBUGEXHIBITOR_H__
#define __CBDEBUGEXHIBITOR_H__

#include "CBAchievementExhibitor.h"
#include <string>
using namespace std;

class CBDebugExhibitor : public CBAchievementExhibitor
{
public:
    CBDebugExhibitor();
    ~CBDebugExhibitor();

    void post(CBAchievementItem* object);
};

#endif