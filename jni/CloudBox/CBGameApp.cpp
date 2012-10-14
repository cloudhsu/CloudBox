//
//  GameApp.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#include "CBGameApp.h"
#include "CBOpenGL.h"
#include "CBLogoScene.h"
#include "CBCore.h"
#include "CBEnvironment.h"
#include "CBTexturePool.h"
#include "CBTimerManager.h"
#include "CBEventProcessor.h"
#ifdef __CBIOS__
#include "HelloScene.h"
#else
#include "../HelloScene.h"
#endif

CBGameApp::CBGameApp()
{
	// construct
	m_isinitialed = false;
}

CBGameApp::~CBGameApp()
{
	// Deconstruct
}

void CBGameApp::setScreen(GLint screenWidth,GLint screenHeight)
{
	CBEnvironment::setScreenWidth(screenWidth);
	CBEnvironment::setScreenHeight(screenHeight);
}

void CBGameApp::initialize()
{
	SOpenGL.initialize2D();
	if(!m_isinitialed)
	{
		m_isinitialed = true;
		start();
	}
}

void CBGameApp::start()
{
	if(SKIP_LOGO)
	{
		DebugLog("GameApp.start() HelloScene\n");
		runWithScene(new HelloScene());
	}
	else
	{
		DebugLog("GameApp.start() CBLogoScene\n");
		runWithScene(new CBLogoScene());
	}

}

void CBGameApp::mainLoop(double time)
{
	SEventProcessor.onUpdate(time);
	SEventProcessor.onDraw();
}

void CBGameApp::runWithScene(CBScene* scene)
{
	SDirector.runNextScene(scene);
}

void CBGameApp::destory()
{
}

void CBGameApp::reloadTexture()
{
    STexturePool.reloadTexture();
}

void CBGameApp::initialTimer(double oldTime)
{
	STimerManager.initialTimer(oldTime);
}

void CBGameApp::retinaDisplay()
{
	CBEnvironment::setRetina(true);
}

void CBGameApp::touchBegan(float x, float y)
{
    SEventProcessor.onTouchBegan(x, y);
}
void CBGameApp::touchMoved(float x, float y)
{
    SEventProcessor.onTouchMoved(x, y);
}
void CBGameApp::touchEnded(float x, float y)
{
    SEventProcessor.onTouchEnded(x, y);
}

void CBGameApp::onSersorChanged(float x, float y, float z)
{
    SEventProcessor.onSersorChanged(x, y, z);
}

void CBGameApp::applicationDidEnterBackground()
{
    SEventProcessor.onApplicationDidEnterBackground();
}
void CBGameApp::applicationWillEnterForeground()
{
    SEventProcessor.onApplicationWillEnterForeground();
}
