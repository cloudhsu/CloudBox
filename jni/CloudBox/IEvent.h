/*
 *  IEvent.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/17.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _IEVENT_H_
#define _IEVENT_H_

#include "CBDelegate.h"
#include "CBEventDispatcher.h"
#include "CBEvent.h"
#include "CBLibrary.h"

class CBView;
class CBEvent;

class IEvent
{
protected:
	CBDelegate<void(CBView*,CBEvent*)>* m_delegate;
	
	void onTrigger()
	{
		if(m_delegate)
			m_delegate->invoke(NULL,NULL);
	}
	
	void onTrigger(CBView* sender, CBEvent* e)
	{
		if(m_delegate)
			m_delegate->invoke(sender, e);
		if(e)
			delete e;
	}
public:
	IEvent()
	{
		m_delegate = NULL;
	}
	virtual ~IEvent()
	{
		CBDELETE(m_delegate);
	}
};	

#endif