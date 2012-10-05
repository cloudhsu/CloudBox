//
//  CloudGameAppDelegate.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/25.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MainViewController;

@interface CloudGameAppDelegate : NSObject <UIApplicationDelegate> 
{
	UIWindow *window;
	MainViewController *viewController;
}

//@property (nonatomic, assign) MainViewController *viewController;
@property (readonly) MainViewController *viewController;

@end

