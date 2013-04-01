/*
 *  CBScreenExhibitItem.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/27.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAchievementItem.h"
#include "CBScreenExhibitItem.h"
#include "CBLibrary.h"
#include "CBImage.h"
#include "CBAction.h"
#include "CBEnvironment.h"

CBScreenExhibitItem::CBScreenExhibitItem()
:m_state(ScreenExhibitItemInitial)
{

}

CBScreenExhibitItem::CBScreenExhibitItem( CBAchievementItem* item )
:m_state(ScreenExhibitItemInitial)
{
    m_image = new CBImage(item->getImageName());
    m_image->hide();
    m_showing = new CBAction(0.02, 1000);
    m_showing->addTriggerEvent(this,&CBScreenExhibitItem::onShowingRunning);
    m_showing->addFinishEvent(this,&CBScreenExhibitItem::onShowingFinish);
    m_show = new CBAction(0.8,1);
    m_show->addFinishEvent(this,&CBScreenExhibitItem::onShowFinish);
    m_hiding = new CBAction(0.02, 1000);
    m_hiding->addTriggerEvent(this,&CBScreenExhibitItem::onHidingRunning);
    m_hiding->addFinishEvent(this,&CBScreenExhibitItem::onHidingFinish);
}

CBScreenExhibitItem::~CBScreenExhibitItem()
{
    CBDELETE(m_image);
}

void CBScreenExhibitItem::draw()
{
    if(!IsRunning())
        return;
    m_image->visit();
}

void CBScreenExhibitItem::update()
{
    if(!IsRunning())
        return;
    m_image->notify();
}

void CBScreenExhibitItem::start()
{
    if(m_state == ScreenExhibitItemInitial)
    {
        DebugLog("call CBScreenExhibitItem::start()\n");
        startX = CBEnvironment::getScreenWidth();
        startY = CBEnvironment::getScreenHeight() - m_image->getHeight();
        moveX = -8;
        m_image->moveToAbsolute(startX,startY);
        m_image->show();
        m_state = ScreenExhibitItemShowing;
        m_showing->commit(m_image);
    }
}

bool CBScreenExhibitItem::IsRunning()
{
    return (m_state == ScreenExhibitItemShowing) ||
        (m_state == ScreenExhibitItemHiding) ||
        (m_state == ScreenExhibitItemOnShow);
}

bool CBScreenExhibitItem::IsEnded()
{
    return (m_state == ScreenExhibitItemEnded);
}

void CBScreenExhibitItem::onShowingRunning( CBView* target )
{
    m_image->moveX(moveX);
    if(m_image->getX() <= (CBEnvironment::getScreenWidth() - m_image->getWidth() - 10))
    {
        m_showing->finish();
    }
}

void CBScreenExhibitItem::onShowingFinish( CBView* target )
{
    DebugLog("call CBScreenExhibitItem::onShowingFinish()\n");
    m_state = ScreenExhibitItemOnShow;
    m_show->commit(m_image);
}

void CBScreenExhibitItem::onShowFinish( CBView* target )
{
    DebugLog("call CBScreenExhibitItem::onShowFinish()\n");
    moveX *= -1;
    m_state = ScreenExhibitItemHiding;
    m_hiding->commit(m_image);
}

void CBScreenExhibitItem::onHidingRunning( CBView* target )
{
    m_image->moveX(moveX);
    if(m_image->getX() >= CBEnvironment::getScreenWidth())
    {
        m_hiding->finish();
    }
}

void CBScreenExhibitItem::onHidingFinish( CBView* target )
{
    DebugLog("call CBScreenExhibitItem::onHidingFinish()\n");
    m_state = ScreenExhibitItemEnded;
}