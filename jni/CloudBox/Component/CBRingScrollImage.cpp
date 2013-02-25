/*
 *  CBRingScrollImage.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/18.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBRingScrollImage.h"
#ifdef __CBBLACKBERRY__ 
#include "../CBImage.h"
#include "../CBAction.h"
#include "../CBEnvironment.h"
#include "../CBLayout.h"
#elif WIN32
#include "../CBImage.h"
#include "../CBAction.h"
#include "../CBEnvironment.h"
#include "../CBLayout.h"
#else
#include "CBImage.h"
#include "CBAction.h"
#include "CBEnvironment.h"
#include "CBLayout.h"
#endif

CBRingScrollImage::CBRingScrollImage()
:CBView(), m_image1(NULL), m_image2(NULL),m_isPause(false)
{
	initial();
}

CBRingScrollImage::CBRingScrollImage(const string& imageName, ScrollCoordinate scrollCoordinate, float distance, float duration)
:CBView(), m_image1(NULL), m_image2(NULL), m_scrollCoordinate(scrollCoordinate),
m_distance(distance), m_duration(duration),m_isPause(false)
{
	initial();
	setImage(imageName);
}

CBRingScrollImage::CBRingScrollImage(CBView* view, ScrollCoordinate scrollCoordinate, float distance, float duration)
:CBView(), m_image1(NULL), m_image2(NULL), m_scrollCoordinate(scrollCoordinate),
m_distance(distance), m_duration(duration),m_isPause(false)
{
    initial();
	setImage(view);
}

CBRingScrollImage::CBRingScrollImage(ScrollCoordinate scrollCoordinate, float distance, float duration)
:CBView(), m_image1(NULL), m_image2(NULL), m_scrollCoordinate(scrollCoordinate),
m_distance(distance), m_duration(duration),m_isPause(false)
{
    
}

CBRingScrollImage::~CBRingScrollImage()
{
	CBDELETE(m_image1);
	CBDELETE(m_image2);
}

//const float CBRingScrollImage::getOffset()
//{
//    return m_offset;
//}
//void CBRingScrollImage::setOffset(float offset)
//{
//    m_offset = offset;
//    SLayout.scaleWidth(m_offset);
//}

void CBRingScrollImage::initial()
{
	this->setWidth(CBEnvironment::getScreenWidth());
	this->setHeight(CBEnvironment::getScreenHeight());
	DebugLog("Width:%f\n",this->getWidth());
	DebugLog("Height:%f\n",this->getHeight());
}

void CBRingScrollImage::setImage(const string& imageName)
{
	m_image1 = new CBImage(imageName);
	m_image2 = new CBImage(imageName);
}

void CBRingScrollImage::setImage(CBView* view)
{
	m_image1 = view;
	m_image2 = view;
}

void CBRingScrollImage::setImage(CBView* view1, CBView* view2)
{
    m_image1 = view1;
	m_image2 = view2;
}

void CBRingScrollImage::resetImage2()
{
	if(m_scrollCoordinate == ScrollX)
	{
		if(m_distance < 0)
			m_image2->moveToAbsolute(m_image1->getX() + m_image1->getWidth(), getY());
		else if(m_distance > 0)
			m_image2->moveToAbsolute(m_image1->getX() - m_image1->getWidth(), getY());
	}
	else if(m_scrollCoordinate == ScrollY)
	{
		if(m_distance < 0)
			m_image2->moveToAbsolute(getX(), m_image1->getY() + m_image1->getHeight());
		else if(m_distance > 0)
			m_image2->moveToAbsolute(getX(), m_image1->getY() - m_image1->getHeight());
	}
    //DebugLog("image1 X:%f,Y:%f\n", m_image1->getX(),m_image1->getY());
    //DebugLog("image2 X:%f,Y:%f\n", m_image2->getX(),m_image2->getY());
}

void CBRingScrollImage::scrollImage(CBView* target)
{
    if(m_isPause)
        return;
	bool isSwap = false;
	if(m_scrollCoordinate == ScrollX)
	{
		m_image1->move(m_distance, 0);
		m_image2->move(m_distance, 0);
		if((m_image2->getX() <= 0 && m_distance < 0) ||
		   (m_image2->getX() + m_image2->getWidth() >= this->getWidth() && m_distance > 0))
			isSwap = true;
	}
	else if(m_scrollCoordinate == ScrollY)
	{
		m_image1->move(0, m_distance);
		m_image2->move(0, m_distance);
		if((m_image2->getY() <= 0 && m_distance < 0) ||
		   (m_image2->getY() + m_image2->getHeight() >= this->getHeight() && m_distance > 0))
			isSwap = true;
	}
	if(isSwap)
	{
		CBView* temp = m_image1;
		m_image1 = m_image2;
		m_image2 = temp;
		temp = NULL;
		resetImage2();
	}
	//DebugLog("image1 X:%f,Y:%f\n", m_image1->getX(),m_image1->getY());
	//DebugLog("image2 X:%f,Y:%f\n", m_image2->getX(),m_image2->getY());
}

void CBRingScrollImage::startScroll()
{
    m_image1->moveToAbsolute(getX(), getY());
    resetImage2();
	CBAction* action = new CBAction(m_duration,REPEAT_ALWAYS);
	action->addTriggerEvent(this,&CBRingScrollImage::scrollImage);
	action->commit(this);
}

void CBRingScrollImage::initialScroll()
{
	m_isPause = false;
    m_image1->moveToAbsolute(getX(), getY());
    resetImage2();
}

void CBRingScrollImage::draw()
{
	if(!this->getVisible())
		return;
	m_image1->visit();
	m_image2->visit();
}
