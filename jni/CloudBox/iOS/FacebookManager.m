/*
 *  FacebookManager.m
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/06.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import "FacebookManager.h"

#ifdef CBFacebookEnable

@implementation FacebookManager

@synthesize isLogon = _isLogon;
@synthesize controller = _controller;
@synthesize loggedInUser = _loggedInUser;

static FacebookManager* _sharedInstance = nil;

+(FacebookManager*) sharedInstance
{
	@synchronized([FacebookManager class])
	{
		if (!_sharedInstance)
			[[self alloc] init];
		
		return _sharedInstance;
	}
	
	return nil;
}

+(id) alloc
{
	@synchronized([FacebookManager class])
	{
		NSAssert(_sharedInstance == nil, @"Attempted to allocate a second instance of a singleton.");
		_sharedInstance = [super alloc];
		return _sharedInstance;
	}
	
	return nil;
}

-(id) init
{
    self = [super init];
    if (self) {
        _isLogon = NO;
        _controller = nil;
        _defaultPermissions = [[NSArray alloc] initWithObjects:@"publish_stream", @"publish_actions", nil];
    }
    return self;
}

- (void)dealloc {
    [session close];
	[_sharedInstance release];
    [_defaultPermissions release];
	[self dealloc];
    [super dealloc];
}

- (void) login
{
    if (!session.isOpen)
    {
        if (session.state != FBSessionStateCreated) {
            // Create a new, logged out session.
            session = [[FBSession alloc] initWithPermissions:_defaultPermissions];
        }
    
        // if the session isn't open, let's open it now and present the login UX to the user
        [session openWithCompletionHandler:^(FBSession *session,
                                             FBSessionState status,
                                             NSError *error) {
            // and here we make sure to update our UX according to the new session state
            if(error != nil)
            {
                _isLogon = YES;
            }
        }];
        [FBSession setActiveSession:session];
    }
}

- (void) autoLogin
{
    if (!session.isOpen) {
        // create a fresh session object
        session = [[FBSession alloc] initWithPermissions:_defaultPermissions];
        
        // if we don't have a cached token, a call to open here would cause UX for login to
        // occur; we don't want that to happen unless the user clicks the login button, and so
        // we check here to make sure we have a token before calling open
        if (session.state == FBSessionStateCreatedTokenLoaded) {
            // even though we had a cached token, we need to login to make the session usable
            [session openWithCompletionHandler:^(FBSession *session,
                                                             FBSessionState status,
                                                             NSError *error) {
                // we recurse here, in order to update buttons and labels
                if(error != nil)
                {
                    _isLogon = YES;
                }
            }];
            [FBSession setActiveSession:session];
        }
    }
}

- (BOOL) handleOpenURL :(NSURL *)url
{
    return [session handleOpenURL:url];
}

- (void) handleActive
{
    [FBSession.activeSession handleDidBecomeActive];
}

- (void) logout
{
    [session close];
}

- (void) postStatus:(NSString*)message
{
    [self performPublishAction:^{
        
        [FBRequestConnection startForPostStatusUpdate:message
                                    completionHandler:^(FBRequestConnection *connection, id result, NSError *error) {
                                        
                                        NSLog(@"Result:%@, Error:%@",result,error);
                                    }];
    }];
}
- (void) postStatus:(NSString*)message andImageName:(NSString*)imageName
{
    [self performPublishAction:^{
        UIImage *img = [UIImage imageNamed:imageName];
    
        NSMutableDictionary* params = [[NSMutableDictionary alloc] init];
        [params setObject:message forKey:@"message"];
        [params setObject:UIImagePNGRepresentation(img) forKey:@"picture"];
    
        [FBRequestConnection startWithGraphPath:@"me/photos"
                                     parameters:params
                                     HTTPMethod:@"POST"
                              completionHandler:^(FBRequestConnection *connection,
                                                  id result,
                                                  NSError *error)
         {
              if (error)
              {
                  NSLog(@"Result:%@, Error:%@",result,error);
              }
              else
              {
                  //showing an alert for success
              }
         }];
    }];
}

- (void) postFeed:(NSString*) name andLink:(NSString*) link andCaption:(NSString*) caption andDesc:(NSString*) description andMsg:(NSString*) msg
{
    [self performPublishAction:^{
        
        NSMutableDictionary *params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                                       name, @"name",
                                       link, @"link",
                                       caption, @"caption",
                                       description, @"description",
                                       msg, @"message",
                                       nil];
        
        [FBRequestConnection startWithGraphPath:@"me/feed"
                                     parameters:params
                                     HTTPMethod:@"POST"
                              completionHandler:^(FBRequestConnection *connection,
                                                  id result,
                                                  NSError *error)
         {
             if (error)
             {
                 NSLog(@"Result:%@, Error:%@",result,error);
             }
             else
             {
                 //showing an alert for success
             }
         }];
    }];
}


// Convenience method to perform some action that requires the "publish_actions" permissions.
- (void) performPublishAction:(void (^)(void)) action {
    // we defer request for permission to post to the moment of post, then we check for the permission
//    if ([session.permissions indexOfObject:@"publish_actions"] == NSNotFound ||
//        [session.permissions indexOfObject:@"user_about_me"] == NSNotFound ||
//        [session.permissions indexOfObject:@"publish_stream"] == NSNotFound) {
//        // if we don't already have the permission, then we request it now
//        [session requestNewPublishPermissions:@[@"publish_actions",@"user_about_me",@"publish_stream"]
    if ([session.permissions indexOfObject:@"publish_actions"] == NSNotFound) {
        // if we don't already have the permission, then we request it now
        [session requestNewPublishPermissions:@[@"publish_actions"]
                                              defaultAudience:FBSessionDefaultAudienceEveryone
                                            completionHandler:^(FBSession *session, NSError *error) {
                                                if (!error) {
                                                    action();
                                                }
                                                //For this example, ignore errors (such as if user cancels).
                                            }];
    } else {
        action();
    }
}

@end

#endif
