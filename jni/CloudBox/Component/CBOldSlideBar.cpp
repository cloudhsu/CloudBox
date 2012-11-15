/*
 *  CBOldSlideBar.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/8.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBOldSlideBar.h"
#include "CBImage.h"
#include "CBSwitch.h"

CBOldSlideBar::CBOldSlideBar()
: m_optionButton(NULL), m_optionBar(NULL), m_status(SlideBarHide),
m_optionButtonShowClick(NULL), m_optionButtonHideClick(NULL),
m_optionBarShow(NULL), m_optionBarHide(NULL), m_buttonClick(NULL),
m_direction(SlideBarRight)
{
	registerClickEvent();
}

//CBOldSlideBar::CBOldSlideBar(DefaultSlideBar defaultType)
//: m_optionButton(NULL), m_optionBar(NULL), m_status(SlideBarHide),
//m_optionButtonShowClick(NULL), m_optionButtonHideClick(NULL),
//m_optionBarShow(NULL), m_optionBarHide(NULL)
//{
//	registerClickEvent();
//	setDefaultBar1();
//}

CBOldSlideBar::~CBOldSlideBar()
{
	DELETE(m_optionButton);
	DELETE(m_optionBar);
	DELETE(m_buttonClick);
	for(int i = 0 ; i < m_options.size() ; i++)
	{
		DELETE(m_options[i]);
	}
	m_options.clear();
}

void CBOldSlideBar::onBarAnimationScrolling(CBView* target)
{
	int x = target->getX() + target->getWidth();
	for(int i = 0 ; i < m_options.size() ; i++)
	{
		if(m_status == SlideBarShow)
		{
			if((m_options[i]->getX() + m_options[i]->getWidth()) <= x)
			{
				m_options[i]->show();
			}
		}
		else if(m_status == SlideBarHide)
		{
			if((m_options[i]->getX() + m_options[i]->getWidth()) > x)
			{
				m_options[i]->hide();
			}
		}
	}
}

void CBOldSlideBar::onBarAnimationFinish(CBView* target)
{
	if(m_status == SlideBarHide)
	{
		target->hide();
	}
}

void CBOldSlideBar::setOptionButton(const string& imageName)
{
	DELETE(m_optionButton);
	m_optionButton = new CBImage(imageName);
}

void CBOldSlideBar::setOptionBar(const string& imageName)
{
	DELETE(m_optionBar);
	m_optionBar = new CBImage(imageName);
	m_optionBar->hide();
}

void CBOldSlideBar::addButton(const string& imageName)
{
	CBImage* image = new CBImage(imageName);
	image->hide();
	m_options.push_back(image);
}

void CBOldSlideBar::addSwitchButton(const string& onImageName,const string& offImageName)
{
	CBSwitch* button = new CBSwitch(onImageName,offImageName);
	button->hide();
	m_options.push_back(button);
}

void CBOldSlideBar::onOptionClick()
{
	if(m_status == SlideBarShow)
	{
		m_status = SlideBarHide;
		m_optionButtonHideClick->stop();
		m_optionBarShow->stop();
		m_optionButtonHideClick->commit(m_optionButton);
		m_optionBarHide->commit(m_optionBar);
	}
	else
	{
		m_status = SlideBarShow;
		m_optionButtonHideClick->stop();
		m_optionBarHide->stop();
		m_optionButtonShowClick->commit(m_optionButton);
		m_optionBarShow->commit(m_optionBar);
		m_optionBar->show();
	}
}

void CBOldSlideBar::onClick(float x,float y)
{
	if(m_optionButton->isTrigger(x, y))
	{
		onOptionClick();
	}
	if(m_status == SlideBarShow)
	{
		for(int i = 0 ; i < m_options.size() ; i++)
		{
			if(m_options[i]->isTrigger(x,y))
			{
				onButtonClick(m_options[i], i);
				break;
			}
		}
	}
}

void CBOldSlideBar::onButtonClick(CBView* target, int index)
{
	DebugLog("click [%d] button in CBOldSlideBar\n",index);
	if(m_buttonClick)
		m_buttonClick->invoke(target,index);
}

void CBOldSlideBar::draw()
{
	m_optionBar->moveToAbsolute(m_x, m_y);
	m_optionBar->visit();
	m_optionButton->moveToAbsolute(m_x, m_y);
	m_optionButton->visit();
	int width = 0;
	for(int i = 0 ; i < m_options.size() ; i++)
	{
		m_options[i]->moveToAbsolute(m_x + m_optionButton->getWidth() + width, m_y);
		m_options[i]->visit();
		width += m_options[i]->getWidth();
	}
}