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
}CBColor;

typedef struct _CBRect {
	float x;
	float y;
	float width;
	float height;
}CBRect;

typedef struct _CBPoint {
	float x;
	float y;
}CBPoint;

typedef struct{
	float width;
	float height;
}CBSize;

typedef struct
{
	CBPoint center;
	float ratius;
}CBCircle;


#endif
