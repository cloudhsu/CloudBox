//
//  CloudLib.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2010/11/28.
//  Copyright 2010 Cloud Hsu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CloudLib : NSObject {
	int m_appleID;
}

+(CloudLib*)sharedLib;
-(void)reviewFor:(int)appleID;
-(void)openApp:(int)appID;
-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
-(void)sendEmailTo:(NSString *)to withCC:(NSString *)cc withSubject:(NSString *) subject withBody:(NSString *)body;
-(bool)checkCrackForSingerIdentityKey;
//-(bool)checkCrackForCodeFileExist;
-(bool)checkCrackForBinaryCreateTime;
@end
