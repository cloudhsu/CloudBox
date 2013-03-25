/*
 *  CBXmlUtility.cpp
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/10/15.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#include "CBLibXMLUtility.h"
#include "CBXmlUtility.h"
#include "CBUtility.h"
#include "CBLibrary.h"

CBXmlUtility::CBXmlUtility(void)
{
    m_xmlUtility = new CBLibXMLUtility();
}

CBXmlUtility::~CBXmlUtility(void)
{
    CBDELETE(m_xmlUtility);
}

void CBXmlUtility::saveToXML(map<string,string>& data,const string& fileName)
{
    string fullName = SUtility.getDocumentPath(fileName);
    m_xmlUtility->saveToXML(data,fullName);
}
map<string,string> CBXmlUtility::loadFromXML(string fileName)
{
    string fullName = SUtility.getDocumentPath(fileName);
    map<string,string> data;
    if(SUtility.checkFileExist(fullName))
    {
        data = m_xmlUtility->loadFromXML(fullName);
    }
    return data;
}

CBAchievements* CBXmlUtility::loadAchievement(const string& fileName)
{
    CBAchievements* achievements = NULL;
    achievements = m_xmlUtility->loadAchievement(fileName);
    return achievements;
}
void CBXmlUtility::saveAchievement(const string& fileName, CBAchievements* achievements)
{
    m_xmlUtility->saveAchievement(fileName, achievements);
}