/*
 *  MainViewGameCenterController.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <GameKit/GameKit.h>

#import "GameCenterManager.h"

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
