/*
 *  CBActionManager.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBActionManager.h"
#include "CBAction.h"

CBActionManager::CBActionManager()
:m_generateID(1)
{
}
CBActionManager::~CBActionManager()
{
	clear();
}

void CBActionManager::registerAction(CBAction* action)
{
	if(action->getID() == NOT_EXIST)
	{
		action->setID(++m_generateID);
		m_actions.push_back(action);
	}
}

void CBActionManager::clear()
{
	for(int i = 0 ; i < m_actions.size() ; i++)
	{
		CBDELETE(m_actions[i]);
	}
	m_actions.clear();
}

void CBActionManager::removeAction(CBAction* action)
{
	for(int i = 0 ; i < m_actions.size() ; i++)
	{
		if(m_actions[i]->getID() == action->getID())
		{
			CBDELETE(m_actions[i]);
			m_actions.erase(m_actions.begin()+i);
			break;
		}
	}
}
void CBActionManager::update()
{
	for(int i = 0 ; i < m_actions.size() ; i++)
	{
		m_actions[i]->notify();
	}
}