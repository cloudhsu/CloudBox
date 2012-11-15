/*
 *  CBiOSDialog.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/14.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#import "CBiOSDialogView.h"
#include "CBiOSDialog.h"

void CBiOSDialog::showDialog()
{
    showDialog(DialogTypeOK, "Test", "No message");
}

void CBiOSDialog::showDialog(const string& title,const string& msg)
{
    showDialog(DialogTypeOK, title, msg);
}

void CBiOSDialog::showDialog(DialogType type, const string& title,const string& msg)
{
    CBiOSDialogView* alert = [[CBiOSDialogView alloc]initWithType:type];
    NSString* nsTitle = [NSString stringWithUTF8String:title.c_str()];
    NSString* nsMsg = [NSString stringWithUTF8String:msg.c_str()];
    
    [alert showDialog:nsTitle Message:nsMsg];
    m_result = [alert getResult];
}