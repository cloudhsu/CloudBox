/*
 *  CBButton.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBBUTTON_H_
#define _CBBUTTON_H_

#include "CBView.h"

#ifdef __CBIOS__
#define BUTTON_NORMAL_NAME "button_normal.png"
#define BUTTON_CLICK_NAME "button_click.png"
#else
#define BUTTON_NORMAL_NAME "system/button_normal.png"
#define BUTTON_CLICK_NAME "system/button_click.png"
#endif

class CBImage;
class CBString;

class CBButton : public CBView
{
private:
	CBImage* m_normal;
	CBImage* m_clicked;
	bool m_isClick;
	float m_textOffsetX;
	float m_textOffsetY;
	CBString* m_text;
	int m_fontSize;
	void offsetText();
protected:
	void draw();
public:
	CBButton();
	CBButton(const string& text, int fontSize);
	virtual ~CBButton();
	void setNormalState(CBImage* image);
	void setClickState(CBImage* image);
	
	void setText(const string& text);
	void setText(const string& text, int fontSize);
	void setTextColor(float r, float g, float b, float a);
	
	void touchBegan(float x, float y);
	void touchMoved(float x, float y);
	void touchEnded(float x, float y);
	
	//void finish(CBCmd* cmd);
};

#endif