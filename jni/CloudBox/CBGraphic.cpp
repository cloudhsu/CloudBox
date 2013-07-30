/*
 *  CBGraphic.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/02/09.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBGraphicBase.h"
#include "CBGraphic.h"
#include "CBGLGraphic.h"

CBGraphic::CBGraphic()
{
    m_impl = new CBGLGraphic();
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

void CBGraphic::beforeRender()
{
    m_impl->beforeRender();
}

// for draw line function
void CBGraphic::drawLine(float x1, float y1, float x2, float y2)
{
    CBPoint p1;
    p1.x = x1;
    p1.y = y1;
    CBPoint p2;
    p2.x = x2;
    p2.y = y2;
    drawLine(p1,p2);
}
void CBGraphic::drawLine(CBPoint& ptStart,CBPoint& ptEnd)
{
    m_impl->drawLine(ptStart, ptEnd);
}
void CBGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size)
{
    m_impl->drawLine(ptStart, ptEnd, size);
}
void CBGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color, float size)
{
    m_impl->drawLine(ptStart, ptEnd, color, size);
}
void CBGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color)
{
    m_impl->drawLine(ptStart, ptEnd, color);
}

void CBGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4)
{
    m_impl->drawLineLoop(p1, p2, p3, p4);
}
void CBGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, float size)
{
    m_impl->drawLineLoop(p1, p2, p3, p4, size);
}
void CBGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color)
{
    m_impl->drawLineLoop(p1, p2, p3, p4, color);
}
void CBGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color, float size)
{
    m_impl->drawLineLoop(p1, p2, p3, p4, color, size);
}

void CBGraphic::drawRect(CBRect& rect)
{
    m_impl->drawRect(rect);
}
void CBGraphic::drawRect(CBRect& rect,CBColor& color)
{
    m_impl->drawRect(rect, color);
}
void CBGraphic::drawCircle(CBPoint& pt, float radius)
{
    m_impl->drawCircle(pt, radius);
}

void CBGraphic::drawCircle(CBPoint& pt, float radius, CBColor& color)
{
    m_impl->drawCircle(pt, radius, color);
}
void CBGraphic::drawCircle(CBPoint& pt, float radius, CBColor& color, bool filled)
{
    m_impl->drawCircle(pt, radius, color, filled);
}

// for texture
void CBGraphic::render(CBView* view, CBTexture* texture)
{
    m_impl->render(view, texture);
}
void CBGraphic::renderString(CBView* view, CBTexture* texture)
{
    m_impl->renderString(view, texture);
}