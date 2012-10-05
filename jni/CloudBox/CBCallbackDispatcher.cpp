/*
 *  CBCallbackDispatcher.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/19.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBCallbackDispatcher.h"
#include "CBCallback.h"

CBCallbackDispatcher::CBCallbackDispatcher()
{
}

CBCallbackDispatcher::~CBCallbackDispatcher()
{
	clear();
}

void CBCallbackDispatcher::clear()
{
	std::queue<CBCallback*> empty;
	std::swap( m_runOnceCall, empty );

}
void CBCallbackDispatcher::registerRunOnce(CBCallback* callback)
{
	m_runOnceCall.push(callback);
}

void CBCallbackDispatcher::notify()
{
	while(!m_runOnceCall.empty())
	{
		CBCallback* callback = m_runOnceCall.front();
		callback->onCallback();
		m_runOnceCall.pop();
	}
}