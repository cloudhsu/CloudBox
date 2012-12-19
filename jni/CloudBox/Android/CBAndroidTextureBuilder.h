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

#include "../CBTextureBuilderBase.h"
#include "../../libpng/png.h"

class CBAndroidTextureBuilder : public CBTextureBuilderBase
{
private:
	// --- Add private member --- //
	GLuint createText(const char* text, float size,float& rWidth, float& rHeight);
	// load texture from png
	GLuint loadTextureFromPNG (const char* filename, int &width, int &height, int &rpixWidth, int &rpixHeight);
public:
	// --- Add public member --- //
	CBAndroidTextureBuilder();
	~CBAndroidTextureBuilder();
	GLuint reloadText(const string& text, const float size);
	GLuint reloadTexture(const string& filename);
	CBTexture* buildTexture(const string& filename);
	CBTexture* buildStringTexture(const string& text, const float size);
};

#endif
