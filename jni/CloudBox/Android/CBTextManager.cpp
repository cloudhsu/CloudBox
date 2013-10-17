/*
 *  CBTextManager.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBTextManager.h"
#include "def.h"
#include "../CBLibrary.h"

CBTextManager::CBTextManager()
{
	initialJNIClass("com/clouddevelop/cloudbox/TextManager");
	m_create = g_env->GetMethodID(m_mainClass, "create",
		                         "(Ljava/lang/String;F)Landroid/graphics/Bitmap;");
	m_getWidth = g_env->GetMethodID(m_mainClass, "getWidth", "(Landroid/graphics/Bitmap;)I");
	m_getHeight = g_env->GetMethodID(m_mainClass, "getHeight", "(Landroid/graphics/Bitmap;)I");
	m_getPixels = g_env->GetMethodID(m_mainClass, "getPixels", "(Landroid/graphics/Bitmap;[I)V");
	m_close = g_env->GetMethodID(m_mainClass, "close", "(Landroid/graphics/Bitmap;)V");
}
CBTextManager::~CBTextManager()
{
}

jobject CBTextManager::create(const char* text, float size)
{
	jstring data = g_env->NewStringUTF(text);
	jobject textImage = g_env->CallObjectMethod(m_mainObject, m_create, data, size);
	g_env->DeleteLocalRef(data);
	g_env->NewGlobalRef(textImage);
	return textImage;
}
int CBTextManager::getWidth(jobject textImage)
{
	int width = g_env->CallIntMethod(m_mainObject, m_getWidth, textImage);
	return width;
}
int CBTextManager::getHeight(jobject textImage)
{
	int height = g_env->CallIntMethod(m_mainObject, m_getHeight, textImage);
	return height;
}

void CBTextManager::close(jobject textImage)
{
	/* Free image */
	g_env->CallVoidMethod(m_mainObject, m_close, textImage);
	g_env->DeleteGlobalRef(textImage);
}

GLuint CBTextManager::createText(const char* text, float size,float& rWidth, float& rHeight)
{
	/* Ask the PNG manager for a bitmap */
	LOGI("Start create text.");
	//jobject textImage = create(text,size);
	jstring data = g_env->NewStringUTF(text);
	jobject textImage = g_env->CallObjectMethod(m_mainObject, m_create, data, size);
	g_env->DeleteLocalRef(data);
	g_env->NewLocalRef(textImage);
	LOGI("Create text image succeed.");

	/* Get image dimensions */
	int width = getWidth(textImage);
	int height = getHeight(textImage);
	rWidth = width;
	rHeight = height;

	/* Get pixels */
	jintArray image_data = g_env->NewIntArray(width * height);
	//g_env->NewGlobalRef(image_data);
	g_env->NewLocalRef(image_data);
	g_env->CallVoidMethod(m_mainObject, m_getPixels, textImage, image_data);

	jint *pixels = g_env->GetIntArrayElements(image_data, 0);

	//Now generate the OpenGL texture object
	GLuint texture = 0;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
	      GL_UNSIGNED_BYTE, (GLvoid*) pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	g_env->ReleaseIntArrayElements(image_data, pixels, 0);
	//g_env->DeleteGlobalRef(image_data);
	g_env->DeleteLocalRef(image_data);

	/* Free image */
	LOGI("Start close text image.");
	//close(textImage);
	g_env->CallVoidMethod(m_mainObject, m_close, textImage);
	g_env->DeleteLocalRef(textImage);
	LOGI("Close text image succeed.");

	return texture;
}
