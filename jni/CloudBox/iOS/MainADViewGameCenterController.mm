/*
 *  MainADViewGameCenterController.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import "MainADViewController.h"
#import "EAGLView.h"
#import "CloudBox.h"
#import "CBLogoScene.h"
#import "CBDeviceIOS.h"

//@interface MainViewController ()
//
//@property (nonatomic, assign) CADisplayLink *displayLink;
//
//@end

@implementation MainViewController

@synthesize glView;
@synthesize animating;
//@synthesize animationInterval;

/*
// The designated initializer. Override to perform setup that is required before the view is loaded.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    if (self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]) {
        // Custom initialization
    }
    return self;
}
*/


// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
	CGRect t_FullScreenRect = [[UIScreen mainScreen] bounds];
	glView = [[EAGLView alloc]initWithFrame:t_FullScreenRect];
	//NSLog(@"glView:%d",[glView retainCount]);
	self.view = glView;
    [GameCenterManager sharedInstance].controller = self;
	
	animating = FALSE;
	// Set 1 = 60FPS
	// 2 = 30FPS
    animationFrameInterval = 1;
    displayLink = nil;
	
	//SGameApp.start();
	[self startAnimation];
	
	awView = [AdWhirlView requestAdWhirlViewWithDelegate:self];	
	awView.autoresizingMask =
    UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin;
	[glView addSubview:awView];
	[awView.superview bringSubviewToFront:awView];
}

- (void)startAnimation {
	if (!animating)
    {
		CFTimeInterval time = CFAbsoluteTimeGetCurrent();
		SGameApp.initialTimer(time);
        CADisplayLink *aDisplayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawView)];
        [aDisplayLink setFrameInterval:animationFrameInterval];
        [aDisplayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        displayLink = aDisplayLink;
        
        animating = TRUE;
    }
}


- (void)stopAnimation {
	if (animating)
    {
        [displayLink invalidate];
        displayLink = nil;
        animating = FALSE;
    }
}

- (void)viewWillAppear:(BOOL)animated
{
    [self startAnimation];
    
    [super viewWillAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [self stopAnimation];
    
    [super viewWillDisappear:animated];
}


- (NSInteger)animationFrameInterval
{
    return animationFrameInterval;
}

- (void)setAnimationFrameInterval:(NSInteger)frameInterval
{
    /*
	 Frame interval defines how many display frames must pass between each time the display link fires.
	 The display link will only fire 30 times a second when the frame internal is two on a display that refreshes 60 times a second. The default frame interval setting of one will fire 60 times a second when the display refreshes at 60 times a second. A frame interval setting of less than one results in undefined behavior.
	 */
    if (frameInterval >= 1)
    {
        animationFrameInterval = frameInterval;
        
        if (animating)
        {
            [self stopAnimation];
            [self startAnimation];
        }
    }
}

- (void)drawView {
	[glView drawView];
	//[[NSRunLoop currentRunLoop] runUntilDate: [NSDate distantPast]];
}

#ifdef __IPHONE_6_0
// iPhone 6.0 code here
- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window{
    NSLog(@"supportedInterfaceOrientationsForWindow");
    return  UIInterfaceOrientationMaskPortrait;
}
#endif

-(BOOL)shouldAutorotate
{
    //return NO;
    return YES;
}


// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    //return (interfaceOrientation == DefaultOrientation());
    //return UIInterfaceOrientationIsLandscape( interfaceOrientation );
    return UIInterfaceOrientationIsPortrait( interfaceOrientation );
}

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
/*
- (void)viewDidLoad 
{
	sharedInstance = self;
	
	glView.animationInterval = 1.0 / 60.0;
	[glView startAnimation];
	
    [super viewDidLoad];
}
*/


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning]; // Releases the view if it doesn't have a superview
    // Release anything that's not essential, such as cached data
}


- (void)dealloc 
{
	[self stopAnimation];
	[glView release];
	SGameApp.destory();
    [super dealloc];
}

- (NSString *)adWhirlApplicationKey {
	//在AdWhirlDelegate的函式中輸入licenseKey
	return @"b2a58665a3f44eeeadf0b8a12d5673d5";
}

- (UIViewController *)viewControllerForPresentingModalView {
	//return [((AdWhirlTestAppDelegate *)[[UIApplication sharedApplication] delegate]) navigationController];
	return self;
}

- (void)adWhirlDidReceiveAd:(AdWhirlView *)adWhirlView {
	NSLog([NSString stringWithFormat:
		   @"Got ad from %@, size %@",
		   [adWhirlView mostRecentNetworkName],
		   NSStringFromCGSize([adWhirlView actualAdSize])]);
	[self adjustAdSize];
}

- (void)adWhirlDidFailToReceiveAd:(AdWhirlView *)adWhirlView usingBackup:(BOOL)yesOrNo {
	NSLog([NSString stringWithFormat:
		   @"Failed to receive ad from %@, %@. Error: %@",
		   [adWhirlView mostRecentNetworkName],
		   yesOrNo? @"will use backup" : @"will NOT use backup",
		   adWhirlView.lastError == nil? @"no error" : [adWhirlView.lastError localizedDescription]]);
}

- (void)adjustAdSize {
	//[UIView beginAnimations:@"AdResize" context:nil];
	//[UIView setAnimationDuration:0.7];
	CGSize adSize = [awView actualAdSize];
	CGRect newFrame = awView.frame;
	newFrame.size.height = adSize.height;
	newFrame.size.width = adSize.width;
	newFrame.origin.x = self.view.bounds.size.width - adSize.width;
	//newFrame.origin.y = self.view.bounds.size.height - adSize.height;
	newFrame.origin.y = 0;
	awView.frame = newFrame;
	//[UIView commitAnimations];
	awView.hidden = NO;
}

- (BOOL)adWhirlTestMode{
	/*
	 * 非測試時，請將測試模式參數設為NO
	 * 測試時，請將測試模式參數設為YES 
	 */
	return NO;
}

- (CLLocation *)locationInfo
{
	return nil;
}

@end
