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

CBStoreSimulator::CBStoreSimulator()
{
    
}
CBStoreSimulator::~CBStoreSimulator()
{
    
}
void CBStoreSimulator::buy(const string& buyProductTag)
{
    m_buyProductID = buyProductTag;
    CBDialog* dialog = new CBSystemDialog();
    dialog->addAlertEvent(this, &CBStoreSimulator::onAlertClick);
    dialog->showDialog(DialogTypeOKCancel,"Confirm", "Do you want to buy it?");
}

void CBStoreSimulator::onAlertClick(DialogResult result, int clickIndex)
{
    if(DialogResultOK == result)
    {
        SStoreManager.completeTransaction(const_cast<string&>(m_buyProductID));
    }
}

bool CBStoreSimulator::isCanBuy()
{
    return true;
}

void CBStoreSimulator::initialStore()
{
    // nothing to do
}

void CBStoreSimulator::releaseStore()
{
    // nothing to do
}

void CBStoreSimulator::restoreCompletedTransactions()
{
    
}