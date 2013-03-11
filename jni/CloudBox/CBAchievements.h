/*
 *  CBAchievements.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBACHIEVEMENT_H__
#define __CBACHIEVEMENT_H__

#include <map>
#include <string>
using namespace std;

class CBAchievementItem;

class CBAchievements
{
    map<string,CBAchievementItem*> m_achievements;
public:
    CBAchievements();
    ~CBAchievements();

    void loadAchievement(const string& fileName);
    void saveAchievement(const string& fileName);

    CBAchievementItem* getAchievementItem(const string& id);

    void resetAchievement(const string& id);
    void resetAllAchievement();

    void updateAchievement(const string& id, double newValue);
    void increaseAchievement(const string& id, double increaseValue);
};

#endif