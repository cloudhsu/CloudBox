/*
 *  CBAudioBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/6/22.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBAUDIOBASE_H_
#define _CBAUDIOBASE_H_

#define LOOP_ALWAYS -1
#include <string>
using namespace std;

enum AudioState
{
    AudioNotReady,
    AudioReady,
    AudioPlaying,
    AudioPause
};

class CBAudioBase
{
protected:
    AudioState m_state;
public:
    CBAudioBase():m_state(AudioNotReady) {}
    virtual ~CBAudioBase() {}
    virtual void loadMusic(const string fileName) = 0;
	virtual void releaseMusic() = 0;
	virtual void playMusic() = 0;
	virtual void stopMusic() = 0;
    virtual void pauseMusic() = 0;
	virtual void resumeMusic() = 0;
    
    virtual float getVolume() = 0;
    virtual void setVolume(float volume) = 0;
};

class CBAudioSimulator : public CBAudioBase
{
public:
    CBAudioSimulator() {}
    ~CBAudioSimulator() {}
    void loadMusic(const string fileName) {}
    void releaseMusic() {}
    void playMusic() {}
    void stopMusic() {}
    void pauseMusic() {}
    void resumeMusic() {}
    
    float getVolume() { return 0.0f; }
    void setVolume(float volume) { }
};

#endif
