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

#include "CBSubjectMediator.h"
#include "CBSingleton.h"
#include <string>
using namespace std;

class CBAchievementItem;
class CBAchievements;
class CBAchievementExhibitor;

class CBAchievementManager : public CBSingleton<CBAchievementManager>, public CBSubjectMediator<CBAchievementItem>
{
private:
    bool m_isInitialed;
    const static string DEFAULT_ACHIEVEMENT_SETTING_NAME;
    const static string ACHIEVEMENT_SETTING_NAME;
    CBAchievements* m_defaultAchievements;
    CBAchievements* m_currentAchievements;

    void checkArchievementComplete(const string& id);

    void loadAchievement();
    void syncAchievement();
    void saveAchievement();
    string myAchievementName();
    string defaultAchievementName();

    void detachExhibiter(CBAchievementExhibitor* exhibitor);
    void attachExhibiter(CBAchievementExhibitor* exhibitor);
    void initialExhibiter();

public:
    CBAchievementManager();
    ~CBAchievementManager();

    void initialAchievementSystem();

    void resetAchievement(const string& id);
    void resetAllAchievement();

    void updateAchievement(const string& id, double newValue);
    void increaseAchievement(const string& id, double increaseValue);
    void completeAchievement(const string& id);
};

#define SAchievementManager CBAchievementManager::instance()

#endif