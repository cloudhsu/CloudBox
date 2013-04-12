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
class CBScreenExhibitor;
class CBGameCenterExhibitor;
class CBCommunityExhibitor;

class CBAchievementManager : public CBSingleton<CBAchievementManager>, protected CBSubjectMediator<CBAchievementItem>
{
private:
    bool m_isSupported;
    bool m_isInitialed;
    const static string DEFAULT_ACHIEVEMENT_SETTING_NAME;
    const static string ACHIEVEMENT_SETTING_NAME;
    CBAchievements* m_defaultAchievements;
    CBAchievements* m_currentAchievements;
    CBScreenExhibitor* m_screenExhibitor;
    CBGameCenterExhibitor* m_gameCenterExhibitor;

    void postArchievement(const string& id);

    void loadAchievement();
    void syncAchievement();
    void saveAchievement();
    string myAchievementName();
    string defaultAchievementName();

    void initialExhibiter();
    void initialDefaultExhibiter();
    void initialGameCenter();
    void resetAllGameCenterAchievement();

public:
    CBAchievementManager();
    ~CBAchievementManager();

    void detachExhibitor(CBAchievementExhibitor* exhibitor);
    void attachExhibitor(CBAchievementExhibitor* exhibitor);

    inline bool getIsSupport() { return m_isSupported; }
    inline bool getIsInitial() { return m_isInitialed; }

    void initialAchievementSystem();

    void resetAchievement(const string& id);
    void resetAllAchievement();

    void updateAchievement(const string& id, double newValue);
    void increaseAchievement(const string& id, double increaseValue);
    void completeAchievement(const string& id);

    void updateScreenExhibitor();
    void drawScreenExhibitor();
    
    void showGameCenter();
    
};

#define SAchievementManager CBAchievementManager::instance()

#endif