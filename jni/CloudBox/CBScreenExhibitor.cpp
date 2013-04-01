/*
 *  CBScreenExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */


#include "CBScreenExhibitor.h"
#include "CBLibrary.h"
#include "CBScreenExhibitItem.h"

CBScreenExhibitor::CBScreenExhibitor()
{

}

CBScreenExhibitor::~CBScreenExhibitor()
{
    for (int i = 0; i < m_exhibitItems.size(); i++) {
        CBDELETE(m_exhibitItems[i]);
    }
    m_exhibitItems.clear();
}

void CBScreenExhibitor::post(CBAchievementItem* object)
{
    DebugLog("call CBScreenExhibitor::post()\n");
    if(object->getIsComplete())
    {
        m_exhibitItems.push_back(new CBScreenExhibitItem(object));
        m_exhibitItems[0]->start();
    }
}

void CBScreenExhibitor::draw()
{
    if(m_exhibitItems.size() > 0)
    {
        m_exhibitItems[0]->visit();
    }
}

void CBScreenExhibitor::update()
{
    if(m_exhibitItems.size() > 0)
    {
        m_exhibitItems[0]->notify();
        if(m_exhibitItems[0]->IsEnded())
        {
            DebugLog("Remove a CBScreenExhibitItem.\n");
            CBScreenExhibitItem* item = m_exhibitItems[0];
            m_exhibitItems.erase (m_exhibitItems.begin());
            CBDELETE(item);
            if(m_exhibitItems.size() > 0)
                m_exhibitItems[0]->start();
        }
    }
}