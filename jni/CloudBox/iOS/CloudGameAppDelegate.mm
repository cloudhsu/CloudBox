//
//  CloudGameAppDelegate.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/25.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#import "CloudGameAppDelegate.h"
#import "MainViewController.h"
#import "CBGameApp.h"

@implementation CloudGameAppDelegate

@synthesize viewController;

- (void)applicationDidFinishLaunching:(UIApplication *)application 
{
	CGRect t_FullScreenRect = [[UIScreen mainScreen] bounds];
	
	// --- initial window and set to full screen --- //
	window = [[UIWindow alloc] initWithFrame:t_FullScreenRect];
	viewController = [[MainViewController alloc] init];
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this mehod on ios6
        [window setRootViewController:viewController];
    }
    //[window setRootViewController:viewController];
	//[window addSubview:viewController.view];
	[window makeKeyAndVisible];
}


- (void)applicationWillResignActive:(UIApplication *)application
{
    [self.viewController stopAnimation];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    [self.viewController startAnimation];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    [self.viewController stopAnimation];
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Handle any background procedures not related to animation here.
	SGameApp.applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Handle any foreground procedures not related to animation here.
	SGameApp.applicationWillEnterForeground();
}

- (void)dealloc
{
	[window release];
	[viewController release];
	[super dealloc];
}

@end
