/*
 *  CBDialog.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/13.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBDialog.h"
#include "CBLibrary.h"

CBDialog::CBDialog():m_dialogClick(NULL),m_result(DialogResultNone)
{
}

CBDialog::~CBDialog()
{
    CBDELETE(m_dialogClick);
}

DialogResult CBDialog::getDialogResult()
{
    return m_result;
}

void CBDialog::alertEvent(DialogResult result, int clickIndex)
{
    m_result = result;
    if(m_dialogClick)
		m_dialogClick->invoke(result,clickIndex);
}

//void CBDialog::showDialog()
//{
//    
//}
//
//void CBDialog::showDialog(const string& title,const string& msg)
//{
//    showDialog(DialogTypeOK, title, msg);
//}
//
//void CBDialog::showDialog(DialogType type, const string& title,const string& msg)
//{
//    m_dialog->showDialog(type, title, msg);
//}