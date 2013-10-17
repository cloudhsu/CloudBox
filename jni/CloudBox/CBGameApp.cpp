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
#include "CBStoreManager.h"
#include "CBLayout.h"
#include "CBAchievementManager.h"
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
	DebugLog("Succeed initial OpenGL.");
#ifdef __CBIOS__
    initialStore();
    initialArchiment();
#endif
	if(!m_isinitialed)
	{
		m_isinitialed = true;
		start();
	}
}

void CBGameApp::initialStore()
{
    SStoreManager.initialStore();
    DebugLog("Succeed initial Store.");
}

void CBGameApp::initialArchiment()
{
	SAchievementManager.initialAchievementSystem();
	DebugLog("Succeed initial Achievement System.");
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
    SStoreManager.releaseStore();
}

#ifdef __CBANDROID__
void CBGameApp::reloadTexture()
{
    STexturePool.reloadTexture();
}
#endif

void CBGameApp::initialTimer(double oldTime)
{
	STimerManager.initialTimer(oldTime);
}

void CBGameApp::retinaDisplay()
{
	CBEnvironment::retinaDisplay();
}

void CBGameApp::iOSWideScreen()
{
    SLayout.iOSWideScreen();
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

void CBGameApp::onAndroidAlertEvent(int dialogType, int dialogResult, int buttonIndex)
{
	DebugLog("CBGameApp::onAndroidAlertEvent\n");
	SEventProcessor.onAlertEvent((DialogResult)dialogResult, buttonIndex);
}
void CBGameApp::applicationDidEnterBackground()
{
    SEventProcessor.onApplicationDidEnterBackground();
}
void CBGameApp::applicationWillEnterForeground()
{
    SEventProcessor.onApplicationWillEnterForeground();
}

void CBGameApp::requestFail(string& msg)
{
    SStoreManager.requestFail(msg);
}
void CBGameApp::requestFinished()
{
    SStoreManager.requestFinished();
}

void CBGameApp::completeTransaction(string& buyProductTag)
{
    SStoreManager.completeTransaction(buyProductTag);
}
void CBGameApp::failedTransaction(string& msg, int errorCode)
{
    SStoreManager.failedTransaction(msg, errorCode);
}
void CBGameApp::restoreTransaction(string& buyProductTag)
{
    SStoreManager.restoreTransaction(buyProductTag);
}
void CBGameApp::purchasingTransaction(string& buyProductTag)
{
    SStoreManager.purchasingTransaction(buyProductTag);
}
void CBGameApp::restoreCompletedTransactionsFinished()
{
    SStoreManager.restoreCompletedTransactionsFinished();
}
void CBGameApp::restoreCompletedTransactionsFailed(string& msg, int errorCode)
{
    SStoreManager.restoreCompletedTransactionsFailed(msg, errorCode);
}
