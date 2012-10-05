/*
 *  CBAppEvent.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBAPPEVENT_H_
#define _CBAPPEVENT_H_

#include "CBSingleton.h"

class CBAppEvent : public CBSingleton<CBAppEvent>
{
private:
public:
	void applicationDidEnterBackground();
	void applicationWillEnterForeground();
};

#define SAppEvent CBAppEvent::instance()

#endif
