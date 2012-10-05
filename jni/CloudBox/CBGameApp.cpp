//
//  GameApp.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#include "CBGameApp.h"
#include "CBOpenGL.h"
#include "CBActionManager.h"
#include "CBDirector.h"
#include "CBTimerManager.h"
#include "CBLogoScene.h"
#include "CBCore.h"
#include "CBEnvironment.h"
#include "CBTexturePool.h"
#include "CBCallbackDispatcher.h"
#include "CBAudioEngine.h"
#ifdef __CBIOS__
#include "HelloScene.h"
#include "CBAppEvent.h"
#include "CBMotion.h"
#else
#include "../HelloScene.h"
#include "../CBAppEvent.h"
#include "Extends/CBMotion.h"
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
	notify(time);
	draw();
}

void CBGameApp::runWithScene(CBScene* scene)
{
	SDirector.runNextScene(scene);
}

void CBGameApp::notify(double time)
{
	STimerManager.update(time);
	SActionManager.update();
	SDirector.notify();
	SCallbackDispatcher.notify();
}

void CBGameApp::draw()
{
	SOpenGL.beforeRender();
	SDirector.visit();
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
	//m_OldTime = oldTime;
	STimerManager.initialTimer(oldTime);
}

void CBGameApp::retinaDisplay()
{
	CBEnvironment::setRetina(true);
}

void CBGameApp::touchBegan(float x, float y)
{
	SDirector.touchBegan(x, y);
}
void CBGameApp::touchMoved(float x, float y)
{
	SDirector.touchMoved(x, y);
}
void CBGameApp::touchEnded(float x, float y)
{
	SDirector.touchEnded(x, y);
}

void CBGameApp::onSersorChanged(float x, float y, float z)
{
#ifdef CBMotionEnable
	SMotion.updateAccelerometer(x,y,z);
#endif
}

void CBGameApp::applicationDidEnterBackground()
{
	SAppEvent.applicationDidEnterBackground();
	SDirector.applicationDidEnterBackground();
	SAudioEngine.pauseMusic();
}
void CBGameApp::applicationWillEnterForeground()
{
	SAppEvent.applicationWillEnterForeground();
	SDirector.applicationWillEnterForeground();
	SAudioEngine.playMusic();
}
