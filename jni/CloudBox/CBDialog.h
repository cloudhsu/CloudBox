/*
 *  CBDialog.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/13.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBDIALOG__
#define __CBDIALOG__

#include "CBDelegate.h"
#include "CBDialogEnum.h"
#include <string>
using namespace std;

class CBDialogBase;

class CBDialog
{
protected:
    DialogResult m_result;
    CBDelegate<void(DialogResult,int)>* m_dialogClick;
public:
    CBDialog();
    virtual ~CBDialog();
    
    DialogResult getDialogResult();
    
    void alertEvent(DialogResult result, int clickIndex);
    
    template <typename T>
	void addAlertEvent(T* instance, void (T::*Func)(DialogResult,int))
	{
		m_dialogClick = new CBDelegate<void(DialogResult,int)>();
		m_dialogClick->initDelegate<T>(instance,Func);
	}
    
    virtual void showDialog() = 0;
    virtual void showDialog(const string& title,const string& msg) = 0;
    virtual void showDialog(DialogType type, const string& title,const string& msg) = 0;
};

class CBDialogSimulator : public CBDialog
{
public:
	CBDialogSimulator() {}
	~CBDialogSimulator() {}
	void showDialog() {}
	void showDialog(const string& title,const string& msg) {}
	void showDialog(DialogType type, const string& title,const string& msg) {}
};


#endif
