/*
 *  CBTimer.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/10/10.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBTimerManager.h"
#include "CBLibrary.h"

CBTimerManager::CBTimerManager()
:m_counter(0),m_fps(0),m_timer(0.0)
{
}

void CBTimerManager::initialTimer(double oldTime)
{
	m_oldTime = oldTime;
}

void CBTimerManager::update(double time)
{
	m_spanTime = time - m_oldTime;
	m_oldTime = time;
	m_timer += m_spanTime;
	m_counter++;
	if(m_timer >= SECOUND)
	{
		m_timer -= SECOUND;
		m_fps = m_counter;
		m_counter = 0;
		DebugLog("fps:%.2f\n",m_fps);
	}
}