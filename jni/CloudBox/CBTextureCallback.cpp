/*
 *  CBOnceCallback.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/19.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBTextureCallback.h"
#include "CBCallbackDispatcher.h"

CBTextureCallback::CBTextureCallback()
:CBCallback()
{
}

CBTextureCallback::~CBTextureCallback()
{
}

void CBTextureCallback::onCallback()
{
	m_delegate->invoke(m_imageData);
}

void CBTextureCallback::invoke(CBImageData* imageData)
{
	m_imageData = imageData;
	SCallbackDispatcher.registerRunOnce(const_cast<CBTextureCallback*>(this));
}
