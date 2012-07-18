/*
 *  CBEvent.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/6.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBEVENT_H_
#define _CBEVENT_H_

enum CBEventType
{
	EventEmpty = 0,
	EventOnClick = 1,
	EventOnTouchBegan = 2,
	EventOnTouchMoved = 3,
	EventOnTouchEnded = 4
};

class CBEvent
{
protected:
	CBEventType m_eventType;
	float m_x;
	float m_y;
public:
	CBEvent()
	{
		m_eventType = EventEmpty;
	}
	CBEvent(CBEventType eventType)
	{
		m_eventType = eventType;
	}
	CBEvent(CBEventType eventType,float x, float y)
	{
		m_eventType = eventType;
		m_x = x;
		m_y = y;
	}
	~CBEvent(){}
	
	inline const CBEventType getEventType() { return m_eventType; }
	inline const float getTouchX() { return m_x; }
	inline const float getTouchY() { return m_y; }
};

#endif