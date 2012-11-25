/*
 *  EAGLView.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/14.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 * old delegate, not use
 */

#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/EAGLDrawable.h>

#import "EAGLView.h"
#import "CloudBox.h"

#define USE_DEPTH_BUFFER 0
#define IS_WIDESCREEN (fabs((double)[[UIScreen mainScreen]bounds].size.height - (double)568) < DBL_EPSILON)

// A class extension to declare private methods
@interface EAGLView ()

@property (nonatomic, retain) EAGLContext *context;

- (BOOL) createFramebuffer;
- (void) destroyFramebuffer;

@end


@implementation EAGLView

@synthesize context;

// You must implement this
+ (Class)layerClass {
	return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)rect {
	
	if ((self = [super initWithFrame:rect])) {
		// Get the layer
		CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
        
        if ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] &&
            ([UIScreen mainScreen].scale == 2.0))
        {
            // We have a Retina Display:
			NSLog(@"This is a retain display!");
			self.contentScaleFactor = 2.0f;
			eaglLayer.contentsScale = 2.0f;
			SGameApp.retinaDisplay();
        }
        if(IS_WIDESCREEN)
        {
            SGameApp.iOSWideScreen();
        }
		
		eaglLayer.opaque = YES;
		eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
										[NSNumber numberWithBool:FALSE], kEAGLDrawablePropertyRetainedBacking, kEAGLColorFormatRGBA8, kEAGLDrawablePropertyColorFormat, nil];
		
		context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
		
		if (!context || ![EAGLContext setCurrentContext:context]) {
			[self release];
			return nil;
		}
		
	}
	return self;
}


- (void)drawView {
	
	[EAGLContext setCurrentContext:context];
	
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, viewFramebuffer);
	
	CFTimeInterval time = CFAbsoluteTimeGetCurrent();
	SGameApp.mainLoop(time);
		
	glBindRenderbufferOES(GL_RENDERBUFFER_OES, viewRenderbuffer);
	[context presentRenderbuffer:GL_RENDERBUFFER_OES];
}


- (void)layoutSubviews 
{
	[EAGLContext setCurrentContext:context];
	[self destroyFramebuffer];
	[self createFramebuffer];
	
	NSLog(@"witth:%d height:%d",backingWidth,backingHeight);
	SGameApp.setScreen(backingWidth, backingHeight);
	
//	glViewport(0, 0, backingWidth, backingHeight);
//	
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrthof(0, (float)backingWidth, 0, (float)backingHeight, 0, 100);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	
//	glEnableClientState (GL_VERTEX_ARRAY);
//    glEnableClientState (GL_TEXTURE_COORD_ARRAY);
//	
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	SGameApp.initialize();
	
	[self drawView];
}


- (BOOL)createFramebuffer {
	
	glGenFramebuffersOES(1, &viewFramebuffer);
	glGenRenderbuffersOES(1, &viewRenderbuffer);
	
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, viewFramebuffer);
	glBindRenderbufferOES(GL_RENDERBUFFER_OES, viewRenderbuffer);
	[context renderbufferStorage:GL_RENDERBUFFER_OES fromDrawable:(CAEAGLLayer*)self.layer];
	glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, viewRenderbuffer);
	
	glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_WIDTH_OES, &backingWidth);
	glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_HEIGHT_OES, &backingHeight);
	
	if (USE_DEPTH_BUFFER) {
		glGenRenderbuffersOES(1, &depthRenderbuffer);
		glBindRenderbufferOES(GL_RENDERBUFFER_OES, depthRenderbuffer);
		glRenderbufferStorageOES(GL_RENDERBUFFER_OES, GL_DEPTH_COMPONENT16_OES, backingWidth, backingHeight);
		glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_DEPTH_ATTACHMENT_OES, GL_RENDERBUFFER_OES, depthRenderbuffer);
	}

	if(glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES) != GL_FRAMEBUFFER_COMPLETE_OES) {
		NSLog(@"failed to make complete framebuffer object %x", glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES));
		return NO;
	}
	
	return YES;
}


- (void)destroyFramebuffer {
	
	glDeleteFramebuffersOES(1, &viewFramebuffer);
	viewFramebuffer = 0;
	glDeleteRenderbuffersOES(1, &viewRenderbuffer);
	viewRenderbuffer = 0;
	
	if(depthRenderbuffer) {
		glDeleteRenderbuffersOES(1, &depthRenderbuffer);
		depthRenderbuffer = 0;
	}
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
	// Retrieve the touch point
	UITouch* touch = [touches anyObject];
	// --- get main view touch point --- //
	CGPoint pt = [touch locationInView:self];
	
	// --- touch began --- //
	SGameApp.touchBegan(pt.x,pt.y);
}
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
	UITouch* touch = [touches anyObject];
	// --- get main view touch point --- //
	CGPoint pt = [touch locationInView:self];
	
	// --- touch moved --- //
	SGameApp.touchMoved(pt.x,pt.y);
}
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
	UITouch* touch = [touches anyObject];
	// --- get main view touch point --- //
	CGPoint pt = [touch locationInView:self];
	
	// --- touch ended --- //
	SGameApp.touchEnded(pt.x,pt.y);
}


- (void)dealloc {
	
	if ([EAGLContext currentContext] == context) {
		[EAGLContext setCurrentContext:nil];
	}
	
	[context release];
	
	[super dealloc];
}

@end
