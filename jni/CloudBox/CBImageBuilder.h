/*
 *  CBImageBuilder.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/4.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBIMAGEBUILDER_H_
#define _CBIMAGEBUILDER_H_

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
#include "CBImageData.h"
#include <iostream>
using namespace std;

#define TEXTURE_SIZE 256

class CBImageBuilder
{
public:
	CBImageBuilder(){}
	virtual ~CBImageBuilder(){}
	
	virtual CBImageData* loadImageData(const string& fileName) = 0;
	virtual CBImageData* loadTextData(const string& text, float size) = 0;
	
	virtual void releaseImage(GLvoid* data) = 0;
};

#endif