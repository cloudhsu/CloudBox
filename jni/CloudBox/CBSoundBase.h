/*
 *  CBSoundBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/6/22.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBSOUNDBASE_H_
#define _CBSOUNDBASE_H_

#include <string>
using namespace std;

class CBSoundBase
{
protected:
    float m_volume;
public:
    CBSoundBase(){}
    ~CBSoundBase(){}
    
    virtual void initial() = 0;
    virtual void loadSound(const string fileName) = 0;
	//virtual void releaseSound(const string fileName) = 0;
    virtual void releaseAllSound() = 0;
	virtual void playSound(const string fileName) = 0;
	virtual void stopSound(const string fileName) = 0;
    
    virtual float getVolume() = 0;
    virtual void setVolume(float volume) = 0;
};

class CBNoneSound : public CBSoundBase
{
public:
    CBNoneSound() {}
    ~CBNoneSound() {}
    void initial() {}
    void loadSound(const string fileName) {}
    //void releaseSound(const string fileName) {}
    void releaseAllSound() {}
    void playSound(const string fileName) {}
    void stopSound(const string fileName) {}
    
    float getVolume() { return 0.0f; }
    void setVolume(float volume) { }
};

#endif
