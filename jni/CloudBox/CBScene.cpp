/*
 *  CBScene.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBScene.h"
#include "CBTexture.h"

CBScene::CBScene()
{
	// construct
	m_isEndInitial = false;
	m_isEndTextureInit = false;
}

void CBScene::endInitial()
{
	m_isEndInitial = true;
}

//void CBScene::checkEndInitial()
//{
//	if(m_isEndInitial)
//	{
//		bool init = true;
//		for(int i = 0; i < m_items.size() ; i++)
//		{
//			if(!m_items[i]->IsInitial())
//			{
//				init = false;
//				break;
//			}
//		}
//		m_isEndTextureInit = init;
//	}
//}

CBScene::~CBScene()
{
	for (int i = 0; i < m_items.size(); i++) {
		CBDELETE(m_items[i]);
	}
	m_items.clear();
}

void CBScene::draw()
{
}

void CBScene::drawAfter()
{
}

void CBScene::notify()
{
    // call update scene
	update();
    // notify all sub item to update
    for (int i = 0; i < m_items.size(); i++) {
		m_items[i]->notify();
	}
}

void CBScene::update()
{
}

void CBScene::visit()
{
	// call scene draw
	draw();
	// call items visit
	for (int i = 0; i < m_items.size(); i++) {
		m_items[i]->visit();
	}
    drawAfter();
}

void CBScene::addChild(CBView* view)
{
	m_items.push_back(view);
}

void CBScene::addChild(CBView* view, float x, float y)
{
	view->moveTo(x, y);
	addChild(view);
}

void CBScene::applicationDidEnterBackground()
{
}
void CBScene::applicationWillEnterForeground()
{
}
