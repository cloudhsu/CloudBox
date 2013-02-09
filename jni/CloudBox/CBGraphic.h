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

class CBGraphicBase;

class CBGraphic
{
private:
    CBGraphicBase* m_impl;
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

#endif /* defined(_____PROJECTNAME_____CBGraphic__) */
