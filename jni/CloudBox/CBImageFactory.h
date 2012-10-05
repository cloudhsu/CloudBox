/*
 *  CBImageFactory.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/3/31.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBIMAGEFACTORY_H_
#define _CBIMAGEFACTORY_H_

#include "CBImageBase.h"
#include "CBGLImage.h"

class CBImageFactory
{
public:
	static CBImageBase* CreateImage()
	{
		return new CBGLImage();
	}
};

#endif