/*
 *  CBRotateAction.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/7.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBROTATEACTION_H_
#define _CBROTATEACTION_H_

#include "CBAction.h"

class CBRotateAction : public CBAction {
protected:
	float m_angle;
	void onAction(CBView* view);
	CBRotateAction();
public:
	CBRotateAction(float angle, double duration);
	CBRotateAction(float angle, double duration,int repeatTime);
	//CBRotateAction(float angle, double duration,int repeatTime,ActionLifeType lifeType);
    ~CBRotateAction() {}
	
	inline float getAngle() { return m_angle; }
	inline void setAngle(float angle) { m_angle = angle; }
};

#endif