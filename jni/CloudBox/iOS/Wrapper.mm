//
//  Wrapper.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/8/18.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#import "Wrapper.h"


const char *GetPath(const char *s, const char *directory)
{
	NSString *dir = nil;
	if (directory)
		dir = [[NSString alloc] initWithUTF8String: directory];
	NSString *name = [[NSString alloc] initWithUTF8String: s];
	NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:nil inDirectory:dir];
	
	return [path UTF8String];
	
}