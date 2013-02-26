/*
 *  CBWin32TextureBuilder.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/25.
 *  Copyright 2013 Orz. All rights reserved.
 *
 */

#ifndef _CBWIN32TEXTUREBUILDER_H_
#define _CBWIN32TEXTUREBUILDER_H_

#include <GL/glut.h>
#include "../CBTextureBuilderBase.h"

class CBWin32TextureBuilder : public CBTextureBuilderBase
{
private:
	// --- Add private member --- //
	GLuint createText(const char* text, float size,float& rWidth, float& rHeight);
	// load texture from png
	GLuint loadTextureFromPNG(const char* filename, int &width, int &height, int &rpixWidth, int &rpixHeight);
public:
	// --- Add public member --- //
	CBWin32TextureBuilder();
	~CBWin32TextureBuilder();

	CBTexture* buildTexture(const string& filename);
	CBTexture* buildStringTexture(const string& text, const float size);
};

#endif
