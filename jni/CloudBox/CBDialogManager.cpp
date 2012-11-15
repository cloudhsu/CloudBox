/*
 *  CBDialogManager.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/14.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBDialog.h"
#include "CBDialogManager.h"
#include "CBLibrary.h"
#include "CBAudioEngine.h"

bool CBDialogManager::isDialogLockScreen()
{
    bool isLock = false;
    if(m_dialog != NULL)
        isLock = true;
    return isLock;
}

void CBDialogManager::alertEvent(DialogResult result, int clickIndex)
{
	DebugLog("CBDialogManager::onAlertEvent 1\n");
    if(m_dialog != NULL)
    {
        m_dialog->alertEvent(result, clickIndex);
        DebugLog("CBDialogManager::onAlertEvent 2\n");
        DebugLog("CBDialogManager::onAlertEvent 3\n");
#ifdef __CBIOS__
#else
        //SAudioEngine.playMusic();
#endif
    }
    else
    {
        DebugLog("CBDialogManager::alertEvent got NULL, please check dose dialog register?");
    }
}

void CBDialogManager::registerDialog(CBDialog* dialog)
{
	DELETE(m_dialog);
    m_dialog = dialog;
}
