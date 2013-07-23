/*
 *  CBLayout.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/9/18.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLayout.h"
#include "CBEnvironment.h"
#include "CBLibrary.h"

CBLayout::CBLayout():m_isiPhone5(false)
{
    m_coordinate = Coordinate_Normal;
	m_baseLayout = iOS_Retina_640_960;
    m_enableScaleRetina4 = false;
	m_defaultWidth = IOS_RETINA_WIDTH;
	m_defaultHeight = IOS_RETINA_HEIGHT;
	setOrientation(CBEnvironment::getOrientation());
	m_scaleWidth = DEFALUT_SCALE;
	m_scaleHeight = DEFALUT_SCALE;
}

CBLayout::~CBLayout()
{
}

void CBLayout::iOSWideScreen()
{
    m_isiPhone5 = true;
}

void CBLayout::initial(float screenWidth, float screenHeight)
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
    if(m_screenWidth > m_screenHeight)
    {
        m_defaultWidth = IOS_RETINA_HEIGHT;
        m_defaultHeight = IOS_RETINA_WIDTH;
    }
    else
    {
        m_defaultWidth = IOS_RETINA_WIDTH;
        m_defaultHeight = IOS_RETINA_HEIGHT;
    }
	m_scaleWidth = m_screenWidth / m_defaultWidth;
	m_scaleHeight = m_screenHeight / m_defaultHeight;
    DebugLog("scale width:%f\n",m_scaleWidth);
    DebugLog("scale height:%f\n",m_scaleHeight);
}

//void CBLayout::layoutScale(float &width, float &height)
//{
//#ifdef __CBIOS__
//    if(m_isiPhone5 && m_enableScaleRetina4)
//    {
//        width *= m_scaleWidth;
//        height *= m_scaleHeight;
//    }
//#else
//	width *= m_scaleWidth;
//	height *= m_scaleHeight;
//#endif
//}

//void CBLayout::layoutPosition(float &x, float &y)
//{
//#ifdef __CBIOS__
//	if(CBEnvironment::isRetina())
//	{
//        if(m_coordinate == Coordinate_320_480)
//        {
//            x *= 2;
//            y *= 2;
//        }
//        if(m_isiPhone5 && m_enableScaleRetina4)
//        {
//            x *= m_scaleWidth;
//            y *= m_scaleHeight;
//        }
//	}
//    else
//    {
//        if(m_coordinate == Coordinate_Normal)
//        {
//            x /= 2;
//            y /= 2;
//        }
//    }
//#else
//	if(m_coordinate == Coordinate_320_480)
//    {
//        x *= 2;
//        y *= 2;
//    }
//	x *= m_scaleWidth;
//	y *= m_scaleHeight;
//#endif
//}

void CBLayout::scaleSize(float &width, float &height)
{
#ifdef __CBIOS__
    if(m_isiPhone5 && m_enableScaleRetina4)
    {
        width *= m_scaleWidth;
        height *= m_scaleHeight;
    }
#else
	width *= m_scaleWidth;
	height *= m_scaleHeight;
#endif
}
void CBLayout::scalePosition(float &x, float &y)
{
#ifdef __CBIOS__
	if(CBEnvironment::isRetina())
	{
        if(m_coordinate == Coordinate_320_480)
        {
            x *= 2;
            y *= 2;
        }
        if(m_isiPhone5 && m_enableScaleRetina4)
        {
            x *= m_scaleWidth;
            y *= m_scaleHeight;
        }
	}
    else
    {
        if(m_coordinate == Coordinate_Normal)
        {
            x /= 2;
            y /= 2;
        }
    }
#else
	if(m_coordinate == Coordinate_320_480)
    {
        x *= 2;
        y *= 2;
    }
	x *= m_scaleWidth;
	y *= m_scaleHeight;
#endif
}

//void CBLayout::scaleX(float& x)
//{
//#ifdef __CBIOS__
//	if(CBEnvironment::isRetina())
//	{
//        if(m_coordinate == Coordinate_320_480)
//        {
//            x *= 2;
//        }
//        if(m_isiPhone5 && m_enableScaleRetina4)
//        {
//            x *= m_scaleWidth;
//        }
//	}
//    else
//    {
//        if(m_coordinate == Coordinate_Normal)
//        {
//            x /= 2;
//        }
//    }
//#else
//	if(m_coordinate == Coordinate_320_480)
//    {
//        x *= 2;
//    }
//	x *= m_scaleWidth;
//#endif
//}
//void CBLayout::scaleY(float& y)
//{
//#ifdef __CBIOS__
//	if(CBEnvironment::isRetina())
//	{
//        if(m_coordinate == Coordinate_320_480)
//        {
//            y *= 2;
//        }
//        if(m_isiPhone5 && m_enableScaleRetina4)
//        {
//            y *= m_scaleHeight;
//        }
//	}
//    else
//    {
//        if(m_coordinate == Coordinate_Normal)
//        {
//            y /= 2;
//        }
//    }
//#else
//    if(m_coordinate == Coordinate_320_480)
//    {
//        y *= 2;
//    }
//	y *= m_scaleHeight;
//#endif
//}

float CBLayout::scaleX(float x)
{
#ifdef __CBIOS__
	if(CBEnvironment::isRetina())
	{
        if(m_coordinate == Coordinate_320_480)
        {
            x *= 2;
        }
        if(m_isiPhone5 && m_enableScaleRetina4)
        {
            x *= m_scaleWidth;
        }
	}
    else
    {
        if(m_coordinate == Coordinate_Normal)
        {
            x /= 2;
        }
    }
#else
    if(m_coordinate == Coordinate_320_480)
    {
        x *= 2;
    }
	x *= m_scaleWidth;
#endif
    return x;
}
float CBLayout::scaleY(float y)
{
#ifdef __CBIOS__
	if(CBEnvironment::isRetina())
	{
        if(m_coordinate == Coordinate_320_480)
        {
            y *= 2;
        }
        if(m_isiPhone5 && m_enableScaleRetina4)
        {
            y *= m_scaleHeight;
        }
	}
    else
    {
        if(m_coordinate == Coordinate_Normal)
        {
            y /= 2;
        }
    }
#else
    if(m_coordinate == Coordinate_320_480)
    {
        y *= 2;
    }
	y *= m_scaleHeight;
#endif
    return y;
}

//void CBLayout::scaleWidth(float& width)
//{
//#ifdef __CBIOS__
//    if(m_isiPhone5 && m_enableScaleRetina4)
//    {
//        width *= m_scaleWidth;
//    }
//#else
//	width *= m_scaleWidth;
//#endif
//}
//void CBLayout::scaleHeight(float& height)
//{
//#ifdef __CBIOS__
//    if(m_isiPhone5 && m_enableScaleRetina4)
//    {
//        height *= m_scaleHeight;
//    }
//#else
//	height *= m_scaleHeight;
//#endif
//}

float CBLayout::scaleWidth(float width)
{
#ifdef __CBIOS__
    if(m_isiPhone5 && m_enableScaleRetina4)
    {
        width *= m_scaleWidth;
    }
#else
	width *= m_scaleWidth;
#endif
    return width;
}
float CBLayout::scaleHeight(float height)
{
#ifdef __CBIOS__
    if(m_isiPhone5 && m_enableScaleRetina4)
    {
        height *= m_scaleHeight;
    }
#else
	height *= m_scaleHeight;
#endif
    return height;
}

void CBLayout::setOrientation(CBOrientation orientation)
{
//	float temp;
//	if((m_orientation <= CBOrientationPortraitUpsideDown && orientation >= CBOrientationLandscapeLeft) ||
//	   (m_orientation >= CBOrientationLandscapeLeft && orientation <= CBOrientationPortraitUpsideDown))
//	{
//		temp = m_defaultWidth;
//		m_defaultWidth = m_defaultHeight;
//		m_defaultHeight = temp;
//	}
	m_orientation = orientation;
}
