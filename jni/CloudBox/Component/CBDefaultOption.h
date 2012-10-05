/*
 *  CBDefaultOption.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/15.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBDEFAULTOPTION_H_
#define _CBDEFAULTOPTION_H_

#include "CBOldSlideBar.h"

enum DefaultSlideBar
{
	DefaultSlideBar1 = 1,
    DefaultSlideBar2 = 2
};

class CBDefaultOption : public CBOldSlideBar
{
private:
	void setDefaultBar1();
    void setDefaultBar2();
	CBDefaultOption();
protected:
	void onButtonClick(CBView* target, int index);
public:
	CBDefaultOption(DefaultSlideBar defaultType);
};

#endif