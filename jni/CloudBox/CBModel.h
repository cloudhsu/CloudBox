/*
 *  CBModel.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/7.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBMODEL_H_
#define _CBMODEL_H_

#include "CBCore.h"

class CBModel : public CBObject
{
protected:
public:
	CBModel();
	virtual ~CBModel();
	
	virtual void notify() = 0;
};

#endif