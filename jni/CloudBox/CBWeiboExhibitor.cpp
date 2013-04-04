/*
 *  CBWeiboExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBWeiboExhibitor.h"
#include "CBLibrary.h"
#include "CBExhibitorFactory.h"

CBWeiboExhibitor::CBWeiboExhibitor()
{
    m_implExhibitor = CBExhibitorFactory::createWeiboExhibitor();
}

CBWeiboExhibitor::~CBWeiboExhibitor()
{

}