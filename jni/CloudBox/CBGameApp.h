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
#include <GL/glut.h>
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
    void initialTimer(double oldTime);
    void initialStore();
    void initialArchiment();
	void runWithScene(CBScene* scene);
	void destory();
	void mainLoop(double time);
	void retinaDisplay();
    void iOSWideScreen();
#ifdef __CBANDROID__
    void reloadTexture();
#endif
	void touchBegan(float x, float y);
	void touchMoved(float x, float y);
	void touchEnded(float x, float y);
	void onSersorChanged(float x, float y, float z);
	void onAndroidAlertEvent(int dialogType, int dialogResult, int buttonIndex);
	
	void applicationDidEnterBackground();
	void applicationWillEnterForeground();
	
	//inline float getSpanTime() { return m_SpanTime; }
    
    // transaction event
    void requestFail(string& msg);
    void requestFinished();
    
    void completeTransaction(string& buyProductTag);
    void failedTransaction(string& msg, int errorCode);
    void restoreTransaction(string& buyProductTag);
    void purchasingTransaction(string& buyProductTag);
    void restoreCompletedTransactionsFinished();
    void restoreCompletedTransactionsFailed(string& msg, int errorCode);
};

#define SGameApp CBGameApp::instance()

#endif
