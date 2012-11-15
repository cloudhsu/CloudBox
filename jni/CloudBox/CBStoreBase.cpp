/*
 *  CBStoreBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBStoreBase.h"
#include "CBStoreManager.h"
#include "CBDialog.h"
#include "CBSystemDialog.h"

CBSimulateStore::CBSimulateStore()
{
    
}
CBSimulateStore::~CBSimulateStore()
{
    
}
void CBSimulateStore::buy(const string& buyProductTag)
{
    m_buyProductID = buyProductTag;
    CBDialog* dialog = new CBSystemDialog();
    dialog->addAlertEvent(this, &CBSimulateStore::onAlertClick);
    dialog->showDialog(DialogTypeOKCancel,"Confirm", "Do you want to buy it?");
}

void CBSimulateStore::onAlertClick(DialogResult result, int clickIndex)
{
    if(DialogResultOK == result)
    {
        SStoreManager.completeTransaction(const_cast<string&>(m_buyProductID));
    }
}

bool CBSimulateStore::isCanBuy()
{
    return true;
}

void CBSimulateStore::initialStore()
{
    // nothing to do
}

void CBSimulateStore::releaseStore()
{
    // nothing to do
}

void CBSimulateStore::restoreCompletedTransactions()
{
    
}