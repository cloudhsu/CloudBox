/*
 *  CBWin32Dialog.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/25.
 *  Copyright 2013 Orz. All rights reserved.
 *
 */

#ifndef __CBWIN32DIALOG__
#define __CBWIN32DIALOG__

#include "../CBDialog.h"

class CBWin32Dialog : public CBDialog
{
private:
public:
	CBWin32Dialog();
    ~CBWin32Dialog();

    void showDialog();
    void showDialog(const string& title,const string& msg);
    void showDialog(DialogType type, const string& title,const string& msg);
};


#endif
