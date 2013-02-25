/*
 *  CBSprite.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBSprite.h"
#include "CBAnimation.h"

CBSprite::CBSprite()
:m_CurrentAnimation(0)
{
}


CBSprite::~CBSprite()
{
	for (int i = 0; i < m_Animations.size(); i++) {
		CBDELETE(m_Animations[i].animation);
	}
	m_Animations.clear();
}

void CBSprite::playAnimation(int animationID)
{
	m_CurrentAnimation = animationID;
	m_Animations[m_CurrentAnimation].animation->resetAnimation();
}


void CBSprite::addAnimation(int animationID, CBAnimation* animation)
{
	Animation ani;
	ani.animationID = animationID;
	ani.animation = animation;
	m_Animations.push_back(ani);
	if(m_Animations.size() == 1)
	{
		this->setWidth(animation->getWidth());
		this->setHeight(animation->getHeight());
	}
}

void CBSprite::draw()
{
	if(!this->getVisible())
		return;
//	if(!isInitial)
//	{
//		bool init = true;
//		for(int i = 0; i < m_Animations.size() ; i++)
//		{
//			if(!m_Animations[i].animation->IsInitial())
//			{
//				init = false;
//				break;
//			}
//		}
//		isInitial = init;
//	}
	m_Animations[m_CurrentAnimation].animation->moveToAbsolute(this->getX(),this->getY());
	m_Animations[m_CurrentAnimation].animation->visit();
}
