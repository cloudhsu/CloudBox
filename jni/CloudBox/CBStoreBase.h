/*
 *  CBStoreBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBSTOREBASE_H_
#define _CBSTOREBASE_H_

#include "CBDialog.h"
#include <string>
using namespace std;

class CBStoreBase
{
public:
    CBStoreBase(){}
    virtual~CBStoreBase(){}
    
    virtual void initialStore() = 0;
    virtual void releaseStore() = 0;
    
    virtual void buy(const string& buyProductTag) = 0;
    virtual void restoreCompletedTransactions() = 0;
    virtual bool isCanBuy() = 0;
};

class CBStoreSimulator : public CBStoreBase
{
private:
    string m_buyProductID;
public:
    CBStoreSimulator();
    ~CBStoreSimulator();
    
    void onAlertClick(DialogResult result, int clickIndex);
    void buy(const string& buyProductTag);
    void restoreCompletedTransactions();
    bool isCanBuy();
    void initialStore();
    void releaseStore();
};

#endif
