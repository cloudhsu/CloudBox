/*
 *  CBCmd.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBCMD_H_
#define _CBCMD_H_

#define NO_COMMAND -1

typedef enum _CBCommand {
	CmdEmpty = -1,
	CmdTimerTrigger = 0,
	CmdActionFinish = 1
}CBCommand;

class CBCmd
{
private:
	CBCommand m_cmd;
public:
	CBCmd();
	CBCmd(CBCommand cmd);
	~CBCmd();
	
	inline const CBCommand getCommand() { return m_cmd; }
	inline void setCommand(CBCommand cmd) { m_cmd = cmd; }
};

#endif