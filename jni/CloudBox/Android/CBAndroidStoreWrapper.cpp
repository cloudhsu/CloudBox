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
	g_env->CallStaticVoidMethod(m_mainClass, m_buy, data);
	g_env->DeleteLocalRef(data);
	DebugLog("CBAndroidStoreWrapper buy succeed.\n");
}

bool CBAndroidStoreWrapper::isCanBuy()
{
	jboolean canBuy = g_env->CallStaticBooleanMethod(m_mainClass, m_isCanBuy);
	DebugLog("CBAndroidStoreWrapper isCanBuy succeed.\n");
	return canBuy;
}

void CBAndroidStoreWrapper::initialStore()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_initialStore);
	DebugLog("CBAndroidStoreWrapper initialStore succeed.\n");
}

void CBAndroidStoreWrapper::releaseStore()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_releaseStore);
	DebugLog("CBAndroidStoreWrapper releaseStore succeed.\n");
}

void CBAndroidStoreWrapper::restoreCompletedTransactions()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_restoreCompletedTransactions);
	DebugLog("CBAndroidStoreWrapper restoreCompletedTransactions succeed.\n");
}
