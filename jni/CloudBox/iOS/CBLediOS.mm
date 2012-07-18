/*
 *  CBLediOS.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/14.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBLediOS.h"
#import <AVFoundation/AVFoundation.h>

CBLediOS::CBLediOS()
{
}
CBLediOS::~CBLediOS()
{
}
void CBLediOS::turnOnLed()
{
#ifdef TARGET_IPHONE_SIMULATOR
#endif
#ifdef TARGET_OS_IPHONE
//	AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
//    if ([device hasTorch]) {
//        [device lockForConfiguration:nil];
//        [device setTorchMode: AVCaptureTorchModeOn];
//        [device unlockForConfiguration];
//    }
#endif
}
void CBLediOS::turnOffLed()
{
#ifdef TARGET_OS_IPHONE
//	AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
//    if ([device hasTorch]) {
//        [device lockForConfiguration:nil];
//        [device setTorchMode: AVCaptureTorchModeOff];
//        [device unlockForConfiguration];
//    }
#endif
}