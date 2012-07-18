/*
 *  CBOpenGL.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/3/28.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBOPENGL_H_
#define _CBOPENGL_H_

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
#include "CBSingleton.h"
#include "CBLibrary.h"
#include "CBImageData.h"

class CBTexture;
class CBView;

class CBOpenGL : public CBSingleton<CBOpenGL>
{
private:
	GLint m_screenWidth;
	GLint m_screenHeight;
	void render(CBView* view, CBTexture* texture, GLfloat* coordinates,GLfloat* vertices);
public:
	CBOpenGL();
	~CBOpenGL();
	
	GLuint generateTexture(GLvoid* data, int width, int height);
	GLuint generateTexture(CBImageData* imageData);
	
	void initialize2D();
	
	void beforeRender();
	
	void render(CBTexture* texture,float x, float y, float width, float height);
	
	void fillRect(CBRect rt, CBColor color);
	
	void fillScreen(float r, float g, float b);
	
	void setColor(CBColor color);
	
	void render(CBView* view, CBTexture* texture);
	void renderString(CBView* view, CBTexture* texture);
};

#define SOpenGL CBOpenGL::instance()

#endif