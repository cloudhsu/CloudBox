/*
 *  CBComposeAction.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/8/9.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBComposeAction.h"
#include "CBProperty.h"

CBComposeAction::CBComposeAction()
:CBAction()
{
}

CBComposeAction::CBComposeAction(double duration,int repeatTime)
:CBAction(duration, repeatTime)
{
}

CBComposeAction::~CBComposeAction()
{
    m_properties.clear();
}

void CBComposeAction::onAction(CBView* view)
{
	//view->rotate(m_angle);
    for(int i = 0 ; i < m_properties.size();i++)
    {
        m_properties[i].transit(m_target);
    }
}

void CBComposeAction::checkFinish()
{
    bool finish = true;
    for(int i = 0 ; i < m_properties.size();i++)
    {
        finish = m_properties[i].checkFinish(m_target);
        if(finish == false)
            break;
    }
    if(finish)
    {
		finishAction();
	}
}

void CBComposeAction::commit(CBView* target)
{
    for(int i = 0 ; i < m_properties.size();i++)
    {
        m_properties[i].transit(target);
    }
	CBAction::commit(target);
}

void CBComposeAction::addProperty(CBProperty& property)
{
    m_properties.push_back(property);
}