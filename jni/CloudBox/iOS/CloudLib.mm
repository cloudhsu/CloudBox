//
//  CloudLib.m
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2010/11/28.
//  Copyright 2010 Cloud Hsu. All rights reserved.
//

#import "CloudLib.h"


@implementation CloudLib

static CloudLib* _sharedLib = nil;

+(CloudLib*)sharedLib
{
	@synchronized([CloudLib class])
	{
		if (!_sharedLib)
			[[self alloc] init];
		
		return _sharedLib;
	}
	
	return nil;
}

+(id)alloc
{
	@synchronized([CloudLib class])
	{
		NSAssert(_sharedLib == nil, @"Attempted to allocate a second instance of a singleton.");
		_sharedLib = [super alloc];
		return _sharedLib;
	}
	
	return nil;
}

- (void)dealloc {
	[_sharedLib release];
	[self dealloc];
    [super dealloc];
}

-(void)reviewFor:(int)appleID
{
	m_appleID = appleID;
	BOOL neverRate = [[NSUserDefaults standardUserDefaults] boolForKey:@"neverRate"];
	int rnd = arc4random()%100;
	if(neverRate != YES && rnd < 40) {
		//Show alert here
		UIAlertView *alert;
		alert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"rate_title",@"Rate My Appication")
										   message:NSLocalizedString(@"rate_main",@"Give me 5-star rate?")
										  delegate: self
								 cancelButtonTitle:NSLocalizedString(@"rate_cancel",@"Cancel")
								 otherButtonTitles: NSLocalizedString(@"rate_now",@"Rate Now"),
				 NSLocalizedString(@"rate_never",@"Never Rate"), nil];
		[alert show];
		[alert release];
	}
}

-(void)openApp:(int)appID
{
	NSString *url = [NSString stringWithFormat:
					 @"http://itunes.apple.com/WebObjects/MZStore.woa/wa/viewSoftware?id=%d&mt=8",
					 appID ]; 
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]]; 
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
	// Never Review Button
	if (buttonIndex == 2)
	{
		[[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"neverRate"];
	}
	// Review Button
	else if (buttonIndex == 1)
	{
		[[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"neverRate"];
		NSString *str = [NSString stringWithFormat:
				@"itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%d",
				m_appleID ]; 
		[[UIApplication sharedApplication] openURL:[NSURL URLWithString:str]];
	}
}

- (void) sendEmailTo:(NSString *)to withCC:(NSString *)cc withSubject:(NSString *) subject withBody:(NSString *)body {
	NSString *mailString;
	if(cc == nil || [cc isEqualToString:@""])
	{
		mailString= [NSString stringWithFormat:@"mailto:?to=%@&subject=%@&body=%@",
				[to stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
				[subject stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
				[body  stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding]];
	}
	else {
		mailString= [NSString stringWithFormat:@"mailto:%@?cc=%@&subject=%@&body=%@",
				[to stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
				[cc stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
				[subject stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
				[body  stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding]];
	}
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:mailString]];
}

-(bool)checkCrackForSingerIdentityKey
{
	NSBundle *bundle = [NSBundle mainBundle];
	NSDictionary *info = [bundle infoDictionary];
	if ([info objectForKey: @"SignerIdentity"] != nil)
	{
		// crack app
		return YES;
	}
	return NO;
}

//-(bool)checkCrackForCodeFileExist
//{
//	NSString* bundlePath = [[NSBundle mainBundle] bundlePath];
//	
//	BOOL fileExists = [[NSFileManager defaultManager] fileExistsAtPath:(@"%@/_CodeSignature", bundlePath)];
//	
//	if (!fileExists) {
//		
//		// crack app
//		return YES;
//	}
//	
//	BOOL fileExists2 = [[NSFileManager defaultManager] fileExistsAtPath:(@"%@/CodeResources", bundlePath)];
//	
//	if (!fileExists2) {
//		
//		// crack app
//		return YES;
//	}
//	
//	BOOL fileExists3 = [[NSFileManager defaultManager] fileExistsAtPath:(@"%@/ResourceRules.plist", bundlePath)];
//	
//	if (!fileExists3) {
//		
//		// crack app
//		return YES;
//	}
//	
//	return NO;
//}

-(bool)checkCrackForBinaryCreateTime
{
//	NSString* bundlePath = [[NSBundle mainBundle] bundlePath];
//	
//    NSString* path = [NSString stringWithFormat:@"%@/Info.plist", bundlePath];
//	
//	NSBundle *bundle = [NSBundle mainBundle];
//	NSDictionary *info = [bundle infoDictionary];
//	
//	NSString* exeName = [info valueForKey: @"CFBundleExecutable"];
//	
//	NSString* path2 = [NSString stringWithFormat:@"%@/%@", bundlePath,exeName];
//	
//    NSDate* infoModifiedDate = 
//	[[[NSFileManager defaultManager] fileAttributesAtPath:path traverseLink:YES] fileModificationDate];
//	
//    NSDate* infoModifiedDate2 = 
//	[[[NSFileManager defaultManager] fileAttributesAtPath:path2 traverseLink:YES] fileModificationDate];
//	
//    NSDate* pkgInfoModifiedDate = 
//	[[[NSFileManager defaultManager] fileAttributesAtPath:[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"PkgInfo"] traverseLink:YES] fileModificationDate];
//	
//    if([infoModifiedDate timeIntervalSinceReferenceDate] > [pkgInfoModifiedDate timeIntervalSinceReferenceDate]) {
//		
//		// crack app
//		return YES;
//    }
//	
//    if([infoModifiedDate2 timeIntervalSinceReferenceDate] > [pkgInfoModifiedDate timeIntervalSinceReferenceDate]) {
//		
//		// crack app
//		return YES;
//    }
	return NO;
}

@end
