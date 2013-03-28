/*
 *  CBScreenExhibitItem.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/27.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBSCREENEXHIBITITEM_H__
#define __CBSCREENEXHIBITITEM_H__

enum ScreenExhibitItemState
{
    ScreenExhibitItemInitial = 0,
    ScreenExhibitItemShowing = 1,
    ScreenExhibitItemOnShow = 2,
    ScreenExhibitItemHiding = 3,
    ScreenExhibitItemEnded = 4,
};

#include "CBView.h"
#include <string>
using namespace std;

class CBImage;
class CBAchievementItem;
class CBAction;

class CBScreenExhibitItem : public CBView
{
private:
    ScreenExhibitItemState m_state;
    CBImage* m_image;
    float m_targetX;
    float m_targetY;
    CBAction* m_showing;
    CBAction* m_show;
    CBAction* m_hiding;

    float startX;
    float startY;
    float moveX;

    void onShowingRunning(CBView* target);
    void onShowingFinish(CBView* target);

    void onShowFinish(CBView* target);

    void onHidingRunning(CBView* target);
    void onHidingFinish(CBView* target);

protected:
    virtual void draw();
    virtual void update();
    CBScreenExhibitItem();
public:
    CBScreenExhibitItem(CBAchievementItem* item);
    ~CBScreenExhibitItem();

    void start();
    bool IsRunning();
    bool IsEnded();

    ScreenExhibitItemState getState() const { return m_state; }
    void setState(ScreenExhibitItemState val) { m_state = val; }
};

#endif