/*
 *  CBUserDefault.cpp
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/10/15.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#include "CBUserDefault.h"
#include "CBConvert.h"
#include "CBXmlUtility.h"
#include "CBUtility.h"
#include "CBLibrary.h"

const string CBUserDefault::UserDefaultName = "CloudBoxUserDefault.plist";

CBUserDefault::CBUserDefault(void)
{
    m_xmlUtility = new CBXmlUtility();
}

CBUserDefault::~CBUserDefault(void)
{
    CBDELETE(m_xmlUtility);
}

bool CBUserDefault::isUserDefaultExist()
{
    string fullName = SUtility.getDocumentPath(UserDefaultName);
    return SUtility.checkFileExist(fullName);
}

void CBUserDefault::load()
{
    m_data = m_xmlUtility->loadFromXML(UserDefaultName);
}
void CBUserDefault::save()
{
    m_xmlUtility->saveToXML(m_data,UserDefaultName);
}