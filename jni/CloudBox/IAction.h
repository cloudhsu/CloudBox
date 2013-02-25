/*
 *  IAction.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _IACTION_H_
#define _IACTION_H_

#include "IEvent.h"
#include "CBCmd.h"
#include "CBView.h"

#define NOT_EXIST -999

class IAction
{
protected:
	int m_id;
	CBView* m_target;
	CBDelegate<void(CBView*)>* m_delegate;
	CBDelegate<void(CBView*)>* m_finish;
	
	void onTrigger()
	{
		if(m_delegate)
			m_delegate->invoke(m_target);
	}
	
	void onFinish()
	{
		if(m_finish)
			m_finish->invoke(m_target);
	}
public:
	IAction() : m_delegate(NULL), m_finish(NULL), m_id(NOT_EXIST)
	{
	}
	virtual ~IAction()
	{
		CBDELETE(m_delegate);
		CBDELETE(m_finish);
	}
	
	template <typename T>
	void addTriggerEvent(T* instance, void (T::*Func)(CBView*))
	{
		m_delegate = new CBDelegate<void(CBView*)>();
		m_delegate->initDelegate<T>(instance,Func);
	}
	
	template <typename T>
	void addFinishEvent(T* instance, void (T::*Func)(CBView*))
	{
		m_finish = new CBDelegate<void(CBView*)>();
		m_finish->initDelegate<T>(instance,Func);
	}
	
	inline int getID() { return m_id; }
	inline void setID(int actionID) { m_id = actionID;}
};

#endif