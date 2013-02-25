/*
 *  CBTexturePool.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBTexturePool.h"
#include "CBTexture.h"
#include "CBLibrary.h"
#ifdef __CBANDROID__
#include "CBOpenGL.h"
#endif

CBTexturePool::CBTexturePool()
{
}

CBTexturePool::~CBTexturePool()
{
	m_texturePool.clear();
}

#ifdef __CBANDROID__
//////////////////////////////////
// using for android
void CBTexturePool::reloadTexture()
{
	SOpenGL.resetTextureCounter();
    for (std::map<string,CBTexture* >::iterator it = m_texturePool.begin(); it != m_texturePool.end(); ++it)
    {
        it->second->reload();
    }
}
//////////////////////////////////
#endif

void CBTexturePool::registerToPool(const string key, CBTexture* tex)
{
	tex->poolable(key);
	m_texturePool[key] = tex;
}

void CBTexturePool::unregister(const string key)
{
	if( !(m_texturePool.find(key) == m_texturePool.end()) )
	{
		m_texturePool.erase(key);
	}
}

CBTexture* CBTexturePool::getTexture(const string& key)
{
	return m_texturePool[key];
}

void CBTexturePool::releasePool()
{
	for (std::map<string,CBTexture* >::iterator it = m_texturePool.begin(); it != m_texturePool.end(); ++it)
    {
        CBDELETE(it->second);
    }
	m_texturePool.clear();
#ifdef __CBANDROID__
	SOpenGL.resetTextureCounter();
#endif
}
