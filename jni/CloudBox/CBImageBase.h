/*
 *  CBImageBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/3/31.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBIMAGEBASE_H_
#define _CBIMAGEBASE_H_

#include <iostream>
using namespace std;

class CBView;

class CBImageBase
{
protected:
//	float m_imageWidth;
//	float m_imageHeight;
	bool isInitial;
public:
	CBImageBase():isInitial(false){}
	virtual ~CBImageBase(){}
	
//	inline const float getImageWidth() { return m_imageWidth; }
//	inline const float getImageHeight() { return m_imageHeight; }
//	inline void setImageWidth(float imageWidth) { m_imageWidth = imageWidth; }
//	inline void setImageHeight(float imageHeight) { m_imageHeight = imageHeight; }
	
	inline bool IsInitial() { return isInitial; }
	virtual void draw(CBView* view) = 0;
	//virtual void draw(float x, float y, float width, float height) = 0;
	virtual void loadImage(const string& fileName, float& width, float& height) = 0;
	virtual void createTextImage(const string& text,float size, float& width, float& height) = 0;
};


#endif