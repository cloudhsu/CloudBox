/*
 *  CBTextCallback.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/19.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBTextCallback.h"
#include "CBCallbackDispatcher.h"

CBTextCallback::CBTextCallback()
:CBCallback()
{
}

CBTextCallback::~CBTextCallback()
{
}

void CBTextCallback::onCallback()
{
	m_delegate->invoke(m_text,m_size);
}

void CBTextCallback::invoke(const string& text, const float size)
{
	m_text = text;
	m_size = size;
	SCallbackDispatcher.registerRunOnce(const_cast<CBTextCallback*>(this));
}
