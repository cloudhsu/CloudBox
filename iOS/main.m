//
//  main.m
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud Hsu on 2011/7/3.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#import <UIKit/UIKit.h>

int main(int argc, char *argv[]) {
    
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    int retVal = UIApplicationMain(argc, argv, nil, @"CloudGameAppDelegate");
    [pool release];
    return retVal;
}
