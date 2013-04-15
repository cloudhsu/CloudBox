/*
 *  GameCenterManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/04.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>

@interface GameCenterManager : NSObject <GKLeaderboardViewControllerDelegate, GKAchievementViewControllerDelegate>
{
    BOOL _isLogon;
    UIViewController* _controller;
}

+ (GameCenterManager *) sharedInstance;

- (void) submitAchievement:(NSString *)identifier percentComplete:(double)percentComplete;

// Resets local player's achievements
- (void) resetAchievements;

// Returns currently authenticated local player. If no player is authenticated, "unknownPlayer" is returned.
- (NSString *) localPlayerId;

- (BOOL) isGameCenterAvailable;

- (void) showAchievements;
- (void) showLeaderboard;

- (void) login;

- (void) reportScore: (int64_t) score forCategory: (NSString*) category;

@property (nonatomic, readonly) BOOL isLogon;
@property (nonatomic, assign)  UIViewController* controller;

@end
