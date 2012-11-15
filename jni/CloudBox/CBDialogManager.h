/*
 *  CBDialogManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/14.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBDIALOGMANAGER__
#define __CBDIALOGMANAGER__

#include "CBSingleton.h"
#include "CBDialogEnum.h"

class CBDialog;

class CBDialogManager : public CBSingleton<CBDialogManager>
{
private:
	CBDialog* m_dialog;
public:
    bool isDialogLockScreen();
	void alertEvent(DialogResult result, int clickIndex);
    
    void registerDialog(CBDialog* dialog);
};

#define SDialogManager CBDialogManager::instance()

#endif
