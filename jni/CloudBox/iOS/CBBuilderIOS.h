//
//  CBBuilderIOS.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#ifndef _CBBUILDERIOS_H_
#define _CBBUILDERIOS_H_

#include "_CBBuilder.h"


class CBBuilderIOS : public _CBBuilder
{
private:
	// --- Add private member --- //
public:
	// --- Add public member --- //
	CBBuilderIOS();
	~CBBuilderIOS();
	
	GLuint ReloadText(const string& text,const float size);
    GLuint ReloadTexture(const string& filename);
	CBTexture* BuildTexture(const string& filename);
	CBTexture* BuildStringTexture(const string& text,const float size);
};

#endif