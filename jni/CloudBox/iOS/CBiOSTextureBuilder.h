//
//  CBiOSTextureBuilder.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Refactoring by Cloud on 2012/12/09.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#ifndef _CBIOSTEXTUREBUILDER_H_
#define _CBIOSTEXTUREBUILDER_H_

#include "CBTextureBuilderBase.h"


class CBiOSTextureBuilder : public CBTextureBuilderBase
{
private:
	// --- Add private member --- //
public:
	// --- Add public member --- //
	CBiOSTextureBuilder();
	~CBiOSTextureBuilder();
	
	CBTexture* buildTexture(const string& filename);
	CBTexture* buildStringTexture(const string& text,const float size);
};

#endif