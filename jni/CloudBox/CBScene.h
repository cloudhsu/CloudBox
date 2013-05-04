/*
 *  CBScene.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBSCENE_H_
#define _CBSCENE_H_

#include <string>
#include <vector>
#include "CBView.h"
using namespace std;

class CBTexture;

class CBScene : public CBView
{
protected:
	// --- Add private member --- //
	vector<CBView*> m_items;
	//virtual void OnClick(CBItem* item){}
	bool m_isEndInitial;
	bool m_isEndTextureInit;
	virtual void draw();
    virtual void drawAfter();
	virtual void update();
public:
	// --- Add public member --- //
	CBScene();
	virtual ~CBScene();
	
	virtual void initialize() = 0 ;
    
    void notify();
	void visit();
	
	void addChild(CBView* view);
	void addChild(CBView* view, float x, float y);
	
	void endInitial();

	inline const bool isEndInitial()
	{
		return m_isEndInitial;
	}

	virtual void touchBegan(float x, float y) = 0;
	virtual void touchMoved(float x, float y) = 0;
	virtual void touchEnded(float x, float y) = 0;
	
	virtual void applicationDidEnterBackground();
	virtual void applicationWillEnterForeground();
};

#endif
