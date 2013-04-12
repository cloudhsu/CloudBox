/*
 *  GameCenterManager.m
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import "GameCenterManager.h"

@implementation GameCenterManager

@synthesize isLogon = _isLogon;
@synthesize controller = _controller;

static GameCenterManager* _sharedInstance = nil;

+(GameCenterManager*) sharedInstance
{
	@synchronized([GameCenterManager class])
	{
		if (!_sharedInstance)
			[[self alloc] init];
		
		return _sharedInstance;
	}
	
	return nil;
}

+(id) alloc
{
	@synchronized([GameCenterManager class])
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
    }
    return self;
}

- (void)dealloc {
	[_sharedInstance release];
	[self dealloc];
    [super dealloc];
}

- (BOOL) isGameCenterAvailable
{
	// check for presence of GKLocalPlayer API
	Class gcClass = (NSClassFromString(@"GKLocalPlayer"));
	
	// check if the device is running iOS 4.1 or later
	NSString *reqSysVer = @"4.1";
	NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
	BOOL osVersionSupported = ([currSysVer compare:reqSysVer options:NSNumericSearch] != NSOrderedAscending);
	
	return (gcClass && osVersionSupported);
}

- (NSString *)localPlayerId {
    if([self isGameCenterAvailable]) {
        if([GKLocalPlayer localPlayer].authenticated) {
            return [GKLocalPlayer localPlayer].playerID;
        }
    }
    return @"unknownPlayer";
}

//- (void) showAchievements
//{
//    if(delegate != nil)
//    {
//        [delegate showAchievements];
//    }
//}
//
//- (void) showLeaderboard;
//{
//    if(delegate != nil)
//    {
//        [delegate showLeaderboard];
//    }
//}

- (void) login
{
    if(![self isGameCenterAvailable])
    {
        NSLog(@"It's not support game center.");
        return;
    }
    if([GKLocalPlayer localPlayer].authenticated == NO)
	{
		[[GKLocalPlayer localPlayer] authenticateWithCompletionHandler:^(NSError *error)
         {
             if(error == NULL)
             {
                 _isLogon = YES;
             }
             else
             {
                 _isLogon = NO;
                 NSString* errorMsg = [NSString stringWithFormat: @"Reason: %@", [error localizedDescription]];
                 NSLog(@"Login error, %@", errorMsg);
             }
         }];
	}
}

- (void)submitAchievement:(NSString *)identifier percentComplete:(double)percentComplete
{
    if(_isLogon)
    {
        GKAchievement* achievement = [[[GKAchievement alloc] initWithIdentifier: identifier] autorelease];
        achievement.percentComplete= percentComplete;
        [achievement reportAchievementWithCompletionHandler: ^(NSError *error)
         {
             if(error != NULL)
             {
                 NSString* errorMsg = [NSString stringWithFormat: @"Reason: %@", [error localizedDescription]];
                 NSLog(@"Submit Achievement error, %@", errorMsg);
             }
         }];
    }
    else
    {
        NSLog(@"You must login Game Center.");
    }
}

// Resets local player's achievements
- (void)resetAchievements
{
    if(_isLogon)
    {
        [GKAchievement resetAchievementsWithCompletionHandler: ^(NSError *error)
         {
             if(error != NULL)
             {
                 NSString* errorMsg = [NSString stringWithFormat: @"Reason: %@", [error localizedDescription]];
                 NSLog(@"Reset Achievements error, %@", errorMsg);
             }
         }];
    }
    else
    {
        NSLog(@"You must login Game Center.");
    }
}

- (void) reportScore: (int64_t) score forCategory: (NSString*) category
{
    if(_isLogon)
    {
        GKScore *scoreReporter = [[[GKScore alloc] initWithCategory:category] autorelease];
        scoreReporter.value = score;
        [scoreReporter reportScoreWithCompletionHandler: ^(NSError *error)
        {
            if(error != NULL)
            {
                NSString* errorMsg = [NSString stringWithFormat: @"Reason: %@", [error localizedDescription]];
                NSLog(@"Report Score error, %@", errorMsg);
            }
        }];
    }
    else
    {
        NSLog(@"You must login Game Center.");
    }
}

- (void) showLeaderboard;
{
	GKLeaderboardViewController *leaderboardController = [[GKLeaderboardViewController alloc] init];
	if (leaderboardController != NULL)
	{
		leaderboardController.timeScope = GKLeaderboardTimeScopeAllTime;
		leaderboardController.leaderboardDelegate = self;
		[_controller presentModalViewController: leaderboardController animated: YES];
	}
}

- (void) showAchievements
{
	GKAchievementViewController *achievements = [[GKAchievementViewController alloc] init];
	if (achievements != NULL)
	{
		achievements.achievementDelegate = self;
		[_controller presentModalViewController: achievements animated: YES];
	}
}

#pragma mark GameCenter View Controllers
- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController
{
	[_controller dismissModalViewControllerAnimated: YES];
	[viewController release];
}

- (void)achievementViewControllerDidFinish:(GKAchievementViewController *)viewController;
{
	[_controller dismissModalViewControllerAnimated: YES];
	[viewController release];
}

@end
