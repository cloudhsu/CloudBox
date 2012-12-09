/*
 *  CBBuilderBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/12/09.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBBUILDERBASE_H_
#define _CBBUILDERBASE_H_

#include <iostream>
#include <string>
using namespace std;

class CBTexture;

class CBBuilderBase
{
private:
	// --- Add private member --- //
public:
    CBBuilderBase(){}
	virtual ~CBBuilderBase(){}
	// --- Add public member --- //
#ifdef __CBANDROID__
    virtual GLuint reloadText(const string& text, float size) = 0;
    virtual GLuint reloadTexture(const string& filename) = 0;
#endif
    virtual CBTexture* buildTexture(const string& filename) = 0;
    virtual CBTexture* buildStringTexture(const string& text,const float size) = 0;
};

class CBNoneBuilder
{
private:
	// --- Add private member --- //
public:
    CBNoneBuilder() {}
	virtual ~CBNoneBuilder() {}
	// --- Add public member --- //
#ifdef __CBANDROID__
    GLuint reloadText(const string& text, float size) { return 0; }
    GLuint reloadTexture(const string& filename) { return 0; }
#endif
    CBTexture* buildTexture(const string& filename) { return NULL; }
    CBTexture* buildStringTexture(const string& text,const float size) { return NULL; }
};

#endif
