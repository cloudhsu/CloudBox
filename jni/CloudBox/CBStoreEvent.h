/*
 *  CBStoreEvent.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBSTOREEVENT_H__
#define __CBSTOREEVENT_H__

#include <string>
using namespace std;

class CBStoreEvent
{
public:
    CBStoreEvent(){}
    virtual ~CBStoreEvent(){}
    
    virtual void completeTransaction(string& buyProductTag) = 0;
    virtual void failedTransaction(string& buyProductTag, int errorCode) = 0;
    virtual void restoreTransaction(string& buyProductTag) = 0;
    virtual void purchasingTransaction(string& buyProductTag) = 0;
};

class CBDefaultAlertEvent : public CBStoreEvent
{
public:
    CBDefaultAlertEvent();
    virtual ~CBDefaultAlertEvent();
    
    virtual void completeTransaction(string& buyProductTag);
    virtual void restoreTransaction(string& buyProductTag);
    void failedTransaction(string& msg, int errorCode);
    void purchasingTransaction(string& buyProductTag);
};

#endif
