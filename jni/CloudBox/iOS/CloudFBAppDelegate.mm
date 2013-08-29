//
//  CloudGameAppDelegate.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2013/04/07.
//  Copyright 2013 Cloud Hsu. All rights reserved.
//

#import "CloudFBAppDelegate.h"
#import "MainViewController.h"
#import "CBGameApp.h"
#import "FacebookManager.h"

@implementation CloudGameAppDelegate

@synthesize viewController;

#ifdef CBFacebookEnable
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation {
    // attempt to extract a token from the url
    return [[FacebookManager sharedInstance] handleOpenURL:url];
}
#endif

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
#ifdef CBFacebookEnable
    [[FacebookManager sharedInstance]handleActive];
#endif
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    [self.viewController stopAnimation];
#ifdef CBFacebookEnable
    [[FacebookManager sharedInstance]logout];
#endif
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
