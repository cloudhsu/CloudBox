/*
 *  CBFileUtility.cpp
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/6/19.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#include "CBFileUtility.h"
#include <fstream>
#ifdef __CBIOS__
#include "CBiOSUtility.h"
#define SystemPath(name) CBiOSUtility::getSystemPath(name)
#else
#define SystemPath(name) (name)
#endif

CBFileUtility::CBFileUtility(void)
{
}

CBFileUtility::~CBFileUtility(void)
{
}

string CBFileUtility::getSystemPath(const string& fileName)
{
    string fullName = SystemPath(fileName);
    return fullName;
}

bool CBFileUtility::checkFileExist(string fileName)
{
    bool flag = false;
    fstream fin;
    fin.open(fileName.c_str(),ios::in);
    if( fin.is_open() )
    {
        flag=true;
    }
    fin.close();
    return flag;
}