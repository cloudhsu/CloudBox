/*
 *  CBProperty.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/8/9.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBProperty.h"
#include <cmath>

CBProperty::CBProperty()
{
    property = ActionPropertyAlpha;
    propertyFromType = PropertyFromSetting;
    from = 0;
    to = 1;
    delta = 0.1;
}
CBProperty::CBProperty(ActionProperty _property, float _from, float _to, float _delta)
{
    property = _property;
    propertyFromType = PropertyFromSetting;
    from = _from;
    to = _to;
    delta = _delta;
    checkTransform();
}
CBProperty::CBProperty(ActionProperty _property, float _from, float _to, float _delta, PropertyFromType fromType)
{
    property = _property;
    propertyFromType = fromType;
    from = _from;
    to = _to;
    delta = _delta;
    checkTransform();
}

void CBProperty::transit(CBView* view)
{
    switch (property) {
		case ActionPropertyX:
			view->move(delta, 0.0);
			break;
		case ActionPropertyY:
			view->move(0.0, delta);
			break;
		case ActionPropertyWidth:
			view->scaleWidth(delta);
			break;
		case ActionPropertyHeight:
			view->scaleHeight(delta);
			break;
		case ActionPropertyAngle:
			view->rotate(delta);
			break;
		case ActionPropertyAlpha:
			view->transparent(delta);
			break;
		default:
			DebugLog("The property action is not support.\n");
			break;
	}
}

void CBProperty::initial(CBView* view)
{
    if(propertyFromType == PropertyFromSetting)
		setProperty(view,property,from);
}
bool CBProperty::checkFinish(CBView* view)
{
    bool finish = false;
    float currentValue = getCurrentProperty(view);
	if( (propertyTransform == PropertyIncrease && currentValue >= to) ||
       (propertyTransform == PropertyReduce && currentValue <= to) )
	{
		setProperty(view,property,to);
        finish = true;
	}
    return finish;
}
void CBProperty::setProperty(CBView* view, ActionProperty property, float newValue)
{
    switch (property) {
		case ActionPropertyX:
			view->setX(newValue);
			break;
		case ActionPropertyY:
			view->setY(newValue);
			break;
		case ActionPropertyWidth:
			view->setWidth(newValue);
			break;
		case ActionPropertyHeight:
			view->setHeight(newValue);
			break;
		case ActionPropertyAngle:
			view->setAngle(newValue);
			break;
		case ActionPropertyAlpha:
			view->setAlpha(newValue);
			break;
		default:
			DebugLog("The property action is not support.\n");
			break;
	}
}

float CBProperty::getCurrentProperty(CBView* view)
{
	float currentValue = 0.0;
	switch (property) {
		case ActionPropertyX:
			currentValue = view->getX();
			break;
		case ActionPropertyY:
			currentValue = view->getY();
			break;
		case ActionPropertyWidth:
			currentValue = view->getWidth();
			break;
		case ActionPropertyHeight:
			currentValue = view->getHeight();
			break;
		case ActionPropertyAngle:
			currentValue = view->getAngle();
			break;
		case ActionPropertyAlpha:
			currentValue = view->getAlpha();
			break;
		default:
			DebugLog("It can't get from value for current property.\n");
			break;
	}
	return currentValue;
}
void CBProperty::checkTransform()
{
	if(delta > 0)
        propertyTransform = PropertyIncrease;
    else if(delta < 0)
        propertyTransform = PropertyReduce;
}