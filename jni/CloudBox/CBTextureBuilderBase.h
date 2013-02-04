/*
 *  CBTextureBuilderBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/12/09.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBTEXTUREBUILDERBASE_H_
#define _CBTEXTUREBUILDERBASE_H_

#include <iostream>
#include <string>
using namespace std;

#ifdef __CBANDROID__
#include <GLES/gl.h>
#endif

class CBTexture;

class CBTextureBuilderBase
{
private:
	// --- Add private member --- //
public:
    CBTextureBuilderBase(){}
	virtual ~CBTextureBuilderBase(){}
	// --- Add public member --- //
#ifdef __CBANDROID__
    virtual GLuint reloadText(const string& text, float size) = 0;
    virtual GLuint reloadTexture(const string& filename) = 0;
#endif
    virtual CBTexture* buildTexture(const string& filename) = 0;
    virtual CBTexture* buildStringTexture(const string& text,const float size) = 0;
};

class CBTextureBuilderSmulator : public CBTextureBuilderBase
{
private:
	// --- Add private member --- //
public:
    CBTextureBuilderSmulator() {}
	virtual ~CBTextureBuilderSmulator() {}
	// --- Add public member --- //
#ifdef __CBANDROID__
    GLuint reloadText(const string& text, float size) { return 0; }
    GLuint reloadTexture(const string& filename) { return 0; }
#endif
    CBTexture* buildTexture(const string& filename) { return NULL; }
    CBTexture* buildStringTexture(const string& text,const float size) { return NULL; }
};

#endif
