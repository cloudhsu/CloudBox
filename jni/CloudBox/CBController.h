/*
 *  CBController.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/7.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBCONTROLLER_H_
#define _CBCONTROLLER_H_

#include "CBCore.h"

class CBView;
class CBModel;

class CBController : public CBObject
{
protected:
	CBView* m_view;
	CBController();
public:
	CBController(CBView* view);
	virtual ~CBController();
	
	//virtual initialize();
};

#endif