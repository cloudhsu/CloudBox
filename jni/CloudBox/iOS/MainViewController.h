/*
 *  MainViewController.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/14.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 * old delegate, not use
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@class EAGLView;

@interface MainViewController : UIViewController 
{
	EAGLView *glView;
	
	BOOL animating;
    NSInteger animationFrameInterval;
    CADisplayLink *displayLink;
}

@property (nonatomic, retain) EAGLView *glView;
@property (readonly, nonatomic, getter=isAnimating) BOOL animating;
@property (nonatomic) NSInteger animationFrameInterval;

- (void)startAnimation;
- (void)stopAnimation;
- (void)drawView;

@end
