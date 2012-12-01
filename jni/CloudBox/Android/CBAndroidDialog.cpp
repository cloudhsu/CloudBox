/*
 *  CBAndroidDialog.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/11.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "def.h"
#include "CBAndroidDialog.h"
//#include "../CBAudioManager.h"
#include "../CBAudioEngine.h"

CBAndroidDialog::CBAndroidDialog()
{
	initialJNIClass("com/clouddevelop/cloudbox/CBUtility");
	m_showDialog = g_env->GetStaticMethodID(m_mainClass, "showMessageBox", "(ILjava/lang/String;Ljava/lang/String;)V");
}
CBAndroidDialog::~CBAndroidDialog()
{

}

void CBAndroidDialog::showDialog()
{
    showDialog(DialogTypeClose, "Test", "No message");
}

void CBAndroidDialog::showDialog(const string& title,const string& msg)
{
    showDialog(DialogTypeClose, title, msg);
}

void CBAndroidDialog::showDialog(DialogType type, const string& title,const string& msg)
{
	jstring data1 = g_env->NewStringUTF(title.c_str());
	jstring data2 = g_env->NewStringUTF(msg.c_str());
	g_env->CallStaticVoidMethod(m_mainClass, m_showDialog, (jint)type, data1, data2);
	g_env->DeleteLocalRef(data1);
	g_env->DeleteLocalRef(data2);
	DebugLog("CBAndroidDialog show dialog succeed.\n");
}
