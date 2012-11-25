/*
 *  _CBDefBuilder.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/31.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBDEFBUILDER_H_
#define __CBBDEFUILDER_H_

#include "_CBBuilder.h"

class _CBDefBuilder : public _CBBuilder
{
private:
	// --- Add private member --- //
public:
	// --- Add public member --- //
	_CBDefBuilder();
	~_CBDefBuilder();
	
	GLuint ReloadText(const string& text, const float size);
    GLuint ReloadTexture(const string& filename);
	CBTexture* BuildTexture(const string& filename);
	CBTexture* BuildStringTexture(const string& text, const float size);
};

#endif