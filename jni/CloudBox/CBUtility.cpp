/*
 *  CBUtility.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/6/16.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBUtility.h"
#include "CBUtilityBase.h"
#include <math.h>

CBUtility::CBUtility()
{
	m_utility = new CBNoneUtility();
}
CBUtility::~CBUtility()
{
	delete m_utility;
}

string CBUtility::getFilePath()
{
	return m_utility->getFilePath();
}

string CBUtility::getLanguage()
{
	return m_utility->getLanguage();
}

DeviceType CBUtility::getDeviceType()
{
    return m_utility->getDeviceType();
}

int CBUtility::rand()
{
#ifdef __CBIOS__
    return abs((int)arc4random());
#else
    return rand();
#endif
}