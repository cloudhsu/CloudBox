/*
 *  CBBuilderAndroid.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBBUILDERANDROID_H_
#define _CBBUILDERANDROID_H_

#include "../_CBBuilder.h"
#include "../../libpng/png.h"

class CBBuilderAndroid : public _CBBuilder
{
private:
	// --- Add private member --- //
	GLuint CreateText(const char* text, float size,float& rWidth, float& rHeight);
public:
	// --- Add public member --- //
	CBBuilderAndroid();
	~CBBuilderAndroid();
	GLuint ReloadText(const string& text, const float size);
	GLuint ReloadTexture(const string& filename);
	CBTexture* BuildTexture(const string& filename);
	CBTexture* BuildStringTexture(const string& text, const float size);
};

#endif
