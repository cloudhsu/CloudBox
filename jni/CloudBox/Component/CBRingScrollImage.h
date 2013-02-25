/*
 *  CBRingScrollImage.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/4/18.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBRINGSCROLLIMAGE_
#define _CBRINGSCROLLIMAGE_

#ifdef __CBBLACKBERRY__
#include "../CBView.h"
#elif WIN32
#include "../CBView.h"
#else
#include "CBView.h"
#endif

class CBImage;

enum ScrollCoordinate
{
	ScrollX = 0,
	ScrollY = 1
};

class CBRingScrollImage : public CBView
{
private:
	CBView* m_image1;
	CBView* m_image2;
	ScrollCoordinate m_scrollCoordinate;
    
//    float m_offset;
	float m_distance;
	float m_duration;
    bool m_isPause;
    
	void initial();
	void resetImage2();
protected:
	void draw();
public:
	CBRingScrollImage();
	CBRingScrollImage(const string& imageName, ScrollCoordinate scrollCoordinate, float distance, float duration);
    CBRingScrollImage(CBView* view, ScrollCoordinate scrollCoordinate, float distance, float duration);
    CBRingScrollImage(ScrollCoordinate scrollCoordinate, float distance, float duration);
	~CBRingScrollImage();
	
    void scrollImage(CBView* target);
	void startScroll();
    void initialScroll();
    
    void pause() { m_isPause = true; }
    void resume() { m_isPause = false; }
	
	void setImage(const string& imageName);
    void setImage(CBView* view);
    void setImage(CBView* view1, CBView* view2);
	
	inline const ScrollCoordinate getScrollCoordinate() { return m_scrollCoordinate; }
	inline void setScrollCoordinate(ScrollCoordinate scrollCoordinate) { m_scrollCoordinate = scrollCoordinate; }
	
//    const float getOffset();
//    void setOffset(float offset);
    
	inline const float getDistance() { return m_distance; }
	inline void setDistance(float distance) { m_distance = distance; }
	
	inline const float getDuration() { return m_duration; }
	inline void setDuration(float duration) { m_duration = duration; }
};

#endif
