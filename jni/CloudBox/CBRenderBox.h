//
//  CBRenderBox.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/26.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#ifndef _CBRENDERBOX_H_
#define _CBRENDERBOX_H_

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
#include "CBDevice.h"
#include "CBLibrary.h"
#include "CBSingleton.h"

class CBImage;
class CBString;

class CBRenderBox : public CBSingleton<CBRenderBox>
{
protected:
	// --- Add private member --- //
	GLint m_screenWidth;
	GLint m_screenHeight;
    
    bool m_isRetina;

	CBOrientation m_orientation;
	
	void fillRect(CBRect rt, CBColor color);
	void render(GLfloat* coordinates,GLfloat* vertices);
	void renderImage(CBImage* image,GLfloat* coordinates,GLfloat* vertices);
public:
	// --- Add public member --- //
	CBRenderBox();
	~CBRenderBox();
	//void setScreen(GLint screenWidth,GLint screenHeight,CBOrientation orientation);
	//void initialize();
	
	void beginRender();
    
    inline const bool isRetina() { return m_isRetina; }
    
    //void retinaDisplay() { m_isRetina = true; }
	
	void fillScreen(float r, float g, float b);
	
	void render(CBImage* image, float x, float y);
	void render(CBImage* image);
	
	void renderString(CBString* image);
	void renderString(CBString* image, float x, float y);

	inline const float getScreenWidth() { return (float)m_screenWidth; }
	inline const float getScreenHeight() { return (float)m_screenHeight; }
};

#define SRenderBox CBRenderBox::instance()

#endif
