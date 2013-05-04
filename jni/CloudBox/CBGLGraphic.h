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

#include "CBOpenGL.h"
#include "CBGraphicBase.h"

class CBGLGraphic : public CBGraphicBase
{
private:
    void drawLines(GLfloat* vtx, GLfloat* col, float siz);
    void drawLineLoop(GLfloat* vtx, GLfloat* col, float siz);
public:
    CBGLGraphic();
    ~CBGLGraphic();
    // initial graphic
    void initial2D();
    
    // for draw function
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor color, float size);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor color);
    void drawRect(CBRect& rect);
    void drawCircle(CBPoint& pt, float radius);
    
    // for texture
    void render();
    void renderString();
};

#endif
