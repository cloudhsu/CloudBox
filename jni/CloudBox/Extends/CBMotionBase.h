//
//  CBMotionBase.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/5/20.
//  Copyright (c) 2012 Cloud Hsu. All rights reserved.
//

#ifndef _CBMOTIONBASE_h_
#define _CBMOTIONBASE_h_

#include "CBConfig.h"
#include "CBLibrary.h"

class CBMotionBase
{
protected:
    CBAcceleration m_accleration;
public:
    CBMotionBase() {}
    virtual ~CBMotionBase() {}
    virtual void startAccelerometer() = 0;
    virtual void updateAccelerometer() = 0;
    virtual void stopAccelerometer() = 0;
    
    void updateAccelerometer(float x, float y, float z)
    {
    	m_accleration.x = x;
    	m_accleration.y = y;
    	m_accleration.z = z;
    }

    CBAcceleration& getAcceleration() { return m_accleration; }
    double getAccelerationX() { return  m_accleration.x; }
    double getAccelerationY() { return  m_accleration.y; }
    double getAccelerationZ() { return  m_accleration.z; }
};

class CBMotionSimulator : public CBMotionBase
{
public:
    CBMotionSimulator() {}
	~CBMotionSimulator() {}
    
    void startAccelerometer() {}
    void updateAccelerometer() {}
    void stopAccelerometer() {}
};

#endif
