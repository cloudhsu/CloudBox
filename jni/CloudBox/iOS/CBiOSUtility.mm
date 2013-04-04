//
//  CBiOSUtility.ㄝ
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/10/17.
//  Copyright 2012 Orz. All rights reserved.
//

#import "CBiOSUtility.h"
#import <Foundation/Foundation.h>

CBiOSUtility::CBiOSUtility()
{
    
}

CBiOSUtility::~CBiOSUtility()
{
    
}

string CBiOSUtility::getDocumentPath(const string& fileName)
{
    NSString *name = [[[NSString alloc] initWithUTF8String: fileName.c_str()]autorelease];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES); //1
	NSString *documentsDirectory = [paths objectAtIndex:0]; //2
	NSString *path = [documentsDirectory stringByAppendingPathComponent:name]; //3
    
    return string([path UTF8String]);
}

string CBiOSUtility::getResourcePath(const string& fileName)
{
    NSString *name = [[[NSString alloc] initWithUTF8String: fileName.c_str()]autorelease];
    NSString *tileDirectory = [[NSBundle mainBundle] resourcePath];
	NSString *path = [tileDirectory stringByAppendingPathComponent:name]; //3
    
    return string([path UTF8String]);
}

string CBiOSUtility::getLanguage()
{
    return "en";
}
DeviceType CBiOSUtility::getDeviceType()
{
    return DeviceiPhone;
}
void CBiOSUtility::openUrl(const string& url)
{
    NSString *myUrl = [[[NSString alloc] initWithUTF8String: url.c_str()]autorelease];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:myUrl]];
}