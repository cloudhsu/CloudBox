/*
 *  CBGLImage.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/28.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBView.h"
#include "CBGLImage.h"
#include "CBLayout.h"
#include "CBEnvironment.h"
#include "CBTexture.h"
#include "CBTexturePool.h"
#include "CBOpenGL.h"
#include "CBTextureBuilder.h"

CBGLImage::CBGLImage()
:m_mainTexture(NULL)
{
}

CBGLImage::~CBGLImage()
{
	if(m_mainTexture)
	{
		m_mainTexture = NULL;
	}
}


void CBGLImage::draw(CBView* view)
{
	if(m_mainTexture != NULL)
	{
		if(m_mainTexture->getIsText())
		{
			//DebugLog("draw text\n");
			SOpenGL.renderString(view,m_mainTexture);
		}
		else
		{
			SOpenGL.render(view,m_mainTexture);
		}
	}
}

void CBGLImage::loadImage(const string& fileName, float& width, float& height)
{
	m_mainTexture = STexturePool.getTexture(fileName);
	if(m_mainTexture == NULL)
	{
		m_mainTexture = STextureBuilder.buildTexture(fileName);
        if(m_mainTexture != NULL)
        {
		    width = m_mainTexture->getImageWidth();
		    height = m_mainTexture->getImageHeight();
		    STexturePool.registerToPool(fileName,m_mainTexture);
        }
        else
        {
            DebugLog("Generate texture error");
        }
	}
	else
	{
		width = m_mainTexture->getImageWidth();
		height = m_mainTexture->getImageHeight();
	}
//    if(m_mainTexture != NULL)
//	DebugLog("Name:%s,texture id:%d,width:%f,height:%f\n",
//			fileName.c_str(),m_mainTexture->getTextureId(),width,height);
}

void CBGLImage::createTextImage(const string& text,float size, float& width, float& height)
{
	stringstream textKey;
	textKey << text << "_" << size;
	m_mainTexture = STexturePool.getTexture(textKey.str());
	if(m_mainTexture == NULL)
	{
		m_mainTexture = STextureBuilder.buildStringTexture(text,size);
		width = m_mainTexture->getImageWidth();
		height = m_mainTexture->getImageHeight();
		//DebugLog("textureID:%d,width:%f,height:%f\n",m_mainTexture->getTextureId(),width,height);
		STexturePool.registerToPool(textKey.str(),m_mainTexture);
	}
	else
	{
		width = m_mainTexture->getImageWidth();
		height = m_mainTexture->getImageHeight();
	}
	//DebugLog("Name:%s,texture id:%d\n",text.c_str(),m_mainTexture->getTextureId());
}
