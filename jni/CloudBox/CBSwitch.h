/*
 *  CBSwitch.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/9.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBSWITCH_H_
#define _CBSWITCH_H_

#include "CBView.h"

enum SwitchStatus
{
	SwitchOff = 0,
	SwitchOn = 1
};

class CBSwitch : public CBView
{
private:
	CBView* m_on;
	CBView* m_off;
	SwitchStatus m_status;
	CBDelegate<void(CBView*,SwitchStatus)>* m_switch;
	void onSwitch();
protected:
	void draw();
	CBSwitch();
public:
	CBSwitch(CBView* onView,CBView* offView);
	CBSwitch(const string& onImageName,const string& offImageName);
	virtual ~CBSwitch();
	void setOnView(CBView* view);
	void setOffView(CBView* view);
	
	void setOnView(const string& imageName);
	void setOffView(const string& imageName);
	
	void switchStatus();
	void turnOn();
	void turnOff();
	
	void onClick(float x,float y);
	
	inline SwitchStatus getStatus() { return m_status; }
    void setStatus(SwitchStatus status) { m_status = status; }
	
	template <typename T>
	void addSwitchEvent(T* instance, void (T::*Func)(CBView*,SwitchStatus))
	{
		m_switch = new CBDelegate<void(CBView*,SwitchStatus)>();
		m_switch->initDelegate<T>(instance,Func);
	}
};

#endif