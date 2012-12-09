/*
 *  CBTextureBuilder.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Refactor by Cloud on 2012/12/09
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBTEXTUREBUILDER_H_
#define _CBTEXTUREBUILDER_H_

#include "CBSingleton.h"
#include <string>
using namespace std;

class CBTexture;
class CBTextureBuilderBase;

class CBTextureBuilder : public CBSingleton<CBTextureBuilder>
{
private:
	// --- Add private member --- //
    CBTextureBuilderBase *m_builder;
public:
    CBTextureBuilder();
	~CBTextureBuilder();
	// --- Add public member --- //
#ifdef __CBANDROID__
    GLuint reloadText(const string& text, float size);
    GLuint reloadTexture(const string& filename);
#endif
    CBTexture* buildTexture(const string& filename);
    CBTexture* buildStringTexture(const string& text,const float size);
};

#define STextureBuilder CBTextureBuilder::instance()

#endif