/*
 *  CBController.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/7.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBController.h"
#include "CBLibrary.h"
#include "CBView.h"

CBController::CBController()
{
}
CBController::CBController(CBView* view):m_view(view)
{
}
CBController::~CBController()
{
	DELETE(m_view);
}