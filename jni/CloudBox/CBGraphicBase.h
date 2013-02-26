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

class CBGraphicBase
{
private:
public:
    // initial graphic
    virtual void initial2D() = 0;
    
    // for draw function
    virtual void drawLine(CBPoint& ptStart,CBPoint& ptEnd) = 0;
    virtual void drawRect(CBRect& rect) = 0;
    virtual void drawCircle(CBPoint& pt, float radius) = 0;
    
    // for texture
    virtual void render() = 0;
    virtual void renderString() = 0;
};

#endif
