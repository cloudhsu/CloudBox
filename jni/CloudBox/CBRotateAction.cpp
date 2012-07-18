/*
 *  CBRotateAction.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/7.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBRotateAction.h"

CBRotateAction::CBRotateAction()
:CBAction()
{
}

CBRotateAction::CBRotateAction(float angle, double duration)
:CBAction(duration),m_angle(angle)
{
}
CBRotateAction::CBRotateAction(float angle, double duration,int repeatTime)
:CBAction(duration, repeatTime),m_angle(angle)
{
}

//CBRotateAction::CBRotateAction(float angle, double duration,int repeatTime,ActionLifeType lifeType)
//:CBAction(duration, repeatTime,lifeType),m_angle(angle)
//{
//}

void CBRotateAction::onAction(CBView* view)
{
	view->rotate(m_angle);
}