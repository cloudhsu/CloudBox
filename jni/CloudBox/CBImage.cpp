/*
 *  CBImage.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/31.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBImage.h"
#include "CBImageBase.h"
#include "CBImageFactory.h"
#include "CBLayout.h"

CBImage::CBImage()
:CBView()
{
}

CBImage::CBImage(const string& fileName)
:CBView()
{
	loadImage(fileName);
}

CBImage::CBImage(const string& text,float size)
:CBView()
{
	createTextImage(text, size);
}

CBImage::~CBImage()
{
}

void CBImage::draw()
{
	if(!this->getVisible())
		return;
	m_image->draw(this);
}

void CBImage::loadImage(const string& fileName)
{
	m_image = CBImageFactory::CreateImage();
	m_image->loadImage(fileName, m_width, m_height);
    SLayout.scaleSize(m_width,m_height);
}

void CBImage::createTextImage(const string& text,float size)
{
	m_image = CBImageFactory::CreateImage();
	m_image->createTextImage(text, size, m_width, m_height);
    SLayout.scaleSize(m_width,m_height);
}
