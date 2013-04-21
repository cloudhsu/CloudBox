//
//  CBAndroidUtility.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2012/11/11.
//  Copyright 2012 Orz. All rights reserved.
//

#include "CBAndroidUtility.h"
#include "def.h"
#include "../CBLibrary.h"

CBAndroidUtility::CBAndroidUtility()
{
	initialJNIClass("com/clouddevelop/cloudbox/CBUtility");
	m_openUrl = g_env->GetStaticMethodID(m_mainClass, "openUrl", "(Ljava/lang/String;)V");
}

CBAndroidUtility::~CBAndroidUtility()
{
    
}

string CBAndroidUtility::getDocumentPath(const string& fileName)
{
	string dir("/data/data/");
	DebugLog("apk Path:%s\n",g_apkPath.c_str());
	size_t pos = g_apkPath.find(".apk");
	string tmp = g_apkPath.substr(0, pos);
	dir.append(tmp).append("/").append(fileName);
	DebugLog("System Path:%s\n",dir.c_str());
	return dir;
}

string CBAndroidUtility::getResourcePath(const string& fileName)
{
    string dir("asset/");
    dir.append(fileName);
    return dir;
}

string CBAndroidUtility::getLanguage()
{
    return "en";
}

DeviceType CBAndroidUtility::getDeviceType()
{
    return DeviceAndroidPhone;
}
void CBAndroidUtility::openUrl(const string& url)
{
	jstring data = g_env->NewStringUTF(url.c_str());
	g_env->CallStaticVoidMethod(m_mainClass, m_openUrl, data);
	g_env->DeleteLocalRef(data);
	DebugLog("CBAndroidUtility openUrl succeed.\n");
}
