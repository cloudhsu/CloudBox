/*
 *  CBTouchManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBTOUCHMANAGER_H_
#define _CBTOUCHMANAGER_H_

#include "CBSingleton.h"
#include <vector>
using namespace std;

enum CBTouchType {
	TouchBegan,
	TouchMoved,
	TouchEnded
};

typedef struct _Touch
{
	CBTouchType type;
	float x;
	float y;
}TouchPoint;

class CBTouchManager : public CBSingleton<CBTouchManager>
{
private:
	vector<TouchPoint> m_touchs;
public:
	void touchBegan(float x, float y);
	void touchMoved(float x, float y);
	void touchEnded(float x, float y);
};

#define STouchManager CBTouchManager::instance()

#endif