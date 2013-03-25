//
//  CBWin32Utility.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Hsu Cloud on 2013/03/25.
//  Copyright 2013 Orz. All rights reserved.
//

#ifndef _CBWIN32UTILITY_H_
#define _CBWIN32UTILITY_H_

#include "CBUtilityBase.h"
#include <string>
using namespace std;

class CBWin32Utility : public CBUtilityBase
{
public:
	CBWin32Utility();
    ~CBWin32Utility();
    
    string getDocumentPath(const string& fileName);
    string getResourcePath(const string& fileName);
	string getLanguage();
    DeviceType getDeviceType();
    void openUrl(const string& url);
};

#endif
