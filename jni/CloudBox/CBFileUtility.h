/*
 *  CBFileUtility.h
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/6/19.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#ifndef __CBFILEUTILITY_H__
#define __CBFILEUTILITY_H__

#include <string>
using namespace std;

class CBFileUtility
{
public:
    CBFileUtility(void);
    ~CBFileUtility(void);

    static string getSystemPath(const string& fileName);
    //static string getResourcePath();
    static bool checkFileExist(string fileName);
};

#endif