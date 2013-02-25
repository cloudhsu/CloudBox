/*
 *  CBSlideBar.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/8/21.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBSlideBar.h"
#ifdef __CBIOS__
#include "CBPropertyAction.h"
#include "CBImage.h"
#include "CBSwitch.h"
#elif WIN32
#include "../CBPropertyAction.h"
#include "../CBImage.h"
#include "../CBSwitch.h"
#else
#include "../CBPropertyAction.h"
#include "../CBImage.h"
#include "../CBSwitch.h"
#endif

CBSlideBar::CBSlideBar()
: m_optionButton(NULL), m_optionBar(NULL), m_status(SlideBarHide),
m_optionButtonShowClick(NULL), m_optionButtonHideClick(NULL),
m_optionBarShow(NULL), m_optionBarHide(NULL), m_buttonClick(NULL),
m_direction(SlideBarRight),m_duration(1.0),m_barScrollLength(10.0),
m_optionClick(NULL)
{
	registerClickEvent();
}

CBSlideBar::~CBSlideBar()
{
	CBDELETE(m_optionButton);
	CBDELETE(m_optionBar);
	CBDELETE(m_buttonClick);
	for(int i = 0 ; i < m_options.size() ; i++)
	{
		CBDELETE(m_options[i]);
	}
	m_options.clear();
}

void CBSlideBar::setAnimatingDuration(float duration)
{
    m_duration = duration;
}
void CBSlideBar::optionAnimating()
{
    if(m_status == SlideBarShow)
    {
        barShowAnimating();
        buttonShowAnimating();
        checkShowAnimationFinished();
    }
    else
    {
        barHideAnimating();
        buttonHideAnimating();
        checkHideAnimationFinished();
    }
}

void CBSlideBar::barShowAnimating()
{
    if(SlideBarUp == m_direction)
    {
        m_optionBar->scaleHeight(m_barScrollLength);
    }
    else if(SlideBarDown == m_direction)
    {
        m_optionBar->scaleHeight(m_barScrollLength);
    }
    else if(SlideBarLeft == m_direction)
    {
        m_optionBar->scaleWidth(m_barScrollLength);
    }
    else
    {
        m_optionBar->scaleWidth(m_barScrollLength);
    }
}
void CBSlideBar::barHideAnimating()
{
    if(SlideBarUp == m_direction)
    {
        m_optionBar->scaleHeight(-m_barScrollLength);
    }
    else if(SlideBarDown == m_direction)
    {
        m_optionBar->scaleHeight(-m_barScrollLength);
    }
    else if(SlideBarLeft == m_direction)
    {
        m_optionBar->scaleWidth(-m_barScrollLength);
    }
    else
    {
        m_optionBar->scaleWidth(-m_barScrollLength);
    }
}

void CBSlideBar::buttonShowAnimating()
{
    if(SlideBarUp == m_direction)
    {
        float y = m_optionBar->getY();
        DebugLog("option bar y:%f\n", y);
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if(m_options[i]->getY() >= y)
            {
                m_options[i]->show();
            }
        }
    }
    else if(SlideBarDown == m_direction)
    {
        float y = m_optionBar->getY() + m_optionBar->getHeight();
        DebugLog("option bar height:%f\n", m_optionBar->getHeight());
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if((m_options[i]->getY() + m_options[i]->getHeight()) <= y)
            {
                m_options[i]->show();
            }
        }
    }
    else if(SlideBarLeft == m_direction)
    {
        float x = m_optionBar->getX();
        DebugLog("option bar x:%f\n", x);
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if(m_options[i]->getX() >= x)
            {
                m_options[i]->show();
            }
        }
    }
    else
    {
        float x = m_optionBar->getX() + m_optionBar->getWidth();
        DebugLog("option bar width:%f\n", m_optionBar->getWidth());
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if((m_options[i]->getX() + m_options[i]->getWidth()) <= x)
            {
                m_options[i]->show();
            }
        }
    }
}
void CBSlideBar::buttonHideAnimating()
{
    if(SlideBarUp == m_direction)
    {
        float y = m_optionBar->getY();
        DebugLog("option bar y:%f\n", y);
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if(m_options[i]->getY() < y)
            {
                m_options[i]->hide();
            }
        }
    }
    else if(SlideBarDown == m_direction)
    {
        float y = m_optionBar->getY() + m_optionBar->getHeight();
        DebugLog("option bar height:%f\n", m_optionBar->getHeight());
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if((m_options[i]->getY() + m_options[i]->getHeight()) > y)
            {
                m_options[i]->hide();
            }
        }
    }
    else if(SlideBarLeft == m_direction)
    {
        float x = m_optionBar->getX();
        DebugLog("option bar x:%f\n", x);
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if(m_options[i]->getX() < x)
            {
                m_options[i]->hide();
            }
        }
    }
    else
    {
        float x = m_optionBar->getX() + m_optionBar->getWidth();
        DebugLog("option bar width:%f\n", m_optionBar->getWidth());
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            if((m_options[i]->getX() + m_options[i]->getWidth()) > x)
            {
                m_options[i]->hide();
            }
        }
    }
}

void CBSlideBar::checkShowAnimationFinished()
{
    if(SlideBarUp == m_direction || SlideBarDown == m_direction)
    {
        if(m_optionBar->getHeight() >= m_barHeight)
        {
            m_optionBar->setHeight(m_barHeight);
            m_optionBarShow->finish();
        }
    }
    else
    {
        if(m_optionBar->getWidth() >= m_barWidth)
        {
            m_optionBar->setWidth(m_barWidth);
            m_optionBarShow->finish();
        }
    }
}
void CBSlideBar::checkHideAnimationFinished()
{
    if(SlideBarUp == m_direction || SlideBarDown == m_direction)
    {
        if(m_optionBar->getHeight() <= m_optionButton->getHeight())
        {
            m_optionBar->setHeight(m_optionButton->getHeight());
            m_optionBarHide->finish();
        }
    }
    else
    {
        if(m_optionBar->getWidth() <= m_optionButton->getWidth())
        {
            m_optionBar->setWidth(m_optionButton->getWidth());
            m_optionBarHide->finish();
        }
    }
}

void CBSlideBar::onBarAnimationScrolling(CBView* target)
{
    optionAnimating();
}

void CBSlideBar::onBarAnimationFinish(CBView* target)
{
	if(m_status == SlideBarHide)
	{
		target->hide();
	}
}

void CBSlideBar::setOptionButton(const string& imageName)
{
	CBDELETE(m_optionButton);
	m_optionButton = new CBImage(imageName);
}

void CBSlideBar::setOptionBar(const string& imageName)
{
	CBDELETE(m_optionBar);
	m_optionBar = new CBImage(imageName);
	m_optionBar->hide();
}
void CBSlideBar::setOptionBarDirection(const SlideBarDirection direction)
{
    m_direction = direction;
}

void CBSlideBar::addButton(const string& imageName)
{
	CBImage* image = new CBImage(imageName);
	image->hide();
	m_options.push_back(image);
}

void CBSlideBar::addSwitchButton(const string& onImageName,const string& offImageName)
{
	CBSwitch* button = new CBSwitch(onImageName,offImageName);
	button->hide();
	m_options.push_back(button);
}

void CBSlideBar::addSwitchButton(const string& onImageName,const string& offImageName,bool isOn)
{
    CBSwitch* button = new CBSwitch(onImageName,offImageName);
	button->hide();
    button->setStatus((SwitchStatus)isOn);
	m_options.push_back(button);
}

void CBSlideBar::onOptionClick()
{
	if(m_status == SlideBarShow)
	{
		m_status = SlideBarHide;
		m_optionButtonShowClick->stop();
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
    if(m_optionClick)
		m_optionClick->invoke(m_optionButton);
}

void CBSlideBar::onClick(float x,float y)
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

void CBSlideBar::onButtonClick(CBView* target, int index)
{
	DebugLog("click [%d] button in CBSlideBar\n",index);
	if(m_buttonClick)
		m_buttonClick->invoke(target,index);
}

void CBSlideBar::draw()
{
	int width = 0;
    int height = 0;
    if(SlideBarUp == m_direction)
    {
        float shift = (m_optionButton->getWidth() - m_optionBar->getWidth())/2;
        m_optionBar->moveToAbsolute(m_x + shift, m_y + m_optionButton->getHeight() - m_optionBar->getHeight());
        m_optionBar->visit();
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            height += m_options[i]->getHeight();
            m_options[i]->moveToAbsolute(m_x + shift, m_y - height);
            m_options[i]->visit();
        }
    }
    else if(SlideBarDown == m_direction)
    {
        float shift = (m_optionButton->getWidth() - m_optionBar->getWidth())/2;
        m_optionBar->moveToAbsolute(m_x + shift, m_y);
        m_optionBar->visit();
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            m_options[i]->moveToAbsolute(m_x + shift, m_y + m_optionButton->getHeight() + height);
            height += m_options[i]->getHeight();
            m_options[i]->visit();
        }
    }
    else if(SlideBarLeft == m_direction)
    {
        float shift = (m_optionButton->getHeight() - m_optionBar->getHeight())/2;
        m_optionBar->moveToAbsolute(m_x + m_optionButton->getWidth() - m_optionBar->getWidth(), m_y + shift);
        m_optionBar->visit();
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            width += m_options[i]->getWidth();
            m_options[i]->moveToAbsolute(m_x - width, m_y + shift);
            m_options[i]->visit();
        }
    }
    else
    {
        float shift = (m_optionButton->getHeight() - m_optionBar->getHeight())/2;
        m_optionBar->moveToAbsolute(m_x, m_y + shift);
        m_optionBar->visit();
        for(int i = 0 ; i < m_options.size() ; i++)
        {
            m_options[i]->moveToAbsolute(m_x + m_optionButton->getWidth() + width, m_y + shift);
            width += m_options[i]->getWidth();
            m_options[i]->visit();
        }
    }
    m_optionButton->moveToAbsolute(m_x, m_y);
    m_optionButton->visit();
}

void CBSlideBar::initial()
{
    // initial option button rotate animation
    m_optionButtonShowClick =
	new CBPropertyAction(CBProperty(ActionPropertyAngle,0,360,15, PropertyFromCurrent),
						 0.015);
	m_optionButtonHideClick =
	new CBPropertyAction(CBProperty(ActionPropertyAngle,360,0,-15, PropertyFromCurrent),
						 0.015);
    
    m_optionBarShow = new CBAction(0.015,100);
    m_optionBarShow->addTriggerEvent(this,&CBSlideBar::onBarAnimationScrolling);
    
    m_optionBarHide = new CBAction(0.015,100);
    m_optionBarHide->addTriggerEvent(this,&CBSlideBar::onBarAnimationScrolling);
    m_optionBarHide->addFinishEvent(this,&CBSlideBar::onBarAnimationFinish);
    
    m_barWidth = 0;
    m_barHeight = 0;
    for(int i = 0 ; i < m_options.size() ; i++)
    {
        m_barWidth += m_options[i]->getWidth();
        m_barHeight += m_options[i]->getHeight();
    }
    m_barWidth += m_optionButton->getWidth() + 3;
    m_barHeight += m_optionButton->getHeight() + 3;
    if(SlideBarUp == m_direction || SlideBarDown == m_direction)
    {
        m_optionBar->setHeight(m_optionButton->getHeight());
    }
    else
    {
        m_optionBar->setWidth(m_optionButton->getWidth());
    }
//    m_optionBar->setWidth(m_optionButton->getWidth());
//    m_optionBar->setHeight(m_optionButton->getHeight());
}
