/*
 *  CBXmlBase.h
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/10/15.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#ifndef __CBXMLBASE_H__
#define __CBXMLBASE_H__

#include <string>
#include <map>
using namespace std;

class CBAchievements;

class CBXmlBase
{
public:
    CBXmlBase(void){}
    virtual ~CBXmlBase(void){}

    virtual void saveToXML(map<string,string>& data,const string& fileName) = 0;
    virtual map<string,string> loadFromXML(string fileName) = 0;

    virtual CBAchievements* loadAchievement(const string& fileName) = 0;
    virtual void saveAchievement(const string& fileName, CBAchievements* achievements) = 0;
};

#endif