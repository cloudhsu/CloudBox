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
    void initial2D();
    
    // for draw function
    void drawLine();
    void drawRect();
    void drawCircle();
    
    // for texture
    void render();
    void renderString();
};

#endif
