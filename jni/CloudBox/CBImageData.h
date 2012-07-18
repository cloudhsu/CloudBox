/*
 *  CBImageData.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/4.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBIMAGEDATA_H_
#define _CBIMAGEDATA_H_

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
#include "CBLibrary.h"
#include <iostream>
using namespace std;

typedef enum {
	CBTexture2DPixelFormat_Automatic = 0,
	CBTexture2DPixelFormat_RGBA8888,
	CBTexture2DPixelFormat_RGB565,
	CBTexture2DPixelFormat_A8,
} CBTexture2DPixelFormat;

struct CBImageData
{
	float imageWidth;
	float imageHeight;
	float textureWidth;
	float textureHeight;
	CBTexture2DPixelFormat pixelFormat;
	GLvoid* data;
	GLuint textureID;
	
	string key;
	string text;
	float size;
	bool isText;
	
	CBImageData()
	{
		pixelFormat = CBTexture2DPixelFormat_RGBA8888;
		data = NULL;
	}
	~CBImageData()
	{
		free(data);
	}
};

#endif
