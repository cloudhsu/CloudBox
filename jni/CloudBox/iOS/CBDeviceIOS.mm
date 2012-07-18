//
//  CBDeviceIOS.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/25.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#import "CBDeviceIOS.h"
#include "CBEnvironment.h"

UIInterfaceOrientation DefaultOrientation()
{
	UIInterfaceOrientation orientation = UIInterfaceOrientationPortrait;
	if(DEFAULT_ORIENTATION == CBOrientationPortrait)
	{
		orientation = UIInterfaceOrientationPortrait;
	}
	else if(DEFAULT_ORIENTATION == CBOrientationPortraitUpsideDown)
	{
		orientation = UIInterfaceOrientationPortraitUpsideDown;
	}
	else if(DEFAULT_ORIENTATION == CBOrientationLandscapeLeft)
	{
		orientation = UIInterfaceOrientationLandscapeLeft;
	}
	else if(DEFAULT_ORIENTATION == CBOrientationLandscapeRight)
	{
		orientation = UIInterfaceOrientationLandscapeRight;
	}
	return orientation;
}