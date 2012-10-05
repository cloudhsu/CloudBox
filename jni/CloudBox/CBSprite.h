/*
 *  CBSprite.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBSPRITE_H_
#define _CBSPRITE_H_

#include "CBView.h"
#include "IClick.h"
#include <vector>
using namespace std;

class CBAnimation;

typedef struct _Animation {
	int animationID;
	CBAnimation* animation;
}Animation;

class CBSprite : public CBView
{
private:
	int m_CurrentAnimation;
	vector<Animation> m_Animations;
protected:
	void draw();
public:
	CBSprite();
	~CBSprite();
	
	void playAnimation(int animationID);
	
	void addAnimation(int animationID, CBAnimation* animation);
};

#endif