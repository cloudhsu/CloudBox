/*
 *  CBAchievementManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBACHIEVEMENTMANAGER_H__
#define __CBACHIEVEMENTMANAGER_H__

class CBAchievements;

class CBAchievementManager
{
private:
    const static string DEFAULT_ACHIEVEMENT_SETTING_NAME;
    const static string ACHIEVEMENT_SETTING_NAME;
    CBAchievements* m_defaultAchievements;
    CBAchievements* m_currentAchievements;

public:
    CBAchievementManager();
    ~CBAchievementManager();

    void loadAchievements();

};

#endif