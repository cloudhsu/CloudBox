/*
 *  CBSceneController.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/17.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBSCENECONTROLLER_H_
#define _CBSCENECONTROLLER_H_

#include "CBController.h"

class CBSceneController : public CBObject
{
protected:
	CBSceneController();
public:
	CBSceneController(CBView* view);
	virtual ~CBSceneController();
	
	//virtual initialize();
};

#endif