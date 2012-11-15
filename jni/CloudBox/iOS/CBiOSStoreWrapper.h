/*
 *  CBiOSStoreWrapper.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBIOSSTOREWRAPPER_H_
#define _CBIOSSTOREWRAPPER_H_

#include "CBStoreBase.h"
#include <string>
using namespace std;

class CBiOSStoreWrapper : public CBStoreBase
{
public:
    CBiOSStoreWrapper();
    ~CBiOSStoreWrapper();
    
    void restoreCompletedTransactions();
    void buy(const string& buyProductTag);
    bool isCanBuy();
    void initialStore();
    void releaseStore();
};

#endif