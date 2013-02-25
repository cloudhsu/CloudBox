/*
 *  CBWin32Dialog.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/25.
 *  Copyright 2013 Orz. All rights reserved.
 *
 */

#include "CBWin32Dialog.h"
#include <windows.h>

CBWin32Dialog::CBWin32Dialog()
{
}
CBWin32Dialog::~CBWin32Dialog()
{

}

void CBWin32Dialog::showDialog()
{
    showDialog(DialogTypeClose, "Test", "No message");
}

void CBWin32Dialog::showDialog(const string& title,const string& msg)
{
    showDialog(DialogTypeClose, title, msg);
}

void CBWin32Dialog::showDialog(DialogType type, const string& title,const string& msg)
{
    UINT dialogType = MB_OK;
    if(type == DialogTypeOK)
    {
        dialogType = MB_OK;
    }
    else if(type == DialogTypeClose)
    {
        dialogType = MB_OK;
    }
    else if(type == DialogTypeCancel)
    {
        dialogType = MB_OK;
    }
    else if(type == DialogTypeOKCancel)
    {
        dialogType = MB_OKCANCEL;
    }
    else if(type == DialogTypeYesNo)
    {
        dialogType = MB_YESNO;
    }
    MessageBoxA(NULL, msg.c_str(), title.c_str(), dialogType);
}
