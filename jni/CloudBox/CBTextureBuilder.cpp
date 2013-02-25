/*
 *  CBTextureBuilder.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Refactor by Cloud on 2012/12/09
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBTextureBuilderBase.h"
#include "CBFactoryMethod.h"
#include "CBTextureBuilder.h"
#include "CBLibrary.h"

CBTextureBuilder::CBTextureBuilder()
{
    m_builder = CBFactoryMethod::createTextureBuilder();
}
CBTextureBuilder::~CBTextureBuilder()
{
    CBDELETE(m_builder);
}

#ifdef __CBANDROID__
// --- Add public member --- //
GLuint CBTextureBuilder::reloadText(const string& text, float size)
{
    GLuint textureId = m_builder->reloadText(text,size);
    return textureId;
}
GLuint CBTextureBuilder::reloadTexture(const string& filename)
{
    GLuint textureId = m_builder->reloadTexture(filename);
    return textureId;
}
#endif

CBTexture* CBTextureBuilder::buildTexture(const string& filename)
{
    CBTexture* texture = m_builder->buildTexture(filename);
    return texture;
}
CBTexture* CBTextureBuilder::buildStringTexture(const string& text,const float size)
{
    CBTexture* texture = m_builder->buildStringTexture(text,size);
    return texture;
}