//
//  CBLogoScene.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/25.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#ifndef _CBLOGLSCENE_H_
#define _CBLOGLSCENE_H_

#include "CloudBox.h"

class CBLogoScene : public CBScene
{
private:
	// --- Add private member --- //
	CBImage* bg;
protected:
	void draw();
public:
	// --- Add public member --- //
	CBLogoScene();
	~CBLogoScene();
	
	void initialize();
	
	void touchBegan(float x, float y){}
	void touchMoved(float x, float y){}
	void touchEnded(float x, float y){}
	
	void finish(CBView* sender);
};

#endif