/*
 *  FacebookManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/06.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import "CBConfig.h"

#ifdef CBFacebookEnable

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <FacebookSDK/FacebookSDK.h>

@interface FacebookManager : NSObject
{
    BOOL _isLogon;    
    UIViewController* _controller;
    id<FBGraphUser> _loggedInUser;
    FBSession *session;
    NSArray *_defaultPermissions;
}

+ (FacebookManager *) sharedInstance;

- (void) autoLogin;
- (void) login;
- (BOOL) handleOpenURL :(NSURL*)url;
- (void) handleActive;
- (void) logout;

- (void) postStatus:(NSString*)message;
- (void) postStatus:(NSString*)message andImageName:(NSString*)imageName;
- (void) postFeed:(NSString*) name andLink:(NSString*) link andCaption:(NSString*) caption andDesc:(NSString*) description andMsg:(NSString*) msg;

@property (nonatomic, readonly) BOOL isLogon;
@property (nonatomic, assign)  UIViewController* controller;
@property (nonatomic, readonly) id<FBGraphUser> loggedInUser;

@end

#endif
