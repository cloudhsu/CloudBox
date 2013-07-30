/*
 *  CBGLGraphic.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/05/04.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBGLGRAPHIC_H__
#define __CBGLGRAPHIC_H__

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
#include "CBGraphicBase.h"

class CBGLGraphic : public CBGraphicBase
{
private:
    float m_screenWidth;
    float m_screenHeight;
    void drawLines(GLfloat* vtx, CBColor& color, float siz);
    void drawRect(GLfloat* vtx, CBColor& color);
    void drawLineLoop(GLfloat* vtx, CBColor& color, float siz);
    void drawEllipse(int seg,float w,float h,float px,float py,float pz,bool filled, CBColor& color);
    void render(CBView* view, CBTexture* texture, GLfloat* coordinates,GLfloat* vertices);
    void setColor(CBColor color);
public:
    CBGLGraphic();
    ~CBGLGraphic();
    // initial graphic
    void initial2D();
    void beforeRender();
    
    // for draw function
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color, float size);
    
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4);
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, float size);
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color);
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color, float size);
    
    void drawRect(CBRect& rect);
    void drawRect(CBRect& rect,CBColor& color);
    void fillScreen(float r, float g, float b);
    
    void drawCircle(CBPoint& pt, float radius);
    void drawCircle(CBPoint& pt, float radius, CBColor& color);
    void drawCircle(CBPoint& pt, float radius, CBColor& color, bool filled);
    
    // for texture
    void render(CBView* view, CBTexture* texture);
	void renderString(CBView* view, CBTexture* texture);
};

#endif
