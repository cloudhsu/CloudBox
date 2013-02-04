/*
 *  CBAndroidMotion.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/6/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBMOTIONANDROID_H_
#define _CBMOTIONANDROID_H_

#include <jni.h>
#include "../Extends/CBMotionBase.h"
#include "CBJNI.h"

class CBAndroidMotion : public CBMotionBase, public CBJNI
{
private:
	jmethodID m_start;
	jmethodID m_stop;
public:
	CBAndroidMotion();
	~CBAndroidMotion();
	void startAccelerometer();
	void updateAccelerometer();
	void stopAccelerometer();
};

#endif
