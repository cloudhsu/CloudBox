/*
 *  CBCmd.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBCmd.h"

CBCmd::CBCmd()
{
	m_cmd = CmdEmpty;
}
CBCmd::CBCmd(CBCommand cmd)
{
	m_cmd = cmd;
}
CBCmd::~CBCmd()
{
}