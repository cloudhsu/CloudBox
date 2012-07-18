/*
 *  CBAnimation.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/8/7.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBANIMATION_H_
#define _CBANIMATION_H_

#include "CBView.h"
#include <vector>
using namespace std;

class CBImage;

typedef struct _CBFrame {
	CBImage* image;
	float offsetX;
	float offsetY;
}CBFrame;

class CBAnimation : public CBView
{
private:
	int m_index;
	float m_duration;
	float m_timer;
	vector<CBFrame> m_frames;
protected:
    void update();
	void draw();
public:
	CBAnimation();
	CBAnimation(float duration);
	~CBAnimation();
	
	inline void setDuration(float duration) { m_duration = duration; }
	
	void resetAnimation();
	
	void addFrame(const string& imageName);
	void addFrame(const string& imageName, float offsetX, float offsetY);
	void addFrame(CBImage* image);
	void addFrame(CBImage* image, float offsetX, float offsetY);
};

#endif