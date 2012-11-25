/*
 *  CBFactory.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/25.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBFACTORY_H_
#define _CBFACTORY_H_

class CBFactory
{
protected:
	CBFactory(){}
public:
	~CBFactory(){}
    
    template <typename T>
	static T* create()
	{
        T* instance = new T();
		return instance;
	}
};

#endif
