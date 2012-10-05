/*
 *  CBActionManager.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBACTIONMANAGER_H_
#define _CBACTIONMANAGER_H_

#include <vector>
#include "CBSingleton.h"
using namespace std;

class CBAction;

class CBActionManager : public CBSingleton<CBActionManager>
{
private:
	vector<CBAction* > m_actions;
	int m_generateID;
public:
	CBActionManager();
	~CBActionManager();
	
	void registerAction(CBAction* action);
	void removeAction(CBAction* action);
	void clear();
	void update();
};

#define SActionManager CBActionManager::instance()

#endif