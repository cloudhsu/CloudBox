/*
 *  CBDevice.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBDEVICE_H_
#define _CBDEVICE_H_

typedef enum {
    CBOrientationPortrait = 0,
    CBOrientationPortraitUpsideDown = 1,
    CBOrientationLandscapeLeft = 2,
    CBOrientationLandscapeRight = 3
} CBOrientation;

//typedef struct{
//	float x;
//	float y;
//}CBPoint;
//

//#define DEFAULT_ORIENTATION CBOrientationPortrait
//#define DEFAULT_ORIENTATION CBOrientationPortraitUpsideDown
//#define DEFAULT_ORIENTATION CBOrientationLandscapeLeft
#define DEFAULT_ORIENTATION CBOrientationLandscapeRight

#endif