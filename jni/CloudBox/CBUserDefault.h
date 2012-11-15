/*
 *  CBUserDefault.h
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/10/15.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#ifndef __CBUSERDEFAULT_H__
#define __CBUSERDEFAULT_H__

#include "CBSingleton.h"
#include "CBConvert.h"
#include <string>
#include <map>
using namespace std;

class CBXmlUtility;

class CBUserDefault  : public CBSingleton<CBUserDefault>
{
private:
    static const string UserDefaultName;
    CBXmlUtility* m_xmlUtility;
    map<string,string> m_data;
public:
    CBUserDefault(void);
    ~CBUserDefault(void);
    
    bool isUserDefaultExist();

    template<class T>
    void setValue(const string& key, T value)
    {
        m_data[key] = CBConvert::toString<T>(value);
    }

    template<class T>
    T getValue(const string& key)
    {
        T value = CBConvert::toValue<T>(m_data[key]);
        return value;
    }
    
    template<class T>
    T getValue(const string& key,const T defaultValue)
    {
        T value = defaultValue;
        if( !(m_data.find(key) == m_data.end()) )
        {
            value = CBConvert::toValue<T>(m_data[key]);
        }
        return value;
    }

    void load();
    void save();
};

#define SUserDefault CBUserDefault::instance()

#endif