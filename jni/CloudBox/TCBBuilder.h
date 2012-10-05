/*
 *  TCBBuilder.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _TCBBUILDER_H_
#define _TCBBUILDER_H_

#include <string>
using namespace std;

class CBTexture;

template <class TBULIDER>
class TCBBuilder
{
private:
	// --- Add private member --- //
	static TBULIDER* m_builder;
	TCBBuilder(){}
public:
	~TCBBuilder(){}
	// --- Add public member --- //
	static GLuint ReloadText(const string& text, float size)
	{
		GLuint textureId = m_builder->ReloadText(text,size);
		return textureId;
	}
    static GLuint ReloadTexture(const string& filename)
	{
		GLuint textureId = m_builder->ReloadTexture(filename);
		return textureId;
	}
	static CBTexture* BuildTexture(const string& filename)
	{
		CBTexture* texture = m_builder->BuildTexture(filename);
		return texture;
	}
	static CBTexture* BuildStringTexture(const string& text,const float size)
	{
		CBTexture* texture = m_builder->BuildStringTexture(text,size);
		return texture;
	}
};

template <class TBULIDER> TBULIDER* TCBBuilder<TBULIDER> ::m_builder = new TBULIDER();

#endif