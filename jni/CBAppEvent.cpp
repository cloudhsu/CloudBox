/*
 *  CBAppEvent.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAppEvent.h"
#ifdef __CBIOS__
#include "CBLibrary.h"
#else
#include "CloudBox/CBLibrary.h"
#endif

void CBAppEvent::applicationDidEnterBackground()
{
	DebugLog("CBAppEvent::applicationDidEnterBackground\n");
	// system event for enter background
}
void CBAppEvent::applicationWillEnterForeground()
{
	DebugLog("CBAppEvent::applicationWillEnterForeground\n");
	// system event for enter foreground
}
