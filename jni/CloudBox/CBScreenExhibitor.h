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
#include <vector>
using namespace std;

class CBScreenExhibitItem;

class CBScreenExhibitor : public CBAchievementExhibitor
{
private:
    vector<CBScreenExhibitItem*> m_exhibitItems;
protected:
public:
    CBScreenExhibitor();
    ~CBScreenExhibitor();
    
    // define function for achievement exhibtion
    void post(CBAchievementItem* object);

    void draw();
    void update();
};

#endif