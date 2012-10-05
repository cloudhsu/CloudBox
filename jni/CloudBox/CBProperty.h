/*
 *  CBProperty.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/8/9.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBPROPERTY_H_
#define _CBPROPERTY_H_

#include "CBAction.h"

class CBView;

enum ActionProperty
{
	ActionPropertyX = 0,
	ActionPropertyY = 1,
	ActionPropertyWidth = 2,
	ActionPropertyHeight = 3,
	ActionPropertyAngle = 4,
	ActionPropertyAlpha = 5
};

enum PropertyTransform
{
	PropertyIncrease = 0,
	PropertyReduce = 1
};

enum PropertyFromType
{
	PropertyFromCurrent,
	PropertyFromSetting
};

struct CBProperty
{
	ActionProperty property;
	PropertyFromType propertyFromType;
    PropertyTransform propertyTransform;
	float from;
	float to;
	float delta;
	CBProperty();
	CBProperty(ActionProperty _property, float _from, float _to, float _delta);
	CBProperty(ActionProperty _property, float _from, float _to, float _delta, PropertyFromType fromType);

    void transit(CBView* view);
    void initial(CBView* view);
    bool checkFinish(CBView* view);
private:
	void setProperty(CBView* view, ActionProperty property, float newValue);
    float getCurrentProperty(CBView* view);
    void checkTransform();
};

#endif