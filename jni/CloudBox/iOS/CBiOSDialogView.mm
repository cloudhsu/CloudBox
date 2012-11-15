/*
 *  CBiOSDialogView.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/13.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#import "CBDialog.h"
#import "CBiOSDialogView.h"
#import "CBDialogManager.h"

@implementation CBiOSDialogView

-(id) initWithType:(DialogType) type
{
    if ((self = [super init])) {
        // Initialization code
		_type = type;
    }
    return self;
}
-(DialogResult) getResult
{
    return _result;
}

-(void) showDialog:(NSString*)title Message:(NSString*)msg
{
    UIAlertView *alert = nil;
    if(DialogTypeYesNo == _type)
    {
        alert = [[UIAlertView alloc] initWithTitle:title
                                           message:msg
                                          delegate: self
                                 cancelButtonTitle:nil
                                 otherButtonTitles: @"Yes", @"No", nil];
    }
    else if(DialogTypeOKCancel == _type)
    {
        alert = [[UIAlertView alloc] initWithTitle:title
                                           message:msg
                                          delegate: self
                                 cancelButtonTitle:nil
                                 otherButtonTitles: @"OK", @"Cancel", nil];
    }
    else if(DialogTypeRate == _type)
    {
        alert = [[UIAlertView alloc] initWithTitle:title
                                           message:msg
                                          delegate: self
                                 cancelButtonTitle:nil
                                 otherButtonTitles: @"Rate", @"Cancel", @"Never", nil];
    }
    else // DialogTypeOK
    {
        NSString* buttonText = @"Close";
        if(DialogTypeOK == _type)
        {
            buttonText = @"Close";
        }
        else if(DialogTypeCancel == _type)
        {
            buttonText = @"Cancel";
        }
        alert = [[UIAlertView alloc] initWithTitle:title
                                           message:msg
                                          delegate: self
                                 cancelButtonTitle:nil
                                 otherButtonTitles: buttonText, nil];
    }
    [alert show];
    [alert autorelease];
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if(DialogTypeYesNo == _type)
    {
        _result = (DialogResult)(DialogResultYes + buttonIndex);
    }
    else if(DialogTypeOKCancel == _type)
    {
        _result = (DialogResult)(DialogResultOK + buttonIndex);
    }
    else if(DialogTypeRate == _type)
    {
        _result = (DialogResult)(DialogResultRateMe + buttonIndex);
    }
    else // DialogTypeOK
    {
        _result = DialogResultOK;
    }
    
    //_instance->alertEvent(_result, buttonIndex);
    SDialogManager.alertEvent(_result, buttonIndex);
}

@end
