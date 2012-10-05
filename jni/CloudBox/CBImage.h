/*
 *  CBImage.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/31.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBIMAGE_H_
#define _CBIMAGE_H_

#include <iostream>
using namespace std;
#include "CBView.h"

class CBImageBase;

class CBImage : public CBView
{
protected:
	CBImageBase* m_image;
	CBImage();
	virtual void draw();
	
	float m_imageWidth;
	float m_imageHeight;
	
	void loadImage(const string& fileName);
	void createTextImage(const string& text,float size);
	
public:
	CBImage(const string& fileName);
	CBImage(const string& text,float size);
	~CBImage();
	
	inline const float getImageWidth() { return m_imageWidth; }
	inline const float getImageHeight() { return m_imageHeight; }
	inline void setImageWidth(float imageWidth) { m_imageWidth = imageWidth; }
	inline void setImageHeight(float imageHeight) { m_imageHeight = imageHeight; }
};


#endif
