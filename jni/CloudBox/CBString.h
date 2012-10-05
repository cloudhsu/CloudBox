/*
 *  CBString.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/4.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBSTRING_H_
#define _CBSTRING_H_

#define TEXTURE_SIZE	256

#include <string>
#include "CBView.h"
using namespace std;

class CBImage;

class CBString : public CBView
{
private:
	CBImage* m_textImage;
	string m_text;
	int m_fontSize;
	CBString();
protected:
	void draw();
public:
	CBString(const string& text,int fontSize);
	~CBString();
    
    void setColor(float r, float g, float b, float a);
    void setColor(float r, float g, float b);
	
	const string& getText() { return m_text; }
	void setText(const string& text) { m_text = text; }
};

#endif
