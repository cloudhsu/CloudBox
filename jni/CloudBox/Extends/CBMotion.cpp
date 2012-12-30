//
//  CBMotion.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/5/20.
//  Copyright (c) 20122 Cloud Hsu. All rights reserved.
//

#include "CBMotion.h"
#include "CBMotionBase.h"
#ifdef __CBIOS__
#include "CBMotioniOS.h"
#elif __CBANDROID__
#include "../Android/CBMotionAndroid.h"
#else
#endif

CBMotion::CBMotion()
:m_isStartAcclermeter(false)
{
#ifdef CBMotionEnable
#ifdef __CBIOS__
	m_impl = new CBMotioniOS();
#elif __CBANDROID__
	m_impl = new CBMotionAndroid();
#else
	m_impl = new CBEmptyMotion();
#endif
#else
    m_impl = new CBEmptyMotion();
#endif
}

CBMotion::~CBMotion()
{
    stopAccelerometer();
	delete m_impl;
}

void CBMotion::startAccelerometer()
{
    m_impl->startAccelerometer();
    m_isStartAcclermeter = true;
}

void CBMotion::updateAccelerometer()
{
    if(m_isStartAcclermeter)
    {
        m_impl->updateAccelerometer();
    }
}

void CBMotion::updateAccelerometer(float x, float y, float z)
{
	if(m_isStartAcclermeter)
    {
        m_impl->updateAccelerometer(x, y, z);
    }
}

void CBMotion::stopAccelerometer()
{
    if(m_isStartAcclermeter)
    {
        m_impl->stopAccelerometer();
        m_isStartAcclermeter = false;
    }
}

CBAcceleration& CBMotion::getAcceleration()
{
    return m_impl->getAcceleration();
}

float CBMotion::getAccelerationX()
{
    return m_impl->getAccelerationX();
}
float CBMotion::getAccelerationY()
{
    return m_impl->getAccelerationY();
}
float CBMotion::getAccelerationZ()
{
    return m_impl->getAccelerationZ();
}
