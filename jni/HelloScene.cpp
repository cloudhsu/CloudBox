/*
 *  HelloScene.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/31.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAchievementManager.h"
#include "HelloScene.h"

HelloScene::HelloScene()
{
}

HelloScene::~HelloScene()
{
}

void HelloScene::initialize()
{
//	bg1 = new CBImage("testbg1.png");
//	addChild(bg1,0,0);
//	
//	bg2 = new CBImage("testbg2.png");
//	addChild(bg2,0,0);
	//bg = new CBRingScrollImage("testbg1.png",ScrollY,3 ,0.02);
	bg = new CBRingScrollImage("testbg11.png",ScrollX,-3 ,0.02);
	addChild(bg,0,0);
	bg->startScroll();
//    CBImage* img = new CBImage("testbg11.png");
//    addChild(img,0,100);
	
	label = new CBLabel("Label", 18);
	label->moveTo(10,10);
	addChild(label);
	
	button = new CBButton("Button1",20);
	button->moveTo(10,80);
	addChild(button);
    
    button2 = new CBButton("Button2",20);
	button2->moveTo(200,80);
    button2->addClickEvent(this, &HelloScene::OnClick);
	addChild(button2);
	
	dart2 = new CBImage("dart.png");
	addChild(dart2,210,200);
	
	dart = new CBImage("dart.png");
	addChild(dart,210,120);
	
	
	
	CBRotateAction* rotate = new CBRotateAction(10,0.03,REPEAT_ALWAYS);
	rotate->commit(dart);
	
	for (int i = 0; i < MAX_ANIMATION; i++) {
		animation[i] = new CBAnimation(0.1);
		animation[i]->addFrame("bomb1.png");
		animation[i]->addFrame("bomb2.png");
		addChild(animation[i],100,10+(i*40));
	}
    
    CBSlideBar* bar = new CBSlideBar();
    bar->setOptionButton(OPTION_NAME);
    bar->setOptionBar(OPTION_UP_BG_NAME);
    //bar->setOptionBar(OPTION_DOWN_BG_NAME);
    //bar->setOptionBar(OPTION_LEFT_BG_NAME);
    //bar->setOptionBar(OPTION_RIGHT_BG_NAME);
    bar->addButton(OPTION_INFO_NAME);
    bar->addButton(OPTION_HELP_NAME);
    //bar->setOptionBarDirection(SlideBarLeft);
    bar->setOptionBarDirection(SlideBarUp);
    //bar->setOptionBarDirection(SlideBarDown);
    bar->initial();
    addChild(bar,200,140);
    SAchievementManager.initialAchievementSystem();
}

void HelloScene::update()
{
	//bg2->move(0, -1);
//	static int i = 0;
//	if(i++ > 5)
//	{
//		i = 0;
//	static float aaa = 3;
//	if(dart->getX() > CBEnvironment::getScreenWidth())
//	{
//		aaa = -3;
//	}
//	else if(dart->getX() < 0) {
//		aaa = 3;
//	}
//	static float bbb = 3;
//	if(dart->getY() > CBEnvironment::getScreenHeight())
//	{
//		bbb = -3;
//	}
//	else if(dart->getY() < 0) {
//		bbb = 3;
//	}
//
//	//dart->move(aaa, 0);
//	//dart->move(0, bbb);
//	dart->move(aaa, bbb);
//	dart->rotate(15);
//	}
}

void HelloScene::OnClick(CBView* item,CBEvent* e)
{
    SAchievementManager.completeAchievement("com.cloudbox.superbabypig.stage1_clear");
}

void HelloScene::OnOptionButtonClick(CBView* item,int index)
{
	DebugLog("HelloScene::OnOptionButtonClick [%d]\n",index);
}

void HelloScene::touchBegan(float x, float y)
{
}
void HelloScene::touchMoved(float x, float y)
{
}
void HelloScene::touchEnded(float x, float y)
{
	if(button->isInArea(x, y))
		SDirector.runNextScene(new HelloScene());
}
