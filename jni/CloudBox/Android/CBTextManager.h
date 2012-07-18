/*
 *  CBTextManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include <jni.h>
#include <GLES/gl.h>
#include "CBJNI.h"

class CBImageData;

class CBTextManager : public CBJNI
{
private:
	jmethodID m_create;
	jmethodID m_getWidth;
	jmethodID m_getHeight;
	jmethodID m_getPixels;
	jmethodID m_close;

	jobject create(const char* text, float size);
	int getWidth(jobject textImage);
	int getHeight(jobject textImage);
	//void getPixels();
	void close(jobject textImage);
public:
	CBTextManager();
	~CBTextManager();

	GLuint createText(const char* text, float size,float& rWidth, float& rHeight);
	CBImageData* createText(const char* text, float size);
};
