/*
 *  CBEffectBase.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/6/22.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBEFFECTBASE_H_
#define _CBEFFECTBASE_H_

#include <string>
using namespace std;

class CBEffectBase
{
protected:
    float m_volume;
public:
    CBEffectBase(){}
    virtual ~CBEffectBase(){}
    
    virtual void initialEffect() = 0;
    virtual void loadEffect(const string fileName) = 0;
	//virtual void releaseEffect(const string fileName) = 0;
    virtual void releaseAllEffect() = 0;
	virtual void playEffect(const string fileName) = 0;
	virtual void stopEffect(const string fileName) = 0;
    
    virtual float getVolume() = 0;
    virtual void setVolume(float volume) = 0;
};

class CBEffectSimulator : public CBEffectBase
{
public:
    CBEffectSimulator() {}
    ~CBEffectSimulator() {}
    void initialEffect() {}
    void loadEffect(const string fileName) {}
    //void releaseEffect(const string fileName) {}
    void releaseAllEffect() {}
    void playEffect(const string fileName) {}
    void stopEffect(const string fileName) {}
    
    float getVolume() { return 0.0f; }
    void setVolume(float volume) { }
};

#endif
