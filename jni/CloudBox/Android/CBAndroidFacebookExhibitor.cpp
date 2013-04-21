/*
 *  CBAndroidFacebookExhibitor.mm
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/04/01.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAndroidFacebookExhibitor.h"
#include "../CBLibrary.h"
#include "def.h"

CBAndroidFacebookExhibitor::CBAndroidFacebookExhibitor()
{
	DebugLog("Create CBAndroidFacebookExhibitor.\n");
	initialJNIClass("com/clouddevelop/cloudbox/CBCommunityUtility");
	m_login = g_env->GetStaticMethodID(m_mainClass, "loginFB", "()V");
	m_logout = g_env->GetStaticMethodID(m_mainClass, "logoutFB", "()V");
	m_postMsg = g_env->GetStaticMethodID(m_mainClass, "postStatusToFB", "(Ljava/lang/String;)V");
	m_postImage = g_env->GetStaticMethodID(m_mainClass, "postStatusToFB", "(Ljava/lang/String;Ljava/lang/String;)V");
	m_postFeed = g_env->GetStaticMethodID(m_mainClass, "postFeedToFB", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
}

CBAndroidFacebookExhibitor::~CBAndroidFacebookExhibitor()
{

}

void CBAndroidFacebookExhibitor::autoLogin()
{
	// Android auto login function is called by activity
	DebugLog("Call CBAndroidFacebookExhibitor autoLogin.\n");
}
void CBAndroidFacebookExhibitor::login()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_login);
	DebugLog("Call CBAndroidFacebookExhibitor login.\n");
}
void CBAndroidFacebookExhibitor::logout()
{
	g_env->CallStaticVoidMethod(m_mainClass, m_logout);
	DebugLog("Call CBAndroidFacebookExhibitor logout.\n");
}

void CBAndroidFacebookExhibitor::post(CBAchievementItem* object)
{
	string str = "You got " + object->getDescription();
	jstring msg = g_env->NewStringUTF(str.c_str());
	jstring imageName = g_env->NewStringUTF(object->getImageName().c_str());

	g_env->CallStaticVoidMethod(m_mainClass, m_postImage, msg, imageName);

	g_env->DeleteLocalRef(msg);
	g_env->DeleteLocalRef(imageName);
	DebugLog("Call CBAndroidFacebookExhibitor post.\n");
}

void CBAndroidFacebookExhibitor::postStatus(string msg)
{
	jstring _msg = g_env->NewStringUTF(msg.c_str());

	g_env->CallStaticVoidMethod(m_mainClass, m_postMsg, _msg);

	g_env->DeleteLocalRef(_msg);
	DebugLog("Call CBAndroidFacebookExhibitor postStatus.\n");
}

void CBAndroidFacebookExhibitor::postStatus(string msg,string imageName)
{
	jstring _msg = g_env->NewStringUTF(msg.c_str());
	jstring _imageName = g_env->NewStringUTF(imageName.c_str());

	g_env->CallStaticVoidMethod(m_mainClass, m_postImage, _msg, _imageName);

	g_env->DeleteLocalRef(_msg);
	g_env->DeleteLocalRef(_imageName);
	DebugLog("Call CBAndroidFacebookExhibitor postStatus.\n");
}

void CBAndroidFacebookExhibitor::postFeed(string name,string link, string caption, string description, string msg)
{
	jstring _name = g_env->NewStringUTF(name.c_str());
	jstring _link = g_env->NewStringUTF(link.c_str());
	jstring _caption = g_env->NewStringUTF(caption.c_str());
	jstring _description = g_env->NewStringUTF(description.c_str());
	jstring _msg = g_env->NewStringUTF(msg.c_str());

	g_env->CallStaticVoidMethod(m_mainClass, m_postFeed, _name, _link, _caption, _description, _msg);

	g_env->DeleteLocalRef(_name);
	g_env->DeleteLocalRef(_link);
	g_env->DeleteLocalRef(_caption);
	g_env->DeleteLocalRef(_description);
	g_env->DeleteLocalRef(_msg);
	DebugLog("Call CBAndroidFacebookExhibitor postFeed.\n");
}
