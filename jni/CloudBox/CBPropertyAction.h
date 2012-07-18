/*
 *  CBPropertyAction.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/7.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBPROPERTYACTION_H_
#define _CBPROPERTYACTION_H_

#include "CBAction.h"

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

typedef struct _Property
{
	ActionProperty property;
	PropertyFromType propertyFromType;
	float from;
	float to;
	float delta;
	_Property()
	{
		property = ActionPropertyAlpha;
		propertyFromType = PropertyFromSetting;
		from = 0;
		to = 1;
		delta = 0.1;
	}
	_Property(ActionProperty _property, float _from, float _to, float _delta)
	{
		property = _property;
		propertyFromType = PropertyFromSetting;
		from = _from;
		to = _to;
		delta = _delta;
	}
	_Property(ActionProperty _property, float _from, float _to, float _delta, PropertyFromType fromType)
	{
		property = _property;
		propertyFromType = fromType;
		from = _from;
		to = _to;
		delta = _delta;
	}
}Property;

class CBPropertyAction : public CBAction {
protected:
	PropertyTransform m_transform;
	Property m_property;
	CBPropertyAction();
	
	float getCurrent(CBView* view);
	
	void onAction(CBView* view);
	void checkFinish();
	void setProperty(CBView* view, ActionProperty property, float newValue);
	void transformProperty(CBView* view, ActionProperty property, float transformValue);
	void checkTransform();
public:
	CBPropertyAction(Property property, double duration);
	//CBPropertyAction(Property property, double duration, ActionLifeType lifeType);
	
//	void commit(CBView* target, float to);
//	void commit(CBView* target, float from, float to);
	
	void commit(CBView* target);
	
	inline float getProperty() { return m_property.property; }
	inline void setProperty(ActionProperty property) { m_property.property = property; }
	
	inline float getFromType() { return m_property.propertyFromType; }
	inline void setFromType(PropertyFromType fromType) { m_property.propertyFromType = fromType; }
	
	inline float getFrom() { return m_property.from; }
	inline void setFrom(float from) { m_property.from = from; checkTransform(); }
	
	inline float getTo() { return m_property.to; }
	inline void setTo(float to) { m_property.to = to; checkTransform(); }
	
	inline float getDelta() { return m_property.delta; }
	inline void setDelta(float delta) { m_property.delta = delta; checkTransform(); }
};

#endif