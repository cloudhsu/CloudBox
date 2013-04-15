/*
 *  MainViewGameCenterController.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import "MainViewGameCenterController.h"
#import "EAGLView.h"
#import "CloudBox.h"
#import "CBLogoScene.h"
#import "CBDeviceIOS.h"

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
    
    [UIApplication sharedApplication].idleTimerDisabled = YES;
	
	//SGameApp.start();
	[self startAnimation];
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

#ifdef __IPHONE_6_0
// iPhone 6.0 code here
- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window{
    NSLog(@"supportedInterfaceOrientationsForWindow");
    return  UIInterfaceOrientationMaskLandscapeRight;
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
    return UIInterfaceOrientationIsLandscape( interfaceOrientation );
}


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

@end
