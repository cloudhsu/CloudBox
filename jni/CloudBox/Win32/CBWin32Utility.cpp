//
//  CBWin32Utility.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2013/03/25.
//  Copyright 2013 Orz. All rights reserved.
//

#include "CBWin32Utility.h"
#include "../CBLibrary.h"

CBWin32Utility::CBWin32Utility()
{
}

CBWin32Utility::~CBWin32Utility()
{
    
}

string CBWin32Utility::getDocumentPath(const string& fileName)
{
	return fileName;
}

string CBWin32Utility::getResourcePath(const string& fileName)
{
    string dir = "Win32Resource/";
    dir.append(fileName);
    return dir;
}

string CBWin32Utility::getLanguage()
{
    return "en";
}

DeviceType CBWin32Utility::getDeviceType()
{
    return DeviceWin32;
}
void CBWin32Utility::openUrl(const string& url)
{
	DebugLog("CBWin32Utility openUrl does not implement.\n");
}
