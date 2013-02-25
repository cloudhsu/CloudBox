/*
 *  CBButton.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBButton.h"
#include "CBImage.h"
#include "CBString.h"

CBButton::CBButton()
:CBView(),m_normal(NULL),m_clicked(NULL),m_text(NULL),m_fontSize(18)
{
	setNormalState(new CBImage(BUTTON_NORMAL_NAME));
	setClickState(new CBImage(BUTTON_CLICK_NAME));
	setText("Button");
	registerTouchEvent();
}

CBButton::CBButton(const string& text, int fontSize)
:CBView(),m_normal(NULL),m_clicked(NULL),m_text(NULL),m_fontSize(fontSize)
{
	setNormalState(new CBImage(BUTTON_NORMAL_NAME));
	setClickState(new CBImage(BUTTON_CLICK_NAME));
	setText(text);
	registerTouchEvent();
}

CBButton::~CBButton()
{
	CBDELETE(m_normal);
	CBDELETE(m_clicked);
	CBDELETE(m_text);
}

void CBButton::setNormalState(CBImage* image)
{
	CBDELETE(m_normal);
	m_normal = image;
	this->setWidth(m_normal->getWidth());
	this->setHeight(m_normal->getHeight());
}
void CBButton::setClickState(CBImage* image)
{
	CBDELETE(m_clicked);
	m_clicked = image;
}

void CBButton::draw()
{
	if(!this->getVisible())
		return;
//	if(!isInitial)
//		isInitial = m_normal->IsInitial() && m_clicked->IsInitial() && m_text->IsInitial();
	m_normal->moveToAbsolute(this->getX(), this->getY());
	m_clicked->moveToAbsolute(this->getX(), this->getY());
	if(m_isClick)
	{
		if(m_clicked)
			m_clicked->visit();
		else
			m_normal->visit();
	}
	else {
		m_normal->visit();
	}
	m_text->moveToAbsolute(this->getX() + m_textOffsetX,this->getY() + m_textOffsetY);
	m_text->visit();
}

void CBButton::offsetText()
{
	m_textOffsetX = (getWidth() - m_text->getWidth()) / 2;
	m_textOffsetY = (getHeight() - m_text->getHeight()) / 2;
}

void CBButton::setText(const string& text)
{
	CBString* newText = new CBString(text, m_fontSize);
	CBDELETE(m_text);
	m_text = newText;
	offsetText();
}

void CBButton::setText(const string& text, int fontSize)
{
	m_fontSize = fontSize;
	setText(text);
}

void CBButton::setTextColor(float r, float g, float b, float a)
{
	m_text->setColor(r,g,b,a);
}

void CBButton::touchBegan(float x, float y)
{
	if(isTrigger(x,y))
	{
		m_isClick = true;
		ITouch::onTrigger(this, new CBEvent(EventOnTouchBegan,x,y));
	}
}
void CBButton::touchMoved(float x, float y)
{
	if(isTrigger(x,y))
		ITouch::onTrigger(this, new CBEvent(EventOnTouchMoved,x,y));
	else {
		m_isClick = false;
	}
}
void CBButton::touchEnded(float x, float y)
{
	if(isTrigger(x,y))
	{
		m_isClick = false;
		ITouch::onTrigger(this, new CBEvent(EventOnTouchEnded,x,y));
	}
}