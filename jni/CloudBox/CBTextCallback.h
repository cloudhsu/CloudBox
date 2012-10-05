/*
 *  CBTextCallback.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/19.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBTEXTCBCALLBACK_H_
#define _CBTEXTCBCALLBACK_H_

#include <iostream>
#include "CBCallBack.h"
using namespace std;

class CBTextCallback : public CBCallback
{
private:
	CBDelegate<void(const string&, const float)>* m_delegate;
	string m_text;
	float m_size;
public:
	CBTextCallback();
	~CBTextCallback();
	
	void onCallback();
	void invoke(const string& text, const float size);
	
	template <typename T>
	void addCallbackEvent(T* target, void (T::*Func)(const string&, const float))
	{
		m_delegate = new CBDelegate<void(const string&, const float)>();
		m_delegate->initDelegate<T>(target,Func);
	}
};

#endif