/*
 *  CBJNI.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include <jni.h>
#include <string>
using namespace std;

class CBJNI
{
protected:
	jobject m_mainObject;
	jclass m_mainClass;
	jobject getInstance(JNIEnv* env, jclass obj_class);
	void initial(const string& className);
public:
	CBJNI();
	virtual ~CBJNI();
};
