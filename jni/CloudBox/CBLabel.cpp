/*
 *  CBLabel.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/6.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLabel.h"
#include "CBImage.h"
#include "CBString.h"

CBLabel::CBLabel()
:CBView(),m_background(NULL),m_text(NULL), m_textOffsetX(0), m_textOffsetY(0), m_fontSize(24)
{
	loadBackground(LABEL_NAME);
	setText("Label");
}

CBLabel::CBLabel(const string& text, int fontSize)
:CBView(),m_background(NULL),m_text(NULL)
{
	loadBackground(LABEL_NAME);
	setText(text,fontSize);
}

CBLabel::CBLabel(const string& fileName,const string& text, int fontSize)
:CBView(),m_background(NULL),m_text(NULL)
{
	loadBackground(fileName);
	setText(text,fontSize);
}

CBLabel::~CBLabel()
{
	CBDELETE(m_text);
}

void CBLabel::offsetText()
{
	m_textOffsetX = (getWidth() - m_text->getWidth()) / 2;
	m_textOffsetY = (getHeight() - m_text->getHeight()) / 2;
}

void CBLabel::loadBackground(const string& fileName)
{
	//m_background->loadImage(fileName);
	CBImage* newBg = new CBImage(fileName);
	CBDELETE(m_background);
	m_background = newBg;
	setWidth(m_background->getWidth());
	setHeight(m_background->getHeight());
}

void CBLabel::setBackground(const string& fileName)
{
	loadBackground(fileName);
	offsetText();
}

void CBLabel::setText(const string& text)
{
	CBString* newText = new CBString(text, m_fontSize);
	CBDELETE(m_text);
	m_text = newText;
	offsetText();
}

void CBLabel::setText(const string& text, int fontSize)
{
	m_fontSize = fontSize;
	setText(text);
}

void CBLabel::setTextColor(float r, float g, float b, float a)
{
	m_text->setColor(r,g,b,a);
}

void CBLabel::draw()
{
	if(!this->getVisible())
		return;
//	if(!isInitial)
//		isInitial = m_background->IsInitial() && m_text->IsInitial();
	m_background->moveToAbsolute(getX(), getY());
	m_background->visit();
	m_text->moveToAbsolute(this->getX() + m_textOffsetX,this->getY() + m_textOffsetY);
	m_text->visit();
}
