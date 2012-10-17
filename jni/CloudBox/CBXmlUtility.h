/*
 *  CBXmlUtility.h
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/10/15.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#ifndef __CBXMLUTILITY_H__
#define __CBXMLUTILITY_H__

#include "CBXmlBase.h"

class CBXmlUtility : public CBXmlBase
{
private:
    CBXmlBase* m_xmlUtility;
public:
    CBXmlUtility(void);
    ~CBXmlUtility(void);

    void saveToXML(map<string,string>& data,const string& fileName);
    map<string,string> loadFromXML(string fileName);
};

#endif