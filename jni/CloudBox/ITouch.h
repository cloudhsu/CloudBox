/*
 *  ITouch.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/13.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _ITOUCH_H_
#define _ITOUCH_H_

#include "IEvent.h"
//#include "EventDispatcher.h"


class ITouch : protected IEvent
{
protected:
	bool m_isRegister;
	void registerTouchEvent()
	{
		if(!m_isRegister)
		{
			m_isRegister = true;
			SEventDispatcher.registerEventHandler(this);
		}
	}
public:
	ITouch() : IEvent()
	{
		m_isRegister = false;
	}
	virtual ~ITouch() {}
	
	virtual void touchBegan(float x, float y) = 0;
	virtual void touchMoved(float x, float y) = 0;
	virtual void touchEnded(float x, float y) = 0;
	
	template <typename T>
	void addTouchEvent(T* instance, void (T::*Func)(CBView*, CBEvent*))
	{
		//m_delegate = new TDelegate<T>(target,Func);
		m_delegate = new CBDelegate<void(CBView*, CBEvent*)>();
		m_delegate->initDelegate<T>(instance,Func);
		registerTouchEvent();
	}
};

#endif