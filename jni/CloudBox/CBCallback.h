/*
 *  CBCallback.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/9.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBCALLBACK_H_
#define _CBCALLBACK_H_

#include "CBDelegate.h"
#include "CBView.h"

class CBCallback
{
protected:
	int m_id;
public:
	CBCallback()
	{
	}
	virtual ~CBCallback()
	{
	}
	
	inline int getID() { return m_id; }
	inline void setID(int actionID) { m_id = actionID;}
	
	virtual void onCallback() = 0;
	//virtual void invoke() = 0;
};

#endif