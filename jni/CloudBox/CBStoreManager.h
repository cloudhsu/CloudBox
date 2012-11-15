/*
 *  CBStoreManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBSTOREMANAGER_H__
#define __CBSTOREMANAGER_H__

#include "CBSingleton.h"
#include <string>
using namespace std;

class CBStoreBase;
class CBStoreEvent;

enum IAPStatus
{
    IAPIdel = 0,
    IAPPurchasing = 1,
    IAPRestoring = 2
};

class CBStoreManager : public CBSingleton<CBStoreManager>
{
private:
    string m_buyProductTag;
    CBStoreBase* m_store;
    CBStoreEvent* m_storeEvent;
    IAPStatus m_status;
public:
    CBStoreManager();
    ~CBStoreManager();
    
    void enableSimulateStore();
    bool isBusy();
    void buy(const string& buyProductTag);
    bool isCanBuy();
    void initialStore();
    void releaseStore();
    void restoreCompletedTransactions();
    
    void registerStoreEvent(CBStoreEvent* event);
    
    void requestFail(string& msg);
    void requestFinished();
    
    // transaction event
    void completeTransaction(string& buyProductTag);
    void failedTransaction(string& msg, int errorCode);
    void restoreTransaction(string& buyProductTag);
    void purchasingTransaction(string& buyProductTag);
    void restoreCompletedTransactionsFinished();
    void restoreCompletedTransactionsFailed(string& msg, int errorCode);
};

#define SStoreManager CBStoreManager::instance()

#endif
