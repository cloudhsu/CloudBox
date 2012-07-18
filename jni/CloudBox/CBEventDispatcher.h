/*
 *  CBEventDispatcher.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/16.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _EVENTDISPATCHER_H_
#define _EVENTDISPATCHER_H_

#include "CBSingleton.h"
#include <vector>
using namespace std;

class ITouch;
class IClick;

class CBEventDispatcher : public CBSingleton<CBEventDispatcher>
{
private:
	vector<ITouch*> m_touchHandlers;
	vector<IClick*> m_clickHandlers;
public:
	CBEventDispatcher();
	~CBEventDispatcher();
	
	void clear();
	void registerEventHandler(ITouch* touchHandler);
	void registerEventHandler(IClick* clickHandler);
	
	void onClick(float x, float y);
	
	void touchBegan(float x, float y);
	void touchMoved(float x, float y);
	void touchEnded(float x, float y);
};

#define SEventDispatcher CBEventDispatcher::instance()

#endif