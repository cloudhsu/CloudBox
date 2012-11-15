/*
 *  CBComposeAction.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/8/9.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBCOMPOSEACTION_H_
#define _CBCOMPOSEACTION_H_

#include "CBAction.h"

class CBProperty;

class CBComposeAction : public CBAction {
protected:
	vector<CBProperty> m_properties;
	void onAction(CBView* view);
    void checkFinish();
    
	CBComposeAction();
public:
	CBComposeAction(double duration,int repeatTime);
    ~CBComposeAction();
    
    void commit(CBView* target);
	
	void addProperty(CBProperty& property);
};

#endif