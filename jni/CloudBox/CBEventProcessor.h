/*
 *  CBEventProcessor.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/10/14.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBEVENTPROCESSOR__
#define __CBEVENTPROCESSOR__

#include "CBSingleton.h"
#include "CBDialogEnum.h"

class CBEventProcessor : public CBSingleton<CBEventProcessor>
{
private:
public:
    CBEventProcessor();
    ~CBEventProcessor();
    
    void onUpdate(double time);
    void onDraw();
    
    void onTouchBegan(float x, float y);
	void onTouchMoved(float x, float y);
	void onTouchEnded(float x, float y);
	void onSersorChanged(float x, float y, float z);
	void onAlertEvent(DialogResult dialogResult, int buttonIndex);
	
	void onApplicationDidEnterBackground();
	void onApplicationWillEnterForeground();
};

#define SEventProcessor CBEventProcessor::instance()


#endif
