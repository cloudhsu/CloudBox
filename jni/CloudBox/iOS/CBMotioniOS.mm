//
//  CBMotioniOS.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/5/20.
//  Copyright 2012 Orz. All rights reserved.
//

#import "CBMotioniOS.h"
#import <AVFoundation/AVFoundation.h>
#import "CBEnvironment.h"
#import "CBMotion.h"

CBMotioniOS::CBMotioniOS()
{
#ifdef CBMotionEnable
#ifdef TARGET_OS_IPHONE
    motionManager = [[CMMotionManager alloc] init];
    motionManager.accelerometerUpdateInterval = FPS_60;
    motionManager.gyroUpdateInterval = FPS_60;
    motionManager.deviceMotionUpdateInterval = FPS_60;
#endif
#endif
}
CBMotioniOS::~CBMotioniOS()
{
    [motionManager release];
}

void CBMotioniOS::startAccelerometer()
{
#ifdef CBMotionEnable
#ifdef TARGET_OS_IPHONE
    [motionManager startAccelerometerUpdates];
    //[motionManager startDeviceMotionUpdates];
#endif
#endif
}
void CBMotioniOS::updateAccelerometer()
{
#ifdef CBMotionEnable
#ifdef TARGET_OS_IPHONE
    CMAccelerometerData *newestAccel = motionManager.accelerometerData;
    m_accleration.x = newestAccel.acceleration.x;
    m_accleration.y = newestAccel.acceleration.y;
    if(CBEnvironment::getOrientation() == CBOrientationLandscapeRight)
    {
        m_accleration.x = newestAccel.acceleration.y;
        m_accleration.y = newestAccel.acceleration.x * -1;
    }
    m_accleration.z = newestAccel.acceleration.z;
#endif
#endif
}
void CBMotioniOS::stopAccelerometer()
{
#ifdef CBMotionEnable
#ifdef TARGET_OS_IPHONE
    [motionManager stopAccelerometerUpdates];
#endif
#endif
}