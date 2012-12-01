/*
 *  CBJNI.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBJNI_H_
#define _CBJNI_H_

#include <jni.h>
#include <string>
using namespace std;

class CBJNI
{
protected:
	string m_className;
	jobject m_mainObject;
	jclass m_mainClass;
	jobject getInstance(JNIEnv* env, jclass obj_class);
	void initialJNIClass(const string& className);
public:
	CBJNI();
	virtual ~CBJNI();
};

#endif
