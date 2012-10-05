/*
 *  CBDirector.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBDIRECTOR_H_
#define _CBDIRECTOR_H_

#include "CBSingleton.h"

class CBScene;

class CBDirector : public CBSingleton<CBDirector>
{
private:
	// --- Add private member --- //
	CBScene* m_currentScene;
	CBScene* m_nextScene;
	bool m_isSceneChange;
	void changeScene();
	
	void runWithScene(CBScene* scene);
	void initialScene();
public:
	// --- Add public member --- //
	CBDirector();
	~CBDirector();
	
	void runNextScene(CBScene* scene);
	void notify();
	void visit();
	
	void touchBegan(float x, float y);
	void touchMoved(float x, float y);
	void touchEnded(float x, float y);
	
	static void* proxy_function(void* foo_ptr);
	
	void applicationDidEnterBackground();
	void applicationWillEnterForeground();
};

#define SDirector CBDirector::instance()

#endif
