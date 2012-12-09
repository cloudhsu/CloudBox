/*
 *  CBImageBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/3/31.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBIMAGEBASE_H_
#define _CBIMAGEBASE_H_

#include <iostream>
using namespace std;

class CBView;

class CBImageBase
{
protected:

public:
	CBImageBase(){}
	virtual ~CBImageBase(){}
	
	virtual void draw(CBView* view) = 0;
	virtual void loadImage(const string& fileName, float& width, float& height) = 0;
	virtual void createTextImage(const string& text,float size, float& width, float& height) = 0;
};


#endif