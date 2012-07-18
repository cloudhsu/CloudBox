/*
 *  CBAction.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAction.h"
#include "IAction.h"
#include "CBCmd.h"
#include "CBLibrary.h"
#include "CBActionManager.h"
#include "CBTimerManager.h"

CBAction::CBAction()
: IAction(),
m_repeatTime(1), m_timer(0.0), m_duration(0.1),
m_status(ActionInit)
{
}

CBAction::CBAction(double duration)
: IAction(),
m_repeatTime(1), m_timer(0.0), m_duration(duration),
m_status(ActionInit)
{
}
CBAction::CBAction(double duration,int repeatTime)
: IAction(),
m_repeatTime(repeatTime), m_timer(0.0), m_duration(duration),
m_status(ActionInit)
{
}

//CBAction::CBAction(double duration,int repeatTime,ActionLifeType lifeType)
//: IAction(),
//m_repeatTime(repeatTime), m_timer(0.0), m_duration(duration),
//m_status(ActionInit), m_lifeType(lifeType)
//{
//}

CBAction::~CBAction()
{
}

//void CBAction::commit()
//{
//	commit(NULL);
//}

void CBAction::commit(CBView* target)
{
	m_target = target;
	m_status = ActionRunning;
	m_timer = 0.0;
	m_counter = 0;
    SActionManager.registerAction(this);
}

void CBAction::commit(CBView* target, int repeatTime)
{
	m_repeatTime = repeatTime;
	commit(target);
}

//void CBAction::commit(CBView* target, int repeatTime,ActionLifeType lifeType)
//{
//	m_lifeType = lifeType;
//	commit(target,repeatTime);
//}

void CBAction::stop()
{
	m_status = ActionStop;
	m_timer = 0.0f;
	m_counter = 0;
}

void CBAction::onAction(CBView* view)
{
}

void CBAction::checkFinish()
{
	if(m_repeatTime != REPEAT_ALWAYS && m_counter >= m_repeatTime)
	{
		finishAction();
	}
}

void CBAction::finishAction()
{
	onFinish();
	m_status = ActionFinish;
}

void CBAction::checkTrigger()
{
	m_timer += STimerManager.getSpanTime();
	if(m_timer >= m_duration)
	{
		m_timer -= m_duration;
		m_counter++;
		onAction(m_target);
		onTrigger();
	}
}

void CBAction::finish()
{
    finishAction();
}

void CBAction::notify()
{
	if(m_status == ActionRunning)
	{
		checkTrigger();
		checkFinish();
	}
}