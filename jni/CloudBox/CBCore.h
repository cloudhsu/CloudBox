/*
 *  CBCore.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/1/4.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBCORE_H_
#define _CBCORE_H_

#ifndef NULL
#define NULL			0
#endif

struct CBObject
{
	CBObject(){}
	virtual ~CBObject(){}
};

//template<class T>
//struct CBObject
//{
//	typedef T type;
//	typedef T* pType;
//	
//	CBObject(){}
//	virtual ~CBObject(){}
//};


#endif
