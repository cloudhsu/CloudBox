/*
 *  CBPropertyAction.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/7.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBPropertyAction.h"
#include <cmath>

CBPropertyAction::CBPropertyAction()
{
}

CBPropertyAction::CBPropertyAction(CBProperty property, double duration)
:CBAction(duration,REPEAT_ALWAYS),
m_property(property)
{
//	checkTransform();
}
//CBPropertyAction::CBPropertyAction(Property property, double duration, ActionLifeType lifeType)
//:CBAction(duration, REPEAT_ALWAYS, lifeType),
//m_property(property)
//{
//	checkTransform();
//}

//void CBPropertyAction::transformProperty(CBView* view, ActionProperty property, float transformValue)
//{
//	switch (property) {
//		case ActionPropertyX:
//			view->move(transformValue, 0.0);
//			break;
//		case ActionPropertyY:
//			view->move(0.0, transformValue);
//			break;
//		case ActionPropertyWidth:
//			view->scaleWidth(transformValue);
//			break;
//		case ActionPropertyHeight:
//			view->scaleHeight(transformValue);
//			break;
//		case ActionPropertyAngle:
//			view->rotate(transformValue);
//			break;
//		case ActionPropertyAlpha:
//			view->transparent(transformValue);
//			break;
//		default:
//			DebugLog("The property action is not support.\n");
//			break;
//	}
//}

//void CBPropertyAction::setProperty(CBView* view, ActionProperty property, float newValue)
//{
//	switch (property) {
//		case ActionPropertyX:
//			view->setX(newValue);
//			break;
//		case ActionPropertyY:
//			view->setY(newValue);
//			break;
//		case ActionPropertyWidth:
//			view->setWidth(newValue);
//			break;
//		case ActionPropertyHeight:
//			view->setHeight(newValue);
//			break;
//		case ActionPropertyAngle:
//			view->setAngle(newValue);
//			break;
//		case ActionPropertyAlpha:
//			view->setAlpha(newValue);
//			break;
//		default:
//			DebugLog("The property action is not support.\n");
//			break;
//	}
//}

void CBPropertyAction::onAction(CBView* view)
{
	//transformProperty(view, m_property.property,m_property.delta);
    m_property.transit(view);
}

void CBPropertyAction::checkFinish()
{
	if( m_property.checkFinish(m_target) )
	{
		finishAction();
	}
}

//float CBPropertyAction::getCurrent(CBView* view)
//{
//	float currentValue = 0.0;
//	switch (m_property.property) {
//		case ActionPropertyX:
//			currentValue = view->getX();
//			break;
//		case ActionPropertyY:
//			currentValue = view->getY();
//			break;
//		case ActionPropertyWidth:
//			currentValue = view->getWidth();
//			break;
//		case ActionPropertyHeight:
//			currentValue = view->getHeight();
//			break;
//		case ActionPropertyAngle:
//			currentValue = view->getAngle();
//			break;
//		case ActionPropertyAlpha:
//			currentValue = view->getAlpha();
//			break;
//		default:
//			DebugLog("It can't get from value for current property.\n");
//			break;
//	}
//	return currentValue;
//}

//void CBPropertyAction::commit(CBView* target, float to)
//{
//	float from = getCurrent(target);
//	commit(target, from, to);
//}
//void CBPropertyAction::commit(CBView* target, float from, float to)
//{
//	m_property.from = from;
//	m_property.to = to;
//	checkTransform();
//	CBAction::commit(target);
//}

void CBPropertyAction::commit(CBView* target)
{
//	if(m_property.propertyFromType == PropertyFromSetting)
//		setProperty(m_target,m_property.property,m_property.from);
    m_property.initial(target);
	CBAction::commit(target);
}

//void CBPropertyAction::checkTransform()
//{
//	if(m_property.from < m_property.to)
//	{
//		m_property.delta = abs(m_property.delta);
//		m_transform = PropertyIncrease;
//	}
//	else
//	{
//		m_property.delta = abs(m_property.delta) * -1;
//		m_transform = PropertyReduce;
//	}
//}
