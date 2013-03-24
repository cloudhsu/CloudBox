/*
 *  CBLibXMLUtility.h
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/10/15.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#ifndef __CBLIBXMLUTILITY_H__
#define __CBLIBXMLUTILITY_H__

#include "CBXmlBase.h"

class CBLibXMLUtility : public CBXmlBase
{
private:
    void saveWithLibXML(map<string,string>& data,const string& fileName);
    map<string,string> loadWithLibXML(string fileName);
public:
    CBLibXMLUtility(void);
    ~CBLibXMLUtility(void);

    void saveToXML(map<string,string>& data,const string& fileName);
    map<string,string> loadFromXML(string fileName);

    CBAchievements* loadAchievement(const string& fileName);
    void saveAchievement(const string& fileName, CBAchievements* achievements);
};

#endif