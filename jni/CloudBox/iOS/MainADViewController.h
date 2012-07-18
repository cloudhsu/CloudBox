/*
 *  MainADViewController.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "AdWhirlDelegateProtocol.h"
#import "AdWhirlView.h"

@class EAGLView;

@interface MainViewController : UIViewController<AdWhirlDelegate>
{
	AdWhirlView *awView;
	EAGLView *glView;
	
	BOOL animating;
    NSInteger animationFrameInterval;
    CADisplayLink *displayLink;
}

- (void)adjustAdSize;

@property (nonatomic, retain) EAGLView *glView;
@property (readonly, nonatomic, getter=isAnimating) BOOL animating;
@property (nonatomic) NSInteger animationFrameInterval;

- (void)startAnimation;
- (void)stopAnimation;
- (void)drawView;

@end
