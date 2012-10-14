/*
 *  CBAction.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBACTION_H_
#define _CBACTION_H_

#include "IAction.h"

class IAction;
class CBCmd;

#define REPEAT_ALWAYS -1

enum ActionStatus
{
	ActionInit = 0,
	ActionRunning = 1,
	ActionStop = 2,
	ActionFinish = 3
};

//enum ActionLifeType
//{
//	ActionAutoRelease = 0,
//	ActionManualRelease = 1
//};

class CBAction : public IAction
{
protected:
	//ActionLifeType m_lifeType;
	ActionStatus m_status;
	double m_timer;
	int m_counter;
	int m_repeatTime;
	double m_duration;
	virtual void onAction(CBView* view);
	virtual void checkFinish();
	void checkTrigger();
	void finishAction();
public:
	CBAction();
	CBAction(double duration);
	CBAction(double duration,int repeatTime);
	//CBAction(double duration,int repeatTime,ActionLifeType lifeType);
	virtual ~CBAction();
//	void commit();
	virtual void commit(CBView* target);
	virtual void commit(CBView* target, int repeatTime);
	//virtual void commit(CBView* target, int repeatTime,ActionLifeType lifeType);
	void notify();
    void stop();
    void finish();
    
    void setDuration(double duration) { m_duration = duration; }
	
	inline const ActionStatus getStatus() { return m_status; }
};

#endif