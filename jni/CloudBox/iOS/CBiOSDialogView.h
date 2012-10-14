/*
 *  CBiOSDialogView.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/13.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CBDialogEnum.h"

class CBDialog;

@interface CBiOSDialogView : NSObject
{
    DialogResult _result;
    DialogType _type;
}

-(void) showDialog:(NSString*)title Message:(NSString*)msg;
-(id) initWithType:(DialogType) type;
-(DialogResult) getResult;

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

@end
