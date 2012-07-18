/*
 *  CBLabel.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/6.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBLABEL_H_
#define _CBLABEL_H_

#ifdef __CBIOS__
#define LABEL_NAME "label.png"
#else
#define LABEL_NAME "system/label.png"
#endif

#include <string>
#include "CBView.h"
using namespace std;

class CBString;
class CBImage;

class CBLabel : public CBView
{
protected:
	CBImage* m_background;
	float m_textOffsetX;
	float m_textOffsetY;
	int m_fontSize;
	CBString* m_text;
	void offsetText();
	void loadBackground(const string& fileName);
protected:
	virtual void draw();
public:
	CBLabel();
	CBLabel(const string& text, int fontSize);
	CBLabel(const string& fileName,const string& text, int fontSize);
	virtual ~CBLabel();
	
	void setBackground(const string& fileName);
	void setText(const string& text);
	void setText(const string& text, int fontSize);
	void setTextColor(float r, float g, float b, float a);
};

#endif