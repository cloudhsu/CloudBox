//
//  CBView.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2012/02/07.
//  Copyright 2012 Cloud Hsu. All rights reserved.
//

#ifndef _CBVIEW_H_
#define _CBVIEW_H_

#include "CBLibrary.h"
#include "CBCore.h"
#include "ITouch.h"
#include "IClick.h"
#include <iostream>
using namespace std;

enum RotateAxis
{
    RotateAxisX = 0,
    RotateAxisY = 1,
    RotateAxisZ = 2,
    RotateCustom = 3
};

class CBView : public CBObject, public ITouch, public IClick
{
protected:
	// --- Add private member --- //
	float m_x;
	float m_y;
    float m_z;
	float m_width;
	float m_height;
	
	float m_angle;
	float m_alpha;
	
	bool m_visible;
	float m_ratius;
	
	CBColor m_color;
//	bool isInitial;
	
//	CBCircle m_circle;
	
	virtual void draw() = 0;
	virtual void update(){}
    
    RotateAxis m_rotateAxis;
	
public:
	// --- Add public member --- //
	CBView();
	CBView(CBView& view);
	virtual ~CBView();
	
	virtual void setColor(float r, float g, float b, float a);
	virtual void setColor(float r, float g, float b);
	
	void moveTo(float x, float y);
	void move(float dx, float dy);
    
    void moveX(float dx);
    void moveY(float dy);
	
	void moveToAbsolute(const float x, const float y);
	void moveAbsolute(const float dx, const float dy);

	inline const float getX() { return m_x; }
	inline void setX(float x) { m_x = x; }
	
	inline const float getY() { return m_y; }
	inline void setY(float y) { m_y = y; }
    
    inline const float getZ() { return m_z; }
	inline void setZ(float z) { m_z = z; }
	
	inline const float getWidth() { return m_width; }
	inline void setWidth(float width) { m_width = width; }
	
	inline const float getHeight() { return m_height; }
	inline void setHeight(float height) { m_height = height; }
	
	inline const float getAngle() { return m_angle; }
	inline void setAngle(float angle) { m_angle = angle; }
	
	inline const float getAlpha() { return m_alpha; }
	inline void setAlpha(float alpha) { m_alpha = alpha; m_color.a = alpha; }
    
    inline const RotateAxis getRotateAxis() { return m_rotateAxis; }
	inline void setRotateAxis(RotateAxis rotateAxis) { m_rotateAxis = rotateAxis; }
	
	inline CBColor getColor() { return m_color; }
	
	inline const bool getVisible() { return m_visible; }
	inline void setVisible(const bool visible) { m_visible = visible; }
	inline const bool isVisible() { return m_visible; }
	
	//inline const CBCircle getCircle() { return m_circle; }
//	inline void setCircle(const CBCircle circle) { m_circle = circle; }
//	inline void setCircle(const float centerX, const float centerY, const float ratius)
//	{
//		m_circle.center.x = centerX;
//		m_circle.center.y = centerY;
//		m_circle.ratius = ratius;
//	}
	inline const float getRatius() { return m_ratius; }
	inline void setRatius(const float ratius) { m_ratius = ratius; }
	
	inline void show() { m_visible = true; }
	inline void hide() { m_visible = false; }
	
	inline float getCenterX() { return m_x + (m_width / 2); }
	inline float getCenterY() { return m_y + (m_height / 2); }
	
    bool isInArea(float x,float y);
	
	inline void scaleWidth(float width)
	{
		m_width += width;
	}
	
	inline void scaleHeight(float height)
	{
		m_height += height;
	}
	
	inline void rotate(float angle)
	{
		m_angle += angle;
		if(m_angle > 360)
		{
			m_angle -= 360;
		}
		else if(m_angle < 0){
			m_angle = 360 - angle;
		}
	}
	
	inline void transparent(float alpha)
	{
		m_alpha += alpha;
		if(m_alpha > 1)
		{
			m_alpha = 1.0;
		}
		else if(m_angle < 0){
			m_alpha = 0;
		}
	}
	
    bool isTrigger(float x,float y);
	
	virtual void notify();
	virtual void visit();
	
	// for touch event
	virtual void touchBegan(float x, float y);
	virtual void touchMoved(float x, float y);
	virtual void touchEnded(float x, float y);
	
	// for click event
	virtual void onClick(float x,float y);
    
    bool checkCollision(CBView* target);
};

#endif
