/*
 *  CBGraphic.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/02/09.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBLibrary.h"
#include "CBGraphic.h"

CBGraphic::CBGraphic()
{

}

CBGraphic::~CBGraphic()
{
    CBDELETE(m_impl);
}

// initial graphic
void CBGraphic::initial2D()
{
    m_impl->initial2D();
}

// for draw function
void CBGraphic::drawLine(CBPoint& ptStart,CBPoint& ptEnd)
{
    m_impl->drawLine(ptStart, ptEnd);
}
void CBGraphic::drawRect(CBRect& rect)
{
    m_impl->drawRect(rect);
}
void CBGraphic::drawCircle(CBPoint& pt, float radius)
{
    m_impl->drawCircle(pt, radius);
}

// for texture
void CBGraphic::render()
{
    m_impl->render();
}
void CBGraphic::renderString()
{
    m_impl->renderString();
}