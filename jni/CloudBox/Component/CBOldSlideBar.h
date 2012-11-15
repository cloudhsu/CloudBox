/*
 *  CBOldSlideBar.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/8.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBOLDSLIDEBAR_
#define _CBOLDSLIDEBAR_

#include "CBView.h"
#include "CBAction.h"
#include "CBSlideBar.h"

//enum SlideBarStatus
//{
//	SlideBarHide = 0,
//	SlideBarShow = 1
//};
//
//enum SlideBarDirection
//{
//    SlideBarUp = 0,
//    SlideBarDown = 1,
//    SlideBarLeft = 2,
//    SlideBarRight = 3,
//};

class CBOldSlideBar : public CBView
{
protected:
	SlideBarStatus m_status;
    SlideBarDirection m_direction;
	
	CBDelegate<void(CBView*,int)>* m_buttonClick;
	
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
	
	virtual void onButtonClick(CBView* target, int index);
	
protected:
	void draw();
public:
	CBOldSlideBar();
	~CBOldSlideBar();
	
	inline void setShowButtonAction(CBAction* action) { m_optionButtonShowClick = action; }
	inline void setHideButtonAction(CBAction* action) { m_optionButtonHideClick = action; }
	inline void setShowBarAction(CBAction* action)
	{
		m_optionBarShow = action;
		m_optionBarShow->addTriggerEvent(this,&CBOldSlideBar::onBarAnimationScrolling);
	}
	inline void setHideBarAction(CBAction* action)
	{
		m_optionBarHide = action;
		m_optionBarHide->addTriggerEvent(this,&CBOldSlideBar::onBarAnimationScrolling);
		m_optionBarHide->addFinishEvent(this,&CBOldSlideBar::onBarAnimationFinish);
	}
	
	template <typename T>
	void addButtonClickEvent(T* instance, void (T::*Func)(CBView*, int))
	{
		//m_delegate = new TDelegate<T>(target,Func);
		m_buttonClick = new CBDelegate<void(CBView*, int)>();
		m_buttonClick->initDelegate<T>(instance,Func);
	}
	
	void onClick(float x,float y);
	
	void setOptionButton(const string& imageName);
	void setOptionBar(const string& imageName);
	
	void addButton(const string& imageName);
	void addSwitchButton(const string& onImageName,const string& offImageName);
};

#endif