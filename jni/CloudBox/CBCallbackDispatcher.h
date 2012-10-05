/*
 *  CBCallbackDispatcher.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/19.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CALLBACKDISPATCHER_H_
#define _CALLBACKDISPATCHER_H_

#include "CBSingleton.h"
#include <queue>
using namespace std;

class CBCallback;

class CBCallbackDispatcher : public CBSingleton<CBCallbackDispatcher>
{
private:
	queue<CBCallback*> m_runOnceCall;
public:
	CBCallbackDispatcher();
	~CBCallbackDispatcher();
	
	void clear();
	void registerRunOnce(CBCallback* callback);
	
	void notify();
};

#define SCallbackDispatcher CBCallbackDispatcher::instance()

#endif