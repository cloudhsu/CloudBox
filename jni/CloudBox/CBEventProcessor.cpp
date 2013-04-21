/*
 *  CBEventProcessor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/14.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBEventProcessor.h"
#include "CBAudioEngine.h"
#include "CBActionManager.h"
#include "CBDirector.h"
#include "CBTimerManager.h"
#include "CBOpenGL.h"
#include "CBDialogManager.h"
#ifdef __CBIOS__
#include "CBAppEvent.h"
#include "CBMotion.h"
#else
#include "../CBAppEvent.h"
#include "Extends/CBMotion.h"
#endif

CBEventProcessor::CBEventProcessor()
{
}

CBEventProcessor::~CBEventProcessor()
{
    
}

void CBEventProcessor::onUpdate(double time)
{
	STimerManager.update(time);
	SActionManager.update();
	SDirector.notify();
}

void CBEventProcessor::onDraw()
{
	SOpenGL.beforeRender();
	SDirector.visit();
}

void CBEventProcessor::onTouchBegan(float x, float y)
{
	SDirector.touchBegan(x, y);
}
void CBEventProcessor::onTouchMoved(float x, float y)
{
	SDirector.touchMoved(x, y);
}
void CBEventProcessor::onTouchEnded(float x, float y)
{
	SDirector.touchEnded(x, y);
}

void CBEventProcessor::onSersorChanged(float x, float y, float z)
{
#ifdef CBMotionEnable
	SMotion.updateAccelerometer(x,y,z);
#endif
}

void CBEventProcessor::onAlertEvent(DialogResult dialogResult, int buttonIndex)
{
	//DebugLog("CBEventProcessor::onAlertEvent\n");
	SDialogManager.alertEvent(dialogResult, buttonIndex);
}

void CBEventProcessor::onApplicationDidEnterBackground()
{
	SAppEvent.applicationDidEnterBackground();
	SDirector.applicationDidEnterBackground();
	SAudioEngine.pauseMusic();
}
void CBEventProcessor::onApplicationWillEnterForeground()
{
	SAppEvent.applicationWillEnterForeground();
	SDirector.applicationWillEnterForeground();
	SAudioEngine.playMusic();
}
