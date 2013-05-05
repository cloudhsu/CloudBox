/*
 *  CBGraphicBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/09.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBGRAPHICBASE_H__
#define __CBGRAPHICBASE_H__

#include "CBLibrary.h"

class CBView;
class CBTexture;

class CBGraphicBase
{
private:
public:
    CBGraphicBase() {}
    virtual ~CBGraphicBase(){}
    // initial graphic
    virtual void initial2D() = 0;
    
    virtual void beforeRender() = 0;
    
    // for draw function
    virtual void drawLine(CBPoint& ptStart, CBPoint& ptEnd) = 0;
    virtual void drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size) = 0;
    virtual void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color, float size) = 0;
    virtual void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color) = 0;
    
    virtual void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4) = 0;
    virtual void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, float size) = 0;
    virtual void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color) = 0;
    virtual void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color, float size) = 0;
    
    virtual void drawRect(CBRect& rect) = 0;
    virtual void drawRect(CBRect& rect,CBColor& color) = 0;
    
    virtual void drawCircle(CBPoint& pt, float radius) = 0;
    virtual void drawCircle(CBPoint& pt, float radius, CBColor& color) = 0;
    virtual void drawCircle(CBPoint& pt, float radius, CBColor& color, bool filled) = 0;
    
    // for texture
    virtual void render(CBView* view, CBTexture* texture) = 0;
	virtual void renderString(CBView* view, CBTexture* texture) = 0;
};

class CBGraphicSimulator : public CBGraphicBase
{
private:
public:
    CBGraphicSimulator() {}
    ~CBGraphicSimulator() {}
    // initial graphic
    void initial2D(){}
    void beforeRender() {}

    // for draw function
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd){}
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size){}
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color, float size){}
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color){}
    
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4) {}
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, float size) {}
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color) {}
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color, float size) {}
    
    void drawRect(CBRect& rect){}
    void drawRect(CBRect& rect,CBColor& color){}
    
    void drawCircle(CBPoint& pt, float radius) {}
    void drawCircle(CBPoint& pt, float radius, CBColor& color) {}
    void drawCircle(CBPoint& pt, float radius, CBColor& color, bool filled) {}

    // for texture
    void render(CBView* view, CBTexture* texture) {}
	void renderString(CBView* view, CBTexture* texture) {}
};

#endif
