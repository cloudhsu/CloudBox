/*
 *  CBSystemDialog.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/13.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBSYSTEMDIALOG__
#define __CBSYSTEMDIALOG__

#include "CBDialog.h"
#include "CBDialogEnum.h"
#include <string>
using namespace std;

class CBDialog;

class CBSystemDialog : public CBDialog
{
private:
    CBDialog* m_dialog;
public:
    CBSystemDialog();
    virtual ~CBSystemDialog();
    
    void showDialog();
    void showDialog(const string& title,const string& msg);
    virtual void showDialog(DialogType type, const string& title,const string& msg);
};

class CBDialogNone : public CBDialog
{
private:
public:
    CBDialogNone(){}
    ~CBDialogNone(){}
    
    void showDialog()
    {
        m_result = DialogResultNone;
    }
    void showDialog(const string& title,const string& msg)
    {
        showDialog();
    }
    void showDialog(DialogType type, const string& title,const string& msg)
    {
        showDialog();
    }
};


#endif
