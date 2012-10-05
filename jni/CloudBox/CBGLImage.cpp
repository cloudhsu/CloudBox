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
#include "CBTexturePool.h"
#include "CBTextureCallback.h"
#include "CBTextCallback.h"
#include "CBOpenGL.h"

#ifdef WIN32
// for win32
#elif __CBIOS__
// for ios
#include "CBiOSImageBuilder.h"
CBImageBuilder* CBGLImage::builder = new CBiOSImageBuilder();
#else
// for android
//#include "Android/CBAndroidImageBuilder.h"
//CBImageBuilder* CBGLImage::builder = new CBAndroidImageBuilder();
CBImageBuilder* CBGLImage::builder = NULL;
#endif

CBGLImage::CBGLImage()
:m_mainTexture(NULL)
{
//	m_textureCallback = new CBTextureCallback();
//	m_textureCallback->addCallbackEvent(this,&CBGLImage::_initialTexture);
}

CBGLImage::~CBGLImage()
{
	if(m_mainTexture)
	{
		m_mainTexture = NULL;
	}
//	DELETE(m_textCallback);
//	DELETE(m_textureCallback);
}

void CBGLImage::_initialTexture(CBImageData* imageData)
{
	GLuint textureID = SOpenGL.generateTexture(imageData);
	if(imageData->isText)
	{
		m_mainTexture = new CBTexture(textureID, imageData->imageWidth, imageData->imageHeight,
									  imageData->textureWidth, imageData->textureHeight,
									  imageData->text,imageData->size);
	}
	else
	{
		m_mainTexture = new CBTexture(textureID, imageData->imageWidth, imageData->imageHeight,
								  imageData->textureWidth, imageData->textureHeight);
	}
	STexturePool.registerToPool(imageData->key,m_mainTexture);
	DELETE(imageData);
	isInitial = true;
}


CBImageData* CBGLImage::loadImageData(const string& fileName)
{
	return CBGLImage::builder->loadImageData(fileName);
}
CBImageData* CBGLImage::loadTextData(const string& text, float size)
{
	return CBGLImage::builder->loadTextData(text,size);
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
#ifdef __CBIOS__
		CBImageData* imageData = loadImageData(fileName);
		width = imageData->imageWidth;
		height = imageData->imageHeight;
		imageData->key = fileName;
		imageData->isText = false;
		//m_textureCallback->invoke(imageData);
		_initialTexture(imageData);
#else
		m_mainTexture = CBBuilder::BuildTexture(fileName);
		width = m_mainTexture->getImageWidth();
		height = m_mainTexture->getImageHeight();
		STexturePool.registerToPool(fileName,m_mainTexture);
		isInitial = true;
#endif
	}
	else
	{
		width = m_mainTexture->getImageWidth();
		height = m_mainTexture->getImageHeight();
	}
	DebugLog("Name:%s,texture id:%d,width:%f,height:%f\n",
			fileName.c_str(),m_mainTexture->getTextureId(),width,height);
}

void CBGLImage::createTextImage(const string& text,float size, float& width, float& height)
{
	stringstream textKey;
	textKey << text << "_" << size;
	m_mainTexture = STexturePool.getTexture(textKey.str());
	if(m_mainTexture == NULL)
	{
#ifdef __CBIOS__
		CBImageData* imageData = loadTextData(text,size);
		width = imageData->imageWidth;
		height = imageData->imageHeight;
		imageData->key = textKey.str();
		imageData->text = text;
		imageData->size = size;
		imageData->isText = true;
		_initialTexture(imageData);
#else
		m_mainTexture = CBBuilder::BuildStringTexture(text, size);
		width = m_mainTexture->getImageWidth();
		height = m_mainTexture->getImageHeight();
		DebugLog("textureID:%d,width:%f,height:%f\n",m_mainTexture->getTextureId(),width,height);
		STexturePool.registerToPool(textKey.str(),m_mainTexture);
		isInitial = true;
#endif
	}
	else
	{
		width = m_mainTexture->getImageWidth();
		height = m_mainTexture->getImageHeight();
	}
	DebugLog("Name:%s,texture id:%d\n",text.c_str(),m_mainTexture->getTextureId());
}
