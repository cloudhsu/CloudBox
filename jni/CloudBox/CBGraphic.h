/*
 *  CBGraphic.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/09.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef __CBGRAPHIC_H__
#define __CBGRAPHIC_H__

#include "CBSingleton.h"
#include <string>
using namespace std;

class CBGraphicBase;

class CBGraphic : public CBSingleton<CBGraphic>
{
private:
    CBGraphicBase* m_impl;
public:
    CBGraphic();
    ~CBGraphic();

    // initial graphic
    void initial2D();
    void beforeRender();
    
    // for draw function
    void drawLine(float x1, float y1, float x2, float y2);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color, float size);
    void drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color);
    
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4);
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, float size);
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color);
    void drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color, float size);
    
    void drawRect(CBRect& rect);
    void drawRect(CBRect& rect,CBColor& color);
    
    void drawCircle(CBPoint& pt, float radius);
    void drawCircle(CBPoint& pt, float radius, CBColor& color);
    void drawCircle(CBPoint& pt, float radius, CBColor& color, bool filled);
    
    // for texture
    void render(CBView* view, CBTexture* texture);
	void renderString(CBView* view, CBTexture* texture);
};

#define SGraphic CBGraphic::instance()

#endif /* defined(_____PROJECTNAME_____CBGraphic__) */
