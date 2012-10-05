/*
 *  EventDispatcher.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/16.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBEventDispatcher.h"
#include "IClick.h"
#include "ITouch.h"

CBEventDispatcher::CBEventDispatcher()
{
}

CBEventDispatcher::~CBEventDispatcher()
{
	clear();
}

void CBEventDispatcher::clear()
{
	m_touchHandlers.clear();
	m_clickHandlers.clear();
}
void CBEventDispatcher::registerEventHandler(ITouch* touchHandler)
{
	m_touchHandlers.push_back(touchHandler);
}
void CBEventDispatcher::registerEventHandler(IClick* clickHandler)
{
	m_clickHandlers.push_back(clickHandler);
}

void CBEventDispatcher::onClick(float x, float y)
{
	for (int i = 0; i < m_clickHandlers.size(); i++) {
		m_clickHandlers[i]->onClick(x,y);
	}
}

void CBEventDispatcher::touchBegan(float x, float y)
{
	for (int i = 0; i < m_touchHandlers.size(); i++) {
		m_touchHandlers[i]->touchBegan(x,y);
	}
}
void CBEventDispatcher::touchMoved(float x, float y)
{
	for (int i = 0; i < m_touchHandlers.size(); i++) {
		m_touchHandlers[i]->touchMoved(x,y);
	}
}
void CBEventDispatcher::touchEnded(float x, float y)
{
	for (int i = 0; i < m_touchHandlers.size(); i++) {
		m_touchHandlers[i]->touchEnded(x,y);
	}
}