/*
 *  CBSystemDialog.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/13.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBDialogManager.h"
#include "CBSystemDialog.h"
#include "CBFactoryMethod.h"

CBSystemDialog::CBSystemDialog()
{
    m_dialog = CBFactoryMethod::createSystemDialog();
}

CBSystemDialog::~CBSystemDialog()
{
    
}

void CBSystemDialog::showDialog()
{
    showDialog(DialogTypeClose, "Test", "No message");
}

void CBSystemDialog::showDialog(const string& title,const string& msg)
{
    showDialog(DialogTypeClose, title, msg);
}

void CBSystemDialog::showDialog(DialogType type, const string& title,const string& msg)
{
    SDialogManager.registerDialog(this);
    m_dialog->showDialog(type, title, msg);
}
