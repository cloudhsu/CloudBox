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
	
	button1 = new CBButton("Complete",20);
	button1->moveTo(110,80);
    button1->addClickEvent(this, &HelloScene::OnClick1);
	addChild(button1);
    
    button2 = new CBButton("Increase",20);
	button2->moveTo(210,80);
    button2->addClickEvent(this, &HelloScene::OnClick2);
	addChild(button2);

    button3 = new CBButton("Update",20);
    button3->moveTo(310,80);
    button3->addClickEvent(this, &HelloScene::OnClick3);
    addChild(button3);
    
    
	
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
    
    button4 = new CBButton("Show",20);
    button4->moveTo(110,150);
    button4->addClickEvent(this, &HelloScene::OnClick4);
    addChild(button4);
    
    button5 = new CBButton("Reset",20);
    button5->moveTo(210,150);
    button5->addClickEvent(this, &HelloScene::OnClick5);
    addChild(button5);
    
    button6 = new CBButton("Facebook",20);
    button6->moveTo(310,150);
    button6->addClickEvent(this, &HelloScene::OnClick6);
    addChild(button6);
}

void HelloScene::update()
{
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
}

void HelloScene::OnClick1( CBView* item,CBEvent* e )
{
    SAchievementManager.completeAchievement("com.cloudbox.superbabypig.stage1_clear");
}

void HelloScene::OnClick2( CBView* item,CBEvent* e )
{
    SAchievementManager.increaseAchievement("com.cloudbox.superbabypig.stage2_clear", 1);
}

void HelloScene::OnClick3( CBView* item,CBEvent* e )
{
    SAchievementManager.updateAchievement("com.cloudbox.superbabypig.stage3_clear", 5);
}

void HelloScene::OnClick4( CBView* item,CBEvent* e )
{
    SAchievementManager.showGameCenter();
}

void HelloScene::OnClick5( CBView* item,CBEvent* e )
{
    SAchievementManager.resetAllAchievement();
}

void HelloScene::OnClick6( CBView* item,CBEvent* e )
{
    SAchievementManager.loginFacebook();
}