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
#include <GL/glut.h>
#elif __CBIOS__
// for ios
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#elif __CBANDROID__
// for android
#include <EGL/egl.h>
#include <GLES/gl.h>
#endif

#include "CBSingleton.h"
#include "CBLibrary.h"

class CBTexture;
class CBView;

class CBOpenGL : public CBSingleton<CBOpenGL>
{
private:
	GLint m_screenWidth;
	GLint m_screenHeight;
	void render(CBView* view, CBTexture* texture, GLfloat* coordinates,GLfloat* vertices);

	GLuint m_textureCounter;

public:
	CBOpenGL();
	~CBOpenGL();
	
	/////////////////////////////////////
	// Using for Android
	GLuint genTexture();
	void resetTextureCounter();
	/////////////////////////////////////

	GLuint generateTexture(GLvoid* data, int width, int height);

	
	void initialize2D();
	
	void beforeRender();
	
	void fillRect(CBRect rt, CBColor color);
	
	void fillScreen(float r, float g, float b);
	
	void setColor(CBColor color);
	
	void render(CBView* view, CBTexture* texture);
	void renderString(CBView* view, CBTexture* texture);
};

#define SOpenGL CBOpenGL::instance()

#endif
