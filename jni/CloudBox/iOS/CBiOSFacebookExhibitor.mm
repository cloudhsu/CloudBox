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