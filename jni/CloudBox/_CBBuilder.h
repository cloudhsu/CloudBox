/*
 *  CBAbstractBuilder.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBBUILDER_H_
#define __CBBUILDER_H_

#ifdef WIN32
// for win32
#include <GLES/gl.h>
#elif __CBIOS__
// for ios
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#else
// for android
#include <EGL/egl.h>
#include <GLES/gl.h>
#endif
#include <string>
using namespace std;

class CBTexture;

class _CBBuilder
{
private:
	// --- Add private member --- //
public:
	_CBBuilder();
	~_CBBuilder();
	// --- Add public member --- //
	virtual GLuint ReloadText(const string& text, const float size) = 0;
    virtual GLuint ReloadTexture(const string& filename) = 0;
	virtual CBTexture* BuildTexture(const string& filename) = 0;
	virtual CBTexture* BuildStringTexture(const string& text, const float size) = 0;
};

#endif