/*
 *  CBAndroidFacebookExhibitor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBANDROIDFACEBOOKEXHIBITOR_H__
#define __CBANDROIDFACEBOOKEXHIBITOR_H__

#include "CBJNI.h"
#include "CBCommunityExhibitor.h"
#include <string>
using namespace std;

class CBAndroidFacebookExhibitor : public CBCommunityExhibitorBase, public CBJNI
{
private:
	jmethodID m_login;
	jmethodID m_logout;
	jmethodID m_postMsg;
	jmethodID m_postImage;
	jmethodID m_postFeed;
public:
    CBAndroidFacebookExhibitor();
    ~CBAndroidFacebookExhibitor();
    
    // define function for achievement exhibtion
    void autoLogin();
    void login();
    void logout();
    void post(CBAchievementItem* object);

    void postStatus(string msg);
    void postStatus(string msg,string imageName);
    void postFeed(string name,string link, string caption, string description, string msg);
};

#endif
