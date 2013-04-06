//
//  CloudGameAppDelegate.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2013/04/07.
//  Copyright 2013 Cloud Hsu. All rights reserved.
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

