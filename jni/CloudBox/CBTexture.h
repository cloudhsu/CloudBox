//
//  CBTexture.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#ifndef _CBTEXTURE_H_
#define _CBTEXTURE_H_

#ifdef WIN32
// for win32
#include <GL/glut.h>
#elif __CBIOS__
// for ios
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#else
// for android
#include <EGL/egl.h>
#include <GLES/gl.h>
#endif
#include <iostream>
using namespace std;

class CBTexture
{
private:
	int m_fontSize;
	bool m_isText;
	GLuint m_textureId;
	float m_imageWidth;
	float m_imageHeight;
	float m_textureWidth;
	float m_textureHeight;
	string m_key;
	string m_text;
	
	float m_maxS;
	float m_maxT;
	
	CBTexture();
public:
	CBTexture(GLuint texId, float width, float height, float texWidth, float texHeight);
	CBTexture(GLuint texId, float width, float height, float texWidth, float texHeight,int fontSize);
	CBTexture(GLuint texId, float width, float height, float texWidth, float texHeight, string text, int fontSize);
	~CBTexture();
#ifdef __CBANDROID__
    void reload();
#endif
    void release();
	
	void bind();
	
	void poolable(const string& key);
	
	inline const string getKey() { return m_key; }
	inline const int getFontSize() { return m_fontSize; }
	inline const bool getIsText() { return m_isText; }
	inline const GLuint getTextureId() { return m_textureId; }
	inline const float getImageWidth() { return m_imageWidth; }
	inline const float getImageHeight() { return m_imageHeight; }
	inline const float getTextureWidth() { return m_textureWidth; }
	inline const float getTextureHeight() { return m_textureHeight; }
	inline const float getMaxS() { return m_maxS; }
	inline const float getMaxT() { return m_maxT; }
};

#endif
