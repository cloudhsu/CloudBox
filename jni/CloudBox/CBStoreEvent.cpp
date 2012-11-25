/*
 *  CBStoreEvent.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/3.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLibrary.h"
#include "CBStoreEvent.h"
#include "CBDialog.h"
#include "CBSystemDialog.h"

CBDefaultAlertEvent::CBDefaultAlertEvent()
{
    
}
CBDefaultAlertEvent::~CBDefaultAlertEvent()
{
    
}

void CBDefaultAlertEvent::completeTransaction(string& buyProductTag)
{
    CBDialog* dialog = new CBSystemDialog();
    dialog->showDialog(DialogTypeClose,"", "Transaction completed.");
}
void CBDefaultAlertEvent::failedTransaction(string& msg, int errorCode)
{
    CBDialog* dialog = new CBSystemDialog();
    dialog->showDialog(DialogTypeClose,"Failed", msg);
}
void CBDefaultAlertEvent::restoreTransaction(string& buyProductTag)
{
}
void CBDefaultAlertEvent::purchasingTransaction(string& buyProductTag)
{
    
}