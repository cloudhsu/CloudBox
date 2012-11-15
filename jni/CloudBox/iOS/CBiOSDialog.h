/*
 *  CBiOSDialog.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/14.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBIOSDIALOG__
#define __CBIOSDIALOG__

#include "CBDialog.h"

class CBiOSDialog : public CBDialog
{
public:
    CBiOSDialog(){}
    ~CBiOSDialog(){}
    void showDialog();
    void showDialog(const string& title,const string& msg);
    void showDialog(DialogType type, const string& title,const string& msg);
};


#endif
