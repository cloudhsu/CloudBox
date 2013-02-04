//
//  CBMotion.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/5/20.
//  Copyright (c) 2012 Cloud Hsu. All rights reserved.
//

#ifndef _CBMOTION_H_
#define _CBMOTION_H_

#ifdef __CBIOS__
#include "CBSingleton.h"
#include "CBLibrary.h"
#else
#include "../CBSingleton.h"
#include "../CBLibrary.h"
#endif

class CBMotionBase;

class CBMotion : public CBSingleton<CBMotion>
{
private:
    CBMotionBase* m_impl;
    bool m_isStartAcclermeter;
public:
    CBMotion();
    ~CBMotion();
    
    void startAccelerometer();
    void updateAccelerometer();
    void updateAccelerometer(float x, float y, float z);
    void stopAccelerometer();
    
    CBAcceleration& getAcceleration();
    float getAccelerationX();
    float getAccelerationY();
    float getAccelerationZ();
};

#define SMotion CBMotion::instance()

#endif
