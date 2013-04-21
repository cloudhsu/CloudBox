//
//  LogoScene.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/25.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#include "CBLogoScene.h"
#include "CBOpenGL.h"
#ifdef __CBIOS__
#include "HelloScene.h"
#else
#include "../HelloScene.h"
#endif

CBLogoScene::CBLogoScene()
{
	// construct
}

CBLogoScene::~CBLogoScene()
{
	// Deconstruct
}

void CBLogoScene::initialize()
{
	//DebugLog("initial in logo scene\n");
	bg = new CBImage(LOGO_NAME);
	float x = (CBEnvironment::getScreenWidth() - bg->getWidth()) / 2;
	float y = (CBEnvironment::getScreenHeight() - bg->getHeight()) / 2;
    //DebugLog("x=%f,y=%f\n", x,y);
    //DebugLog("width=%f,height=%f\n", bg->getWidth(),bg->getHeight());
	bg->moveToAbsolute(x, y);
	addChild(bg);
    
	CBAction* action = new CBAction(LOGO_TIME,1);
	action->addFinishEvent(this,&CBLogoScene::finish);
	action->commit(this);
    SAudioEngine.initialEngine();
    SAudioEngine.loadEffect(LOGO_SOUND);
    SAudioEngine.playEffect(LOGO_SOUND);
}

void CBLogoScene::finish(CBView* sender)
{
	//DebugLog("scene change:LogoScene => HelloScene\n");
	SDirector.runNextScene(new HelloScene());
}

void CBLogoScene::draw()
{
	SOpenGL.fillScreen(1,1,1);
}
