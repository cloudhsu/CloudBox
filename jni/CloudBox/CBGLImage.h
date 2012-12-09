/*
 *  CBGLImage.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/28.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBGLIMAGE_H_
#define _CBGLIMAGE_H_

#include "CBImageBase.h"
#include <iostream>
#include <sstream>
using namespace std;

class CBTexture;

class CBGLImage : public CBImageBase
{
protected:
	string m_textureKey;
	CBTexture* m_mainTexture;
	
	void setTexture(CBTexture *tex, float x, float y, float w, float h);
	void setTexture(CBTexture *tex);
	
public:
	CBGLImage();
	virtual ~CBGLImage();
	
	void draw(CBView* view);
	void loadImage(const string& fileName, float& width, float& height);
	void createTextImage(const string& text, float size, float& width, float& height);
};

#endif