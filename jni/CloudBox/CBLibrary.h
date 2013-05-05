/*
 *  CBLibrary.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/1.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBDLIBRARY_H_
#define _CBDLIBRARY_H_

#ifdef __CBIOS__
	#ifdef DEBUG
	#include <stdio.h>
	#define DebugLog(str) printf(str)
	#undef DebugLog
	#define DebugLog(format, ...) printf(format, ## __VA_ARGS__)
	#else
	#define DebugLog(str)
	#undef DebugLog
	#define DebugLog(format, ...)
	#endif
	#define AndroidLog(...)
#elif WIN32
	#ifdef _DEBUG
	#include <windows.h>
    #include <stdio.h>
	#define DebugLog(str) OutputDebugStringA(str)
	#undef DebugLog
    #define DebugLog(format, ...) { char str[256]; sprintf_s(str, format, ## __VA_ARGS__); OutputDebugStringA(str); }
	#else
	#define DebugLog(str)
	#undef DebugLog
	#define DebugLog(format, ...)
	#endif
	#define AndroidLog(...)
#else
	#ifdef DEBUG
	#include <android/log.h>
	#define AndroidLog(...) ((void)__android_log_print(ANDROID_LOG_INFO, "cloudbox-app", __VA_ARGS__))
	#define DebugLog(...) ((void)__android_log_print(ANDROID_LOG_INFO, "cloudbox-app", __VA_ARGS__))
    #else
    #define DebugLog(...)
    #endif
#endif

#define CBDELETE(x)		if (x) { delete x; x = NULL; }
#define CBDELETE_ARRAY(x)	if (x) { delete [] x; x = NULL; }

//#ifndef M_PI
//#define M_PI		(3.1415927f)
//#define M_PI_2		(1.5707963f)			// 90 degree
//#define M_PI_4		(0.7853982f)			// 45 degree
//#define M_PI_6		(0.5233333f)			// 30 degree
//#define M_PI_12		(0.2616667f)			// 15 degree
//#define M_1_PI		(0.3183099f)
//#define M_2_PI		(0.6366198f)
//#endif

#define ARGB(a, r, g, b)		((a << 24) | (r << 16) | (g << 8) | b)
#define RGBA(r, g, b, a)		((a << 24) | (b << 16) | (g << 8) | r)

#define FPS_30 1/30
#define FPS_60 1/60

#define DEGREES_TO_RADIANS(x) (3.14159265358979323846 * x / 180.0)

typedef struct _CBAcceleration{
    double x;
    double y;
    double z;
}CBAcceleration; 

typedef struct _CBColorf
{
	float r;
	float b;
	float g;
	float a;
    _CBColorf()
    {
        r = g = b = a = 1.0f;
    }
    _CBColorf(float _r, float _g, float _b)
    {
        r = _r;
        g = _g;
        b = _b;
        a = 1.0f;
    }
    _CBColorf(float _r, float _g, float _b, float _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }
}CBColor;

typedef struct _CBRect {
	float x;
	float y;
	float width;
	float height;
    _CBRect()
    {
        x = y = width = height = 0.0f;
    }
    _CBRect(float _x, float _y, float _width, float _height)
    {
        x = _x;
        y = _y;
        width = _width;
        height = _height;
    }
}CBRect;

typedef struct _CBPoint {
	float x;
	float y;
    _CBPoint()
    {
        x = y = 0.0f;
    }
    _CBPoint(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
}CBPoint;

typedef struct _CBSize{
	float width;
	float height;
    _CBSize()
    {
        width = height = 0.0f;
    }
    _CBSize(float _width, float _height)
    {
        width = _width;
        height = _height;
    }
}CBSize;

typedef struct _CBCircle
{
	CBPoint center;
	float ratius;
    _CBCircle()
    {
        center.x = center.y = ratius = 0.0f;
    }
    _CBCircle(float _x, float _y, float _ratius)
    {
        center.x = _x;
        center.y = _y;
        ratius = _ratius;
    }
}CBCircle;


#endif
