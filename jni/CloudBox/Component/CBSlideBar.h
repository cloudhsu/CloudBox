/*
 *  CBSlideBar.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/8/21.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBSLIDEBAR_
#define _CBSLIDEBAR_

#ifdef __CBIOS__
#define OPTION_NAME "button_options.png"
#define OPTION_UP_BG_NAME "options_up_bg.png"
#define OPTION_DOWN_BG_NAME "options_down_bg.png"
#define OPTION_LEFT_BG_NAME "options_left_bg.png"
#define OPTION_RIGHT_BG_NAME "options_right_bg.png"
#define OPTION_BG_NAME "options_bg.png"
#define OPTION_VERTICAL_BG_NAME "options_vertical_bg.png"
#define OPTION_MUSIC_ON_NAME "button_music_on.png"
#define OPTION_MUSIC_OFF_NAME "button_music_off.png"
#define OPTION_INFO_NAME "button_info.png"
#define OPTION_HELP_NAME "button_help.png"
#define OPTION_CLOSE_NAME "button_close.png"
#elif __CBANDROID__
#define OPTION_NAME "system/button_options.png"
#define OPTION_UP_BG_NAME "system/options_up_bg.png"
#define OPTION_DOWN_BG_NAME "system/options_down_bg.png"
#define OPTION_LEFT_BG_NAME "system/options_left_bg.png"
#define OPTION_RIGHT_BG_NAME "system/options_right_bg.png"
#define OPTION_BG_NAME "system/options_bg.png"
#define OPTION_VERTICAL_BG_NAME "system/options_vertical_bg.png"
#define OPTION_MUSIC_ON_NAME "system/button_music_on.png"
#define OPTION_MUSIC_OFF_NAME "system/button_music_off.png"
#define OPTION_CLOSE_NAME "system/button_close.png"
#define OPTION_INFO_NAME "system/button_info.png"
#define OPTION_HELP_NAME "system/button_help.png"
#define OPTION_CLOSE_NAME "system/button_close.png"
#elif __CBBLACKBERRY__
#define OPTION_NAME "system/button_options.png"
#define OPTION_UP_BG_NAME "system/options_up_bg.png"
#define OPTION_DOWN_BG_NAME "system/options_down_bg.png"
#define OPTION_LEFT_BG_NAME "system/options_left_bg.png"
#define OPTION_RIGHT_BG_NAME "system/options_right_bg.png"
#define OPTION_BG_NAME "system/options_bg.png"
#define OPTION_VERTICAL_BG_NAME "system/options_vertical_bg.png"
#define OPTION_MUSIC_ON_NAME "system/button_music_on.png"
#define OPTION_MUSIC_OFF_NAME "system/button_music_off.png"
#define OPTION_CLOSE_NAME "system/button_close.png"
#define OPTION_INFO_NAME "system/button_info.png"
#define OPTION_HELP_NAME "system/button_help.png"
#define OPTION_CLOSE_NAME "system/button_close.png"
#elif WIN32
#define OPTION_NAME "system/button_options.png"
#define OPTION_UP_BG_NAME "system/options_up_bg.png"
#define OPTION_DOWN_BG_NAME "system/options_down_bg.png"
#define OPTION_LEFT_BG_NAME "system/options_left_bg.png"
#define OPTION_RIGHT_BG_NAME "system/options_right_bg.png"
#define OPTION_BG_NAME "system/options_bg.png"
#define OPTION_VERTICAL_BG_NAME "system/options_vertical_bg.png"
#define OPTION_MUSIC_ON_NAME "system/button_music_on.png"
#define OPTION_MUSIC_OFF_NAME "system/button_music_off.png"
#define OPTION_CLOSE_NAME "system/button_close.png"
#define OPTION_INFO_NAME "system/button_info.png"
#define OPTION_HELP_NAME "system/button_help.png"
#define OPTION_CLOSE_NAME "system/button_close.png"
#endif

#ifdef __CBBLACKBERRY__
#include "../CBView.h"
#include "../CBAction.h"
#elif WIN32
#include "../CBView.h"
#include "../CBAction.h"
#else
#include "CBView.h"
#include "CBAction.h"
#endif

enum SlideBarStatus
{
	SlideBarHide = 0,
	SlideBarShow = 1
};

enum SlideBarDirection
{
    SlideBarUp = 0,
    SlideBarDown = 1,
    SlideBarLeft = 2,
    SlideBarRight = 3,
};

class CBSlideBar : public CBView
{
protected:
    float m_duration;
    float m_barWidth;
    float m_barHeight;
    float m_barScrollLength;
	SlideBarStatus m_status;
    SlideBarDirection m_direction;
	
	CBDelegate<void(CBView*,int)>* m_buttonClick;
    CBDelegate<void(CBView*)>* m_optionClick;
	
	CBView* m_optionButton;
	CBView* m_optionBar;
	
	CBDelegate<void(int)>* m_click;
	vector<CBView* > m_options;
	CBAction* m_optionButtonShowClick;
	CBAction* m_optionButtonHideClick;
	CBAction* m_optionBarShow;
	CBAction* m_optionBarHide;
	
	void onOptionClick();
	
	void onBarAnimationScrolling(CBView* target);
	void onBarAnimationFinish(CBView* target);
    void optionAnimating();
    void barShowAnimating();
    void barHideAnimating();
    void buttonShowAnimating();
    void buttonHideAnimating();
    void checkShowAnimationFinished();
    void checkHideAnimationFinished();
	
	virtual void onButtonClick(CBView* target, int index);
	
protected:
	void draw();
public:
	CBSlideBar();
	~CBSlideBar();
		
	template <typename T>
	void addButtonClickEvent(T* instance, void (T::*Func)(CBView*, int))
	{
		m_buttonClick = new CBDelegate<void(CBView*, int)>();
		m_buttonClick->initDelegate<T>(instance,Func);
	}
    
    template <typename T>
	void addOptionClickEvent(T* instance, void (T::*Func)(CBView*))
	{
		m_optionClick = new CBDelegate<void(CBView*)>();
		m_optionClick->initDelegate<T>(instance,Func);
	}
	
	void onClick(float x,float y);
	
    void setOptionBarDirection(const SlideBarDirection direction);
    void setOptionButton(const string& imageName);
	void setOptionBar(const string& imageName);
	void addButton(const string& imageName);
	void addSwitchButton(const string& onImageName,const string& offImageName);
    void addSwitchButton(const string& onImageName,const string& offImageName,bool isOn);
    void setAnimatingDuration(float duration);
    
    void initial();
};

#endif
