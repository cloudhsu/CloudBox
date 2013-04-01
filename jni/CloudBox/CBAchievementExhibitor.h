/*
 *  CBAchievementExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBACHIEVEMENTEXHIBITOR_H__
#define __CBACHIEVEMENTEXHIBITOR_H__

#include "CBAchievementItem.h"
#include "CBObserver.h"

class CBAchievementExhibitor : public CBObserver<CBAchievementItem* >
{
private:
    
public:
    CBAchievementExhibitor();
    virtual ~CBAchievementExhibitor();
    
    void update(CBAchievementItem* object);

    // define function for achievement exhibtion
    virtual void post(CBAchievementItem* object) = 0;
};

#endif