/*
 *  CBAndroidStoreWrapper.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/18.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBANDROIDSTOREWRAPPER_H_
#define _CBANDROIDSTOREWRAPPER_H_

#include "CBJNI.h"
#include "CBStoreBase.h"
#include <string>
using namespace std;

class CBAndroidStoreWrapper : public CBStoreBase, public CBJNI
{
private:
	jmethodID m_restoreCompletedTransactions;
	jmethodID m_buy;
	jmethodID m_isCanBuy;
	jmethodID m_initialStore;
	jmethodID m_releaseStore;
public:
	CBAndroidStoreWrapper();
    ~CBAndroidStoreWrapper();
    
    void restoreCompletedTransactions();
    void buy(const string& buyProductTag);
    bool isCanBuy();
    void initialStore();
    void releaseStore();
};

#endif
