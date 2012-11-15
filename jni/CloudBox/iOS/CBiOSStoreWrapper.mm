/*
 *  CBiOSStoreWrapper.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBiOSStoreManager.h"
#include "CBiOSStoreWrapper.h"

CBiOSStoreWrapper::CBiOSStoreWrapper()
{
    
}

CBiOSStoreWrapper::~CBiOSStoreWrapper()
{
    
}

void CBiOSStoreWrapper::buy(const string& buyProductTag)
{
    NSString *name = [[NSString alloc] initWithUTF8String: buyProductTag.c_str()];
    [[CBiOSStoreManager sharedInstance]buy:name];
}

bool CBiOSStoreWrapper::isCanBuy()
{
    return [[CBiOSStoreManager sharedInstance]CanMakePay];
}

void CBiOSStoreWrapper::initialStore()
{
    [[CBiOSStoreManager sharedInstance]initialStore];
}

void CBiOSStoreWrapper::releaseStore()
{
    [[CBiOSStoreManager sharedInstance]releaseStore];
}

void CBiOSStoreWrapper::restoreCompletedTransactions()
{
    [[CBiOSStoreManager sharedInstance]restoreCompletedTransactions];
}