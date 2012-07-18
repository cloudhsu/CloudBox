/*
 *  _CBDefBuilder.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/31.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "_CBDefBuilder.h"

_CBDefBuilder::_CBDefBuilder()
{
	// construct
}

_CBDefBuilder::~_CBDefBuilder()
{
	// Deconstruct
}

GLuint _CBDefBuilder::ReloadText(const string& text, const float size)
{
    return 0;
}

GLuint _CBDefBuilder::ReloadTexture(const string& filename)
{
    return 0;
}

CBTexture* _CBDefBuilder::BuildTexture(const string& filename)
{
	return NULL;
}

CBTexture* _CBDefBuilder::BuildStringTexture(const string& text, const float size)
{
	return NULL;
}