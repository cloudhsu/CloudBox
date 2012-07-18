/*
 *  CBString.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/4.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBString.h"
#include "CBImage.h"

CBString::CBString()
:CBView(), m_textImage(NULL), m_text(""), m_fontSize(14)
{
}

CBString::CBString(const string& text,int fontSize)
:m_text(text), m_fontSize(fontSize)
{
	m_textImage = new CBImage(text, fontSize);
	setWidth(m_textImage->getWidth());
	setHeight(m_textImage->getHeight());
}

CBString::~CBString()
{
}

void CBString::setColor(float r, float g, float b, float a)
{
	m_textImage->setColor(r, g, b, a);
}

void CBString::setColor(float r, float g, float b)
{
	m_textImage->setColor(r, g, b);
}

void CBString::draw()
{
	if(!this->getVisible())
		return;
//	if(!isInitial)
//		isInitial = m_textImage->IsInitial();
	float x = this->getX();
	float y = this->getY();
	m_textImage->moveToAbsolute(x, y);
	m_textImage->visit();
}
