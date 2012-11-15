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
#ifdef __CBIOS__
#include "CBiOSDialog.h"
#else
#include "Android/CBAndroidDialog.h"
#endif

CBSystemDialog::CBSystemDialog()
{
    m_dialog = NULL;
#ifdef __CBIOS__
    m_dialog = new CBiOSDialog();
#else
    m_dialog = new CBAndroidDialog();
#endif
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
