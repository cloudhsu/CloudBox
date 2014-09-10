/*
 *  CBConvert.h
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/6/19.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#ifndef __CBCONVERT_H__
#define __CBCONVERT_H__

#include <string>
#include <sstream>

class CBConvert
{
public:
    CBConvert(void);
    ~CBConvert(void);
public:
    template<class T>
    static T toValueFromCStr(char* s)
    {
        std::stringstream stream;
        stream.str("");
        stream.clear();
        stream<<s;
        T t;
        stream >> t;
        return t;
    }
    
    template<class T>
    static std::string toString(const T& t)
    {
        std::stringstream stream;
        stream.str("");
        stream.clear();
        stream << t;
        return stream.str();
    }

    template<class T>
    static T toValue(const std::string& s)
    {
        std::stringstream stream;
        stream.str("");
        stream.clear();
        stream<<s;
        T t;
        stream >> t;
        return t;
    }
};

#endif