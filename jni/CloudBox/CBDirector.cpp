/*
 *  CBDirector.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#include "CBDirector.h"
#include "CBScene.h"
#include "CBTexturePool.h"
#include "CBEventDispatcher.h"
#include "CBActionManager.h"
#include "CBAudioEngine.h"
#include "CBAchievementManager.h"

CBDirector::CBDirector()
{
	// construct
	m_currentScene = NULL;
	m_nextScene = NULL;
	m_isSceneChange = false;
}

CBDirector::~CBDirector()
{
	// Deconstruct
}

void CBDirector::notify()
{
	changeScene();
	if(m_currentScene && m_currentScene->isEndInitial())
		m_currentScene->notify();
    SAchievementManager.updateScreenExhibitor();
}

void CBDirector::visit()
{
	if(m_currentScene)
		m_currentScene->visit();
    SAchievementManager.drawScreenExhibitor();
}

void CBDirector::changeScene()
{
	if(m_isSceneChange)
	{
		//DebugLog("CBDirector::changeScene\n");
		runWithScene(m_nextScene);
	}
}

void* CBDirector::proxy_function(void* foo_ptr)
{
	static_cast<CBDirector*>(foo_ptr)->initialScene();
	return NULL;
}

void CBDirector::runWithScene(CBScene* scene)
{
	//DebugLog("CBDirector::runWithScene\n");
	if(m_currentScene != NULL)
	{
		CBDELETE(m_currentScene);
		STexturePool.releasePool();
		SEventDispatcher.clear();
		SActionManager.clear();
        SAudioEngine.releaseEngine();
	}
	m_currentScene = m_nextScene;
	m_isSceneChange = false;
	m_nextScene = NULL;
//#ifdef __CBIOS__
//	// for ios
//	// no thread
	initialScene();
//#else
	// with thread
//	pthread_t thread;
//    pthread_create(&thread, NULL, &CBDirector::proxy_function, this);
//#endif
}

void CBDirector::initialScene()
{
	m_currentScene->initialize();
	m_currentScene->endInitial();
}

void CBDirector::runNextScene(CBScene* scene)
{
	if(!m_isSceneChange)
	{
		//DebugLog("CBDirector::runNextScene\n");
		m_nextScene = scene;
		m_isSceneChange = true;
	}
}

void CBDirector::touchBegan(float x, float y)
{
	if(m_currentScene)
	{
		m_currentScene->touchBegan(x, y);
		SEventDispatcher.touchBegan(x, y);
	}
}
void CBDirector::touchMoved(float x, float y)
{
	if(m_currentScene)
	{
		m_currentScene->touchMoved(x, y);
		SEventDispatcher.touchMoved(x, y);
	}
}
void CBDirector::touchEnded(float x, float y)
{
	if(m_currentScene)
	{
		m_currentScene->touchEnded(x, y);
        SEventDispatcher.onClick(x, y);
		SEventDispatcher.touchEnded(x, y);
	}
}

void CBDirector::applicationDidEnterBackground()
{
	if(m_currentScene)
		m_currentScene->applicationDidEnterBackground();
}
void CBDirector::applicationWillEnterForeground()
{
	if(m_currentScene)
		m_currentScene->applicationWillEnterForeground();
}
