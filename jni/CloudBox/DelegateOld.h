/*
 *  Delegate.h
 *  CloudBox Game Application Project
 *
 *  Created by Cloud on 2011/8/14.
 *  Copyright 2011 Orz. All rights reserved.
 *
 * old delegate, not use
 */

#ifndef _Delegate_H_
#define _Delegate_H_

#include "CBEvent.h"

class CBItem;

class Delegate2
{
public:
	virtual void invoke() = 0;
	virtual void invoke(CBItem* sender, CBEvent* e) = 0;
};

//template <typename TInstance>
//template <typename TInstance, typename TSender = CBItem, typename TEvent = IEvent>
template <typename TInstance>
class TDelegate : public Delegate2
{
private:
	TInstance* m_instance;
	typedef void (TInstance::*Func)(CBItem* sender, CBEvent* e);
	Func m_delgate;
	TDelegate(){}
public:
	TDelegate(TInstance* t,Func func)
	{
		m_instance = t;
		m_delgate = func;
	}
	~TDelegate()
	{
		m_instance = NULL;
		m_delgate = NULL;
	}
	void invoke()
	{
		invoke(NULL,NULL);
	}
	void invoke(CBItem* sender, CBEvent* e)
	{
		(m_instance->*m_delgate)(sender, e);
	}
};

//template <typename TInstance>
//class TDelegate<TInstance> : public Delegate
//{
//private:
//	TInstance* m_instance;
//	typedef void (TInstance::*Func)();
//	Func m_delgate;
//	TDelegate(){}
//public:
//	TDelegate(TInstance* t,Func func)
//	{
//		m_instance = t;
//		m_delgate = func;
//	}
//	~TDelegate()
//	{
//		m_instance = NULL;
//		m_delgate = NULL;
//	}
//	void invoke()
//	{
//		(m_instance->*m_delgate)();
//	}
//};

//template <typename TInstance,typename TSender = CBItem,typename TEvent = IEvent>
//class TDelegate<TInstance, TSender, TEvent> : public Delegate
//{
//private:
//	TInstance* m_instance;
//	typedef void (TInstance::*Func)(TSender* sender, TEvent* e);
//	Func m_delgate;
//	TDelegate(){}
//public:
//	TDelegate(TInstance* t,Func func)
//	{
//		m_instance = t;
//		m_delgate = func;
//	}
//	~TDelegate()
//	{
//		m_instance = NULL;
//		m_delgate = NULL;
//	}
//	void invoke(TSender* sender, TEvent* e)
//	{
//		(m_instance->*m_delgate)(sender,e);
//	}
//};

//class GenDelegate
//{
//public:	
////	template <typename T>
////	static Delegate* createDelegate(T* target, void (T::*Func)())
////	{
////		Delegate* delegate = new TDelegate<T>(target,Func);
////		return delegate;
////	}
//	
//	template <typename T, typename TSender, typename TEvent>
//	static Delegate* createDelegate(T* target, void (T::*Func)(TSender*, TEvent*))
//	{
//		Delegate* delegate = new TDelegate<T>(target,Func);
//		return delegate;
//	}
//};

#endif