/*
 *  CBMotionAndroid.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/6/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include <jni.h>
#include "../Extends/CBMotionBase.h"
#include "CBJNI.h"

class CBMotionAndroid : public CBMotionBase, public CBJNI
{
private:
	jmethodID m_start;
	jmethodID m_stop;
public:
	CBMotionAndroid();
	~CBMotionAndroid();
	void startAccelerometer();
	void updateAccelerometer();
	void stopAccelerometer();
};
