/*
 *  CBAndroidStoreWrapper.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/18.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAndroidStoreWrapper.h"
#include "../CBLibrary.h"
#include "def.h"

CBAndroidStoreWrapper::CBAndroidStoreWrapper()
{
	initialJNIClass("com/clouddevelop/cloudbox/CBUtility");
	m_initialStore = g_env->GetStaticMethodID(m_mainClass, "initialStore", "()V");
	m_releaseStore = g_env->GetStaticMethodID(m_mainClass, "releaseStore", "()V");
	m_buy = g_env->GetStaticMethodID(m_mainClass, "buy", "(Ljava/lang/String;)V");
	m_restoreCompletedTransactions = g_env->GetStaticMethodID(m_mainClass, "restoreCompletedTransactions", "()V");
	m_isCanBuy = g_env->GetStaticMethodID(m_mainClass, "isCanBuy", "()Z");
}

CBAndroidStoreWrapper::~CBAndroidStoreWrapper()
{
    
}

void CBAndroidStoreWrapper::buy(const string& buyProductTag)
{
	jstring data = g_env->NewStringUTF(buyProductTag.c_str());
	g_env->CallObjectMethod(m_mainObject, m_buy, data);
	g_env->DeleteLocalRef(data);
}

bool CBAndroidStoreWrapper::isCanBuy()
{
	jboolean canBuy = g_env->CallBooleanMethod(m_mainObject, m_isCanBuy);
	return canBuy;
}

void CBAndroidStoreWrapper::initialStore()
{
	g_env->CallVoidMethod(m_mainObject, m_initialStore);
}

void CBAndroidStoreWrapper::releaseStore()
{
	g_env->CallVoidMethod(m_mainObject, m_releaseStore);
}

void CBAndroidStoreWrapper::restoreCompletedTransactions()
{
	g_env->CallVoidMethod(m_mainObject, m_restoreCompletedTransactions);
}
