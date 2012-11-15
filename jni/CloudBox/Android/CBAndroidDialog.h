/*
 *  CBAndroidDialog.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/11.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBANDROIDDIALOG__
#define __CBANDROIDDIALOG__

#include "CBJNI.h"
#include "../CBDialog.h"

class CBAndroidDialog : public CBDialog, public CBJNI
{
private:
	jmethodID m_showDialog;
public:
	CBAndroidDialog();
    ~CBAndroidDialog();

    void showDialog();
    void showDialog(const string& title,const string& msg);
    void showDialog(DialogType type, const string& title,const string& msg);
};


#endif
