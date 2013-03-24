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
private:
    string m_info;
    string m_version;
    typedef map<string,CBAchievementItem*> ahcievementMap;
    ahcievementMap m_achievements;
public:
    CBAchievements();
    ~CBAchievements();

    inline std::string getInfo() const { return m_info; }
    inline void setInfo(std::string val) { m_info = val; }
    
    inline std::string getVersion() const { return m_version; }
    inline void setVersion(std::string val) { m_version = val; }

    CBAchievementItem* getAchievementItem(const string& id);
    
    ahcievementMap& getAchievements() { return m_achievements; }

    void resetAchievement(const string& id);
    void resetAllAchievement();

    void updateAchievement(const string& id, double newValue);
    void increaseAchievement(const string& id, double increaseValue);
    void completeAchievement(const string& id);

    void addAchievement(CBAchievementItem* item);

    void syncAchievement(CBAchievements* achievements);
};

#endif