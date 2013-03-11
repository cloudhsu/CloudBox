/*
 *  CBAchievementItem.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBACHIEVEMENTITEM_H__
#define __CBACHIEVEMENTITEM_H__

#include <string>
using namespace std;

#define DEFAULT_ACHIEVEMENT_VALUE 0

class CBAchievementItem
{
private:
    string m_id;
    string m_description;
    double m_targetValue;
    double m_currentValue;
public:
    CBAchievementItem();
    ~CBAchievementItem();

    void update(double newValue);
    void reset();
    void increase(double increaseValue);


    inline string getId() const { return m_id; }
    inline void setId(std::string val) { m_id = val; }

    inline string getDescription() const { return m_description; }
    inline void setDescription(std::string val) { m_description = val; }

    double getPercentage();
};

#endif