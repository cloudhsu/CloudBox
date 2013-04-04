/*
 *  CBTwitterExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBTwitterExhibitor.h"
#include "CBLibrary.h"
#include "CBExhibitorFactory.h"

CBTwitterExhibitor::CBTwitterExhibitor()
{
    m_implExhibitor = CBExhibitorFactory::createTwitterExhibitor();
}

CBTwitterExhibitor::~CBTwitterExhibitor()
{

}