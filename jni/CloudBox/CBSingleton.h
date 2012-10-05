/*
 *  CBSingleton.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/10/10.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBSINGLETON_H_
#define _CBSINGLETON_H_

template <typename T>
class CBSingleton
{
protected:
	CBSingleton(){}
public:
	~CBSingleton(){}

	static T& instance()
	{
		static T instance;
		return instance;
	}
};

#endif