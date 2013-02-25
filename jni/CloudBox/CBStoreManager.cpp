/*
 *  CBStoreManager.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLibrary.h"
#include "CBStoreEvent.h"
#include "CBStoreManager.h"
#include "CBStoreBase.h"
#include "CBDialog.h"
#include "CBSystemDialog.h"
#include "CBFactoryMethod.h"

CBStoreManager::CBStoreManager()
:m_storeEvent(NULL),m_status(IAPIdel),m_store(NULL)
{
    m_store = CBFactoryMethod::createStore();
}

CBStoreManager::~CBStoreManager()
{
    CBDELETE(m_store);
    CBDELETE(m_storeEvent);
}

bool CBStoreManager::isBusy()
{
    return (m_status > IAPIdel);
}

void CBStoreManager::enableSimulateStore()
{
    CBDELETE(m_store);
    m_store = CBFactoryMethod::createSimulateStore();
    CBDialog* dialog = new CBSystemDialog();
    dialog->showDialog(DialogTypeClose,"Warring", "Simulate Store Mode!");
}

void CBStoreManager::buy(const string& buyProductTag)
{
    if(isCanBuy())
    {
        DebugLog("It will buy %s\n",buyProductTag.c_str());
        m_status = IAPPurchasing;
        m_store->buy(buyProductTag);
    }
    else
    {
        DebugLog("In-App Purchase is disable!\n");
        CBDialog* dialog = new CBSystemDialog();
        dialog->showDialog(DialogTypeClose,"Warring", "Your In-App Purchase is disable!");
    }
}
bool CBStoreManager::isCanBuy()
{
    return m_store->isCanBuy();
}
void CBStoreManager::initialStore()
{
	DebugLog("Initial Store.\n");
    m_store->initialStore();
}
void CBStoreManager::releaseStore()
{
    m_store->releaseStore();
}

void CBStoreManager::restoreCompletedTransactions()
{
    m_status = IAPRestoring;
    m_store->restoreCompletedTransactions();
}

void CBStoreManager::registerStoreEvent(CBStoreEvent* event)
{
    CBDELETE(m_storeEvent);
    m_storeEvent = event;
}

void CBStoreManager::requestFail(string& msg)
{
    DebugLog("In-App Purchase Request fail:%s\n",msg.c_str());
    m_status = IAPIdel;
    CBDialog* dialog = new CBSystemDialog();
    dialog->showDialog(DialogTypeClose,"Fail", msg);
}

void CBStoreManager::requestFinished()
{
    m_status = IAPIdel;
}

// transaction event
void CBStoreManager::completeTransaction(string& buyProductTag)
{
    DebugLog("In-App Purchase Complete Transaction:%s\n",buyProductTag.c_str());
    if(m_storeEvent)
        m_storeEvent->completeTransaction(buyProductTag);
}
void CBStoreManager::failedTransaction(string& msg, int errorCode)
{
    DebugLog("In-App Purchase Failed Transaction:%s, ErrorCode:%d\n",msg.c_str(), errorCode);
    if(m_storeEvent)
        m_storeEvent->failedTransaction(msg, errorCode);
}
void CBStoreManager::restoreTransaction(string& buyProductTag)
{
    DebugLog("In-App Purchase Restore Transaction:%s\n",buyProductTag.c_str());
    if(m_storeEvent)
        m_storeEvent->restoreTransaction(buyProductTag);
}
void CBStoreManager::purchasingTransaction(string& buyProductTag)
{
    DebugLog("In-App Purchase Purchasing Transaction:%s\n",buyProductTag.c_str());
    if(m_storeEvent)
        m_storeEvent->purchasingTransaction(buyProductTag);
}
void CBStoreManager::restoreCompletedTransactionsFinished()
{
    DebugLog("Your all transactions restored.\n");
    m_status = IAPIdel;
    CBDialog* dialog = new CBSystemDialog();
    dialog->showDialog(DialogTypeClose,"Succeed", "Your all completed transactions restore finished.");
}

void CBStoreManager::restoreCompletedTransactionsFailed(string& msg, int errorCode)
{
    DebugLog("In-App Purchase Restore failed:%s, error code:%d\n",msg.c_str(), errorCode);
    m_status = IAPIdel;
    CBDialog* dialog = new CBSystemDialog();
    dialog->showDialog(DialogTypeClose,"Fail", msg);
}
