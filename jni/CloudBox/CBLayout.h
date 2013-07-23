/*
 *  CBLayout.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/9/18.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBLAYOUT_H_
#define _CBLAYOUT_H_

#include "CBDevice.h"
#include "CBSingleton.h"

#define DEFALUT_SCALE 1.0

typedef enum {
    Coordinate_320_480 = 0,
    Coordinate_Normal = 1
}CBDrawCoordinate;

typedef enum {
	iOS_Normal_320_480,
	iOS_Retina_640_960,
    iOS_Retina_640_1136,
	iOS_iPad1_1024_768,
    iOS_iPad_Retina_2048_1536,
	Android_WQVGA_200_400,
	Android_WVGA_400_800
}CBLayoutType;

#define IOS_RETINA_WIDTH 640.0
#define IOS_RETINA_HEIGHT 960.0

class CBLayout : public CBSingleton<CBLayout>
{
private:
    bool m_enableScaleRetina4;
    bool m_isiPhone5;
    CBDrawCoordinate m_coordinate;
	CBLayoutType m_baseLayout;
    CBLayoutType m_currentLayout;
	float m_scaleWidth;
	float m_scaleHeight;
	float m_defaultWidth;
	float m_defaultHeight;
	float m_screenWidth;
	float m_screenHeight;
	CBOrientation m_orientation;
public:
	CBLayout();
	~CBLayout();
	inline const float getScaleWidth() { return m_scaleWidth; }
	inline const float getScaleHeight() { return m_scaleHeight; }
    
    void iOSWideScreen();
    
	void initial(float screenWidth, float screenHeight);
	void setOrientation(CBOrientation orientation);
//	void layoutScale(float &width, float &height);
//	void layoutPosition(float &x, float &y);
    
    void scaleSize(float &width, float &height);
	void scalePosition(float &x, float &y);
    
    //void scaleX(float& x);
    //void scaleY(float& y);
    
    float scaleX(float x);
    float scaleY(float y);
    
    float scaleWidth(float width);
    float scaleHeight(float height);
    
    //void scaleWidth(float& width);
    //void scaleHeight(float& height);
};

#define SLayout CBLayout::instance()

#endif
