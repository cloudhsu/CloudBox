//
//  CBiOSMotion.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/5/20.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBMOTIONIOS_H_
#define _CBMOTIONIOS_H_

#include "CBMotionBase.h"
#ifdef TARGET_OS_IPHONE
#import <CoreMotion/CoreMotion.h>
#endif

class CBiOSMotion : public CBMotionBase
{
private:
#ifdef TARGET_OS_IPHONE
    CMMotionManager* motionManager;
#endif
public:
	CBiOSMotion();
	~CBiOSMotion();
    
    void startAccelerometer();
    void updateAccelerometer();
    void stopAccelerometer();
};

#endif