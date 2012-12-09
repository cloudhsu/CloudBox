/*
 *  CBBuilderAndroid.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAndroidTextureBuilder.h"
#include "../CBTexture.h"
#include "../CBImage.h"
#include "../CBLabel.h"
#include "../CBButton.h"
#include "../CBScene.h"
#include "../CBSprite.h"
#include "../CBString.h"
#include "../CBNumber.h"
#include "../CBTexturePool.h"
#include "../CBLibrary.h"
#include "CBTextManager.h"
#include "utils.h"

CBAndroidTextureBuilder::CBAndroidTextureBuilder()
{
	// construct
}

CBAndroidTextureBuilder::~CBAndroidTextureBuilder()
{
	// Deconstruct
}

GLuint CBAndroidTextureBuilder::reloadText(const string& text, const float size)
{
	float width = 0;
	float height = 0;
	//GLuint texID = createText(text.c_str(),size,&width,&height);
	GLuint texID = CreateText(text.c_str(), size, width, height);
	//DebugLog("CBBuilderAndroid::ReloadText:%s,%d",s.c_str(),texID);
	return texID;
}

GLuint CBAndroidTextureBuilder::reloadTexture(const string& filename)
{
	int width = 0;
	int height = 0;
	string name = "assets/" + filename;
	GLuint texID = loadTextureFromPNG(name.c_str(), width, height);
	//DebugLog("CBBuilderAndroid::ReloadTexture:%s,%d",filename.c_str(),texID);
    return texID;
}

CBTexture* CBAndroidTextureBuilder::buildTexture(const string& filename)
{
	string name = "assets/" + filename;
	int width = 0;
	int height = 0;
	CBTexture* texture;
	GLuint texID = loadTextureFromPNG(name.c_str(), width, height);
	texture = new CBTexture(texID, width, height, width, height);
	return texture;
}

CBTexture* CBAndroidTextureBuilder::buildStringTexture(const string& text, const float size)
{
	float width = 0;
	float height = 0;
	CBTexture* texture;
	GLuint texID = CreateText(text.c_str(), size, width, height);
	texture = new CBTexture(texID, width, height, width, height, text, size);
	return texture;
}

GLuint CBAndroidTextureBuilder::CreateText(const char* text, float size,float& rWidth, float& rHeight)
{
	static CBTextManager manager;
	return manager.createText(text, size, rWidth, rHeight);
}

