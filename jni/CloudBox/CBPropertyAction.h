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
#include "CBProperty.h"

class CBPropertyAction : public CBAction {
protected:
	//PropertyTransform m_transform;
	CBProperty m_property;
	
	//float getCurrent(CBView* view);
	
	void onAction(CBView* view);
	void checkFinish();
	//void setProperty(CBView* view, ActionProperty property, float newValue);
	//void transformProperty(CBView* view, ActionProperty property, float transformValue);
	//void checkTransform();
public:
	CBPropertyAction();
	CBPropertyAction(CBProperty property, double duration);
	//CBPropertyAction(Property property, double duration, ActionLifeType lifeType);
    virtual ~CBPropertyAction() {}
	
//	void commit(CBView* target, float to);
//	void commit(CBView* target, float from, float to);
	
	void commit(CBView* target);
	
//	inline float getProperty() { return m_property.property; }
//	inline void setProperty(ActionProperty property) { m_property.property = property; }
//	
//	inline float getFromType() { return m_property.propertyFromType; }
//	inline void setFromType(PropertyFromType fromType) { m_property.propertyFromType = fromType; }
//	
//	inline float getFrom() { return m_property.from; }
//	inline void setFrom(float from) { m_property.from = from; }
//	
//	inline float getTo() { return m_property.to; }
//	inline void setTo(float to) { m_property.to = to; }
//	
//	inline float getDelta() { return m_property.delta; }
//	inline void setDelta(float delta) { m_property.delta = delta; checkTransform(); }
};

#endif
