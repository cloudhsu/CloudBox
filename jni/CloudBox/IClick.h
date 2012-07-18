/*
 *  IClick.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/6.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _ICLICK_H_
#define _ICLICK_H_

#include "IEvent.h"
#include "CBEvent.h"


class IClick : public IEvent
{
protected:
	bool m_isRegister;
	void registerClickEvent()
	{
		if(!m_isRegister)
		{
			m_isRegister = true;
			SEventDispatcher.registerEventHandler(this);
		}
	}
public:
	IClick() : IEvent()
	{
		m_isRegister = false;
	}
	virtual ~IClick() {}
	virtual void onClick(float x, float y) = 0;
	
	template <typename T>
	void addClickEvent(T* instance, void (T::*Func)(CBView*, CBEvent*))
	{
		//m_delegate = new TDelegate<T>(target,Func);
		m_delegate = new CBDelegate<void(CBView*, CBEvent*)>();
		m_delegate->initDelegate<T>(instance,Func);
		registerClickEvent();
	}
};

#endif