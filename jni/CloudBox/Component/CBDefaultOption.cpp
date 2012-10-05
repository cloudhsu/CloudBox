/*
 *  CBDefaultOption.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/15.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBDefaultOption.h"
#include "CBAction.h"
#include "CBRotateAction.h"
#include "CBPropertyAction.h"
#include "CBSwitch.h"

CBDefaultOption::CBDefaultOption()
: CBOldSlideBar()
{
}

CBDefaultOption::CBDefaultOption(DefaultSlideBar defaultType)
: CBOldSlideBar()
{
    switch (defaultType) {
		case DefaultSlideBar1:
            setDefaultBar1();
            break;
        case DefaultSlideBar2:
            setDefaultBar2();
            break;
        default:
            setDefaultBar1();
			break;
    }
}

void CBDefaultOption::setDefaultBar1()
{
	// template in CloudBox
	setOptionButton(OPTION_NAME);
	setOptionBar(OPTION_BG_NAME);
	m_optionButtonShowClick = 
	new CBPropertyAction(CBProperty(ActionPropertyAngle,0,360,15, PropertyFromCurrent),
						 0.015);
	m_optionButtonHideClick = 
	new CBPropertyAction(CBProperty(ActionPropertyAngle,360,0,-15, PropertyFromCurrent),
						 0.015);
	
	setShowBarAction(
	new CBPropertyAction(
				CBProperty(ActionPropertyWidth,m_optionButton->getWidth(),m_optionBar->getWidth(),10, PropertyFromCurrent),
						 0.02));
	
	setHideBarAction(
	new CBPropertyAction(
				CBProperty(ActionPropertyWidth,m_optionBar->getWidth(),m_optionButton->getWidth(),-10, PropertyFromCurrent),
						 0.02));
	
	m_optionBar->setWidth(m_optionButton->getWidth());
	addSwitchButton(OPTION_MUSIC_ON_NAME,OPTION_MUSIC_OFF_NAME);
	addButton(OPTION_INFO_NAME);
	addButton(OPTION_HELP_NAME);
}

void CBDefaultOption::setDefaultBar2()
{
	// template in CloudBox
	setOptionButton(OPTION_NAME);
	setOptionBar(OPTION_BG_NAME);
	m_optionButtonShowClick =
	new CBPropertyAction(CBProperty(ActionPropertyAngle,0,360,15, PropertyFromCurrent),
						 0.015);
	m_optionButtonHideClick =
	new CBPropertyAction(CBProperty(ActionPropertyAngle,360,0,-15, PropertyFromCurrent),
						 0.015);
	
	setShowBarAction(
                     new CBPropertyAction(
                                          CBProperty(ActionPropertyWidth,m_optionButton->getWidth(),m_optionBar->getWidth(),10, PropertyFromCurrent),
                                          0.02));
	
	setHideBarAction(
                     new CBPropertyAction(
                                          CBProperty(ActionPropertyWidth,m_optionBar->getWidth(),m_optionButton->getWidth(),-10, PropertyFromCurrent),
                                          0.02));
	
	m_optionBar->setWidth(m_optionButton->getWidth());
	addSwitchButton(OPTION_MUSIC_ON_NAME,OPTION_MUSIC_OFF_NAME);
	addButton(OPTION_INFO_NAME);
	addButton(OPTION_HELP_NAME);
}

void CBDefaultOption::onButtonClick(CBView* target, int index)
{
	CBOldSlideBar::onButtonClick(target, index);
	CBSwitch* button = NULL;
	switch (index) {
		case 0:
			// click music setting
			button = static_cast<CBSwitch*> (target);
			DebugLog("Click music [%d] in CBDefaultOption\n",button->getStatus());
			break;
		case 1:
			// show info
			DebugLog("Click info in CBDefaultOption\n");
			break;
		case 2:
			// show help
			DebugLog("Click help in CBDefaultOption\n");
			break;
		default:
			break;
	}

}