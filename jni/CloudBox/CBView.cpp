//
//  CBView.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2012/02/07.
//  Copyright 2012 Cloud Hsu. All rights reserved.
//

#include "CBView.h"
#include "CBEnvironment.h"
#include "CBLayout.h"
#include <math.h>

CBView::CBView()
:m_visible(true), m_x(0.0), m_y(0.0), m_z(0.0), m_angle(0.0),
m_rotateAxis(RotateAxisZ), m_width(0.0), m_height(0.0)
{
	// construct
	m_color.r = m_color.g = m_color.b = m_color.a = 1.0f;
}

CBView::CBView(CBView& view)
{
}

CBView::~CBView()
{
}

void CBView::setColor(float r, float g, float b, float a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
}

void CBView::setColor(float r, float g, float b)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = 1.0;
}

void CBView::moveTo(float x, float y)
{
	SLayout.scalePosition(x,y);
	m_x = x;
	m_y = y;
}

void CBView::move(float dx, float dy)
{
	SLayout.scalePosition(dx,dy);
	m_x += dx;
	m_y += dy;
}

void CBView::moveX(float dx)
{
    dx = SLayout.scaleX(dx);
    m_x += dx;
}
void CBView::moveY(float dy)
{
    dy = SLayout.scaleY(dy);
    m_y += dy;
}

void CBView::moveToAbsolute(const float x, const float y)
{
	m_x = x;
	m_y = y;
}
void CBView::moveAbsolute(const float dx, const float dy)
{
	m_x += dx;
	m_y += dy;
}

void CBView::visit()
{
	draw();
}

void CBView::notify()
{
	update();
}

bool CBView::isInArea(float x,float y)
{
#ifdef __CBIOS__
    float width = m_width;
    float height = m_height;
    float startX = m_x;
    float startY = m_y;
    if(CBEnvironment::isRetina())
    {
        startX /= 2;
        startY /= 2;
        width /= 2;
        height /= 2;
    }
    return (x >= startX && x <= startX + width) && 
    (y >= startY && y <= startY + height);
#else
    return (x >= m_x && x <= m_x + m_width) && 
    (y >= m_y && y <= m_y + m_height);
#endif
}

bool CBView::isTrigger(float x,float y)
{
#ifdef __CBIOS__
    return m_visible && isInArea(x, y);
#else
    return m_visible && isInArea(x, y);
#endif
}

void CBView::onClick(float x,float y)
{
	if(isTrigger(x,y))
	{
		IClick::onTrigger(this, new CBEvent(EventOnClick,x,y));
	}
}

void CBView::touchBegan(float x, float y)
{
	if(isTrigger(x,y))
	{
		ITouch::onTrigger(this, new CBEvent(EventOnTouchBegan,x,y));
	}
}
void CBView::touchMoved(float x, float y)
{
	if(isTrigger(x,y))
	{
		ITouch::onTrigger(this, new CBEvent(EventOnTouchMoved,x,y));
	}
}
void CBView::touchEnded(float x, float y)
{
	if(isTrigger(x,y))
	{
		ITouch::onTrigger(this, new CBEvent(EventOnTouchEnded,x,y));
	}
}

bool CBView::checkCollision(CBView* target)
{
    /* Circle equation (x - h)^2 + (y - k)^2 = r^2....Basically you just have to find the distance between the two centers.
	 Now take the two radii and add them up. If they are less than this distance, they won't intersect. */
	
	float X = target->getCenterX() - this->getCenterX();
	float Y = target->getCenterY() - this->getCenterY();
	float D = sqrtf( (X*X + Y*Y) );   // distance between two centers
	float sumRad = target->getRatius() + this->getRatius();
	
	// Testing for overlap
	if (D < sumRad)
		return true; // true means they intersect
	else
		return false;
}