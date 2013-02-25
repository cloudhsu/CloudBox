/*
 *  CBAnimation.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAnimation.h"
#include "CBImage.h"
#include "CBTimerManager.h"

CBAnimation::CBAnimation()
:m_index(0), m_duration(0.1), m_timer(0)
{
}

CBAnimation::CBAnimation(float duration)
:m_index(0), m_duration(duration), m_timer(0)
{
}

CBAnimation::~CBAnimation()
{
	for (int i = 0; i < m_frames.size(); i++) {
		CBDELETE(m_frames[i].image);
	}
	m_frames.clear();
}

void CBAnimation::resetAnimation()
{
	m_index = 0;
	m_timer = 0;
}

void CBAnimation::addFrame(const string& imageName)
{
	CBImage* image = new CBImage(imageName);
	addFrame(image,0.0,0.0);
}
void CBAnimation::addFrame(const string& imageName, float offsetX, float offsetY)
{
	CBImage* image = new CBImage(imageName);
	addFrame(image,offsetX,offsetY);
}

void CBAnimation::addFrame(CBImage* image)
{
	addFrame(image,0.0,0.0);
}

void CBAnimation::addFrame(CBImage* image, float offsetX, float offsetY)
{
	CBFrame frame;
	frame.image = image;
	frame.offsetX = offsetX;
	frame.offsetY = offsetY;
	m_frames.push_back(frame);
	if(m_frames.size() == 1)
	{
		this->setWidth(image->getWidth());
		this->setHeight(image->getHeight());
	}
}

void CBAnimation::update()
{
    m_timer += STimerManager.getSpanTime(); 
	if(m_timer > m_duration)
	{
		m_timer -= m_duration;
		m_index++;
		if(m_index >= m_frames.size())
			m_index = 0;
	}
}

void CBAnimation::draw()
{
	if(!this->getVisible())
		return;
//	if(!isInitial)
//	{
//		bool init = true;
//		for(int i = 0; i < m_frames.size() ; i++)
//		{
//			if(!m_frames[i].image->IsInitial())
//			{
//				init = false;
//				break;
//			}
//		}
//		isInitial = init;
//	}
	float x = this->getX() + m_frames[m_index].offsetX;
	float y = this->getY() + m_frames[m_index].offsetY;
	m_frames[m_index].image->moveToAbsolute(x,y);
	m_frames[m_index].image->visit();
}