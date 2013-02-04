/*
 *  CBiOSLed.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBiOSLed.h"
#import <AVFoundation/AVFoundation.h>

CBiOSLed::CBiOSLed()
{
}
CBiOSLed::~CBiOSLed()
{
}
void CBiOSLed::turnOnLed()
{
#ifdef CBLedEnable
#ifdef TARGET_IPHONE_SIMULATOR
#endif
#ifdef TARGET_OS_IPHONE
	AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    if ([device hasTorch]) {
        [device lockForConfiguration:nil];
        [device setTorchMode: AVCaptureTorchModeOn];
        [device unlockForConfiguration];
    }
#endif
#endif
}
void CBiOSLed::turnOffLed()
{
#ifdef CBLedEnable
#ifdef TARGET_OS_IPHONE
	AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    if ([device hasTorch]) {
        [device lockForConfiguration:nil];
        [device setTorchMode: AVCaptureTorchModeOff];
        [device unlockForConfiguration];
    }
#endif
#endif
}