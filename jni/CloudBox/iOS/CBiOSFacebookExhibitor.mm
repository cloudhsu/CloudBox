/*
 *  CBiOSFacebookExhibitor.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBiOSFacebookExhibitor.h"
#include "CBLibrary.h"
#include "FacebookManager.h"

CBiOSFacebookExhibitor::CBiOSFacebookExhibitor()
{

}

CBiOSFacebookExhibitor::~CBiOSFacebookExhibitor()
{

}

void CBiOSFacebookExhibitor::autoLogin()
{
    [[FacebookManager sharedInstance]autoLogin];
}

void CBiOSFacebookExhibitor::login()
{
    [[FacebookManager sharedInstance]login];
}
void CBiOSFacebookExhibitor::logout()
{
    [[FacebookManager sharedInstance]logout];
}

void CBiOSFacebookExhibitor::post(CBAchievementItem* object)
{
    string str = "You got " + object->getDescription();
    NSString *msg = [[[NSString alloc] initWithUTF8String: str.c_str()]autorelease];
    NSString *imageName = [[[NSString alloc] initWithUTF8String: object->getImageName().c_str()]autorelease];
    [[FacebookManager sharedInstance] postStatus:msg andImageName:imageName];
}

void CBiOSFacebookExhibitor::postStatus(string msg)
{
    NSString *message = [[[NSString alloc] initWithUTF8String: msg.c_str()]autorelease];
    [[FacebookManager sharedInstance] postStatus:message];
}
void CBiOSFacebookExhibitor::postStatus(string msg,string imageName)
{
    NSString *message = [[[NSString alloc] initWithUTF8String: msg.c_str()]autorelease];
    NSString *image = [[[NSString alloc] initWithUTF8String: imageName.c_str()]autorelease];
    [[FacebookManager sharedInstance] postStatus:message andImageName:image];
}
void CBiOSFacebookExhibitor::postFeed(string name,string link, string caption, string description, string msg)
{
    NSString *_name = [[[NSString alloc] initWithUTF8String: name.c_str()]autorelease];
    NSString *_link = [[[NSString alloc] initWithUTF8String: link.c_str()]autorelease];
    NSString *_caption = [[[NSString alloc] initWithUTF8String: caption.c_str()]autorelease];
    NSString *_description = [[[NSString alloc] initWithUTF8String: description.c_str()]autorelease];
    NSString *_msg = [[[NSString alloc] initWithUTF8String: msg.c_str()]autorelease];
    
    [[FacebookManager sharedInstance] postFeed:_name andLink:_link andCaption:_caption andDesc:_description andMsg:_msg];
}