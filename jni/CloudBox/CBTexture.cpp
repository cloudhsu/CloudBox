//
//  CBTexture.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#include "CBTexture.h"
#include "CBTexturePool.h"
#include "CBEnvironment.h"
#ifdef __CBANDROID__
#include "CBTextureBuilder.h"
#endif

CBTexture::CBTexture(GLuint texId, float width, float height, float texWidth, float texHeight)
:m_textureId(texId), m_key(""), m_imageWidth(width), m_imageHeight(height),
m_textureWidth(texWidth), m_textureHeight(texHeight),m_isText(false)
{
	m_maxS = m_imageWidth / m_textureWidth;
	m_maxT = m_imageHeight / m_textureHeight;
}

CBTexture::CBTexture(GLuint texId, float width, float height, float texWidth, float texHeight,int fontSize)
:m_textureId(texId), m_key(""), m_imageWidth(width), m_imageHeight(height),
m_textureWidth(texWidth), m_textureHeight(texHeight),m_isText(true),m_fontSize(fontSize)
{
	m_maxS = m_imageWidth / m_textureWidth;
	m_maxT = m_imageHeight / m_textureHeight;
}

CBTexture::CBTexture(GLuint texId, float width, float height, float texWidth, float texHeight, string text,int fontSize)
:m_textureId(texId), m_key(""), m_imageWidth(width), m_imageHeight(height),
m_textureWidth(texWidth), m_textureHeight(texHeight),m_isText(true), m_text(text),m_fontSize(fontSize)
{
	m_maxS = m_imageWidth / m_textureWidth;
	m_maxT = m_imageHeight / m_textureHeight;
}

CBTexture::CBTexture()
:m_textureId(0), m_key(""), m_imageWidth(0), m_imageHeight(0), m_textureWidth(0), m_textureHeight(0),m_isText(false)
{
}

#ifdef __CBANDROID__
void CBTexture::reload()
{
	if(m_isText)
	{
		m_textureId = STextureBuilder.reloadText(m_text,m_fontSize);
	}
	else {
		m_textureId = STextureBuilder.reloadTexture(m_key);
	}
}
#endif

void CBTexture::release()
{
    if(m_textureId)
	{
		glDeleteTextures(1, &m_textureId);
		m_textureId = 0;
	}
}

void CBTexture::poolable(const string& key)
{
	m_key = key;
}

void CBTexture::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_textureId);
}

CBTexture::~CBTexture()
{
	release();
}
