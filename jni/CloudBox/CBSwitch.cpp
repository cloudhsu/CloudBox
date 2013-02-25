/*
 *  CBSwitch.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/9.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBSwitch.h"
#include "CBImage.h"

CBSwitch::CBSwitch()
:CBView(),m_on(NULL),m_off(NULL),m_status(SwitchOn),m_switch(NULL)
{
}

CBSwitch::CBSwitch(CBView* onView,CBView* offView)
:CBView(),m_on(NULL),m_off(NULL),m_status(SwitchOn),m_switch(NULL)
{
	setOnView(onView);
	setOffView(offView);
	registerClickEvent();
}

CBSwitch::CBSwitch(const string& onImageName,const string& offImageName)
:CBView(),m_on(NULL),m_off(NULL),m_status(SwitchOn),m_switch(NULL)
{
	setOnView(onImageName);
	setOffView(offImageName);
	registerClickEvent();
}

CBSwitch::~CBSwitch()
{
	CBDELETE(m_on);
	CBDELETE(m_off);
}

void CBSwitch::onSwitch()
{
	if(m_switch)
		m_switch->invoke(this,m_status);
}

void CBSwitch::draw()
{
	if(!this->getVisible())
		return;
	if(m_status == SwitchOff)
	{
		m_off->show();
		m_on->hide();
		m_off->moveToAbsolute(m_x, m_y);
		m_off->visit();
	}
	else
	{
		m_off->hide();
		m_on->show();
		m_on->moveToAbsolute(m_x, m_y);
		m_on->visit();
	}
}

void CBSwitch::onClick(float x,float y)
{
    if(!this->getVisible())
		return;
	if(m_off->isTrigger(x, y))
	{
		turnOn();
        onSwitch();
	}
	else if(m_on->isTrigger(x, y))
	{
		turnOff();
        onSwitch();
	}
}

void CBSwitch::setOnView(CBView* view)
{
	CBDELETE(m_on);
	m_on = view;
	this->setWidth(m_on->getWidth());
	this->setHeight(m_on->getHeight());
}
void CBSwitch::setOffView(CBView* view)
{
	CBDELETE(m_off);
	m_off = view;
}

void CBSwitch::setOnView(const string& imageName)
{
	CBImage* image = new CBImage(imageName);
	setOnView(image);
}
void CBSwitch::setOffView(const string& imageName)
{
	CBImage* image = new CBImage(imageName);
	setOffView(image);
}

void CBSwitch::switchStatus()
{
    m_status = ((m_status == SwitchOff) ? SwitchOn : SwitchOff);
}
void CBSwitch::turnOn()
{
	m_status = SwitchOn;
}
void CBSwitch::turnOff()
{
	m_status = SwitchOff;
}