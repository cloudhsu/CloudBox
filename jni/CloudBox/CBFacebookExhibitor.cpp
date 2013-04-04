/*
 *  CBFacebookExhibitor.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/03/26.
 *  Copyright 2013 Cloud Hsu. All rights reserved.
 *
 */

#include "CBFacebookExhibitor.h"
#include "CBLibrary.h"
#include "CBExhibitorFactory.h"

CBFacebookExhibitor::CBFacebookExhibitor()
{
    m_implExhibitor = CBExhibitorFactory::createFacebookExhibitor();
}

CBFacebookExhibitor::~CBFacebookExhibitor()
{

}