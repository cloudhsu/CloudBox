/*
 *  CBTexturePool.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBTEXTUREPOOL_H_
#define _CBTEXTUREPOOL_H_

#include <map>
#include <string>
#include "CBSingleton.h"
using namespace std;

class CBTexture;

class CBTexturePool : public CBSingleton<CBTexturePool>
{
protected:
	map<string,CBTexture* > m_texturePool;
public:
	CBTexturePool();
	~CBTexturePool();
    //////////////////////////////////
	// using for android
#ifdef __CBANDROID__
    void reloadTexture();
#endif
    //////////////////////////////////

	void registerToPool(const string key, CBTexture* tex);
	void unregister(const string key);
	
	CBTexture* getTexture(const string& key);

	void releasePool();
};

#define STexturePool CBTexturePool::instance()

#endif
