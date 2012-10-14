//
//  CBGameApp.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#ifndef _CBGAMEAPP_H_
#define _CBGAMEAPP_H_

#ifdef WIN32
// for win32
#include <GLES/gl.h>
#elif __CBIOS__
// for ios
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#else
// for android
#include <EGL/egl.h>
#include <GLES/gl.h>
#endif

#include "CBSingleton.h"
#include <iostream>
using namespace std;

class CBScene;

class CBGameApp : public CBSingleton<CBGameApp>
{
private:
	// --- Add private member --- //
	bool m_isinitialed;
public:
	// --- Add public member --- //
	CBGameApp();
	~CBGameApp();

	void start();
	void setScreen(GLint screenWidth,GLint screenHeight);
	void initialize();
	void runWithScene(CBScene* scene);
	void destory();
	void mainLoop(double time);
	void initialTimer(double oldTime);
	void retinaDisplay();
    
    void reloadTexture();
	
	void touchBegan(float x, float y);
	void touchMoved(float x, float y);
	void touchEnded(float x, float y);
	void onSersorChanged(float x, float y, float z);
	
	void applicationDidEnterBackground();
	void applicationWillEnterForeground();
	
	//inline float getSpanTime() { return m_SpanTime; }
};

#define SGameApp CBGameApp::instance()

#endif
