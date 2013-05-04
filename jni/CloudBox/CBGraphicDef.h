/*
 *  CBGraphicDef.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/09.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBGRAPHICDEF_H__
#define __CBGRAPHICDEF_H__

#ifdef WIN32
// for win32
#include <GLES/gl.h>
#elif __CBIOS__
// for ios
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#elif __CBANDROID__
// for android
#include <EGL/egl.h>
#include <GLES/gl.h>
#endif

#ifdef __CBIOS__
#define __CBOPENGLES__
#elif __CBANDROID__
#define __CBOPENGLES__
#else
#define __CBDIRECTX__
#endif

#ifdef __CBOPENGL__
typedef GLbyte CBbyte;
typedef GLshort CBshort;
typedef GLint CBint;
typedef GLushort CBushort;
typedef GLuint CBuint;
typedef GLFloat CBfloat;
typedef GLdouble CBdouble;
typedef GLvoid CBvoid;
#elif __CBDIRECTX__
#else
typedef unsigned char CBbyte;
typedef short CBshort;
typedef int CBint;
typedef unsigned short CBushort;
typedef unsigned int CBuint;
typedef float CBfloat;
typedef double CBdouble;
typedef void CBvoid;
#endif

#endif
