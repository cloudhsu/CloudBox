/*
 *  CBTimerManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/10/10.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBTIMERMANAGER_H_
#define _CBTIMERMANAGER_H_

#include "CBSingleton.h"

#define SECOUND 1

class CBTimerManager : public CBSingleton<CBTimerManager>
{
private:
	double m_oldTime;
	double m_spanTime;
	
	float m_fps;
	int m_counter;
	float m_timer;
public:
	CBTimerManager();
	void initialTimer(double oldTime);
	void update(double time);
	inline float getSpanTime() { return m_spanTime; }
	inline float getFPS() { return m_fps;}
};

#define STimerManager CBTimerManager::instance()

#endif