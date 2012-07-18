/*
 *  def.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef DEF_H_
#define DEF_H_

#include <android/log.h>
#include <zip.h>
#include <jni.h>

extern zip* APKArchive;
extern jobject g_textmgr;
extern JNIEnv *g_env;

#define STRINGIFY(x) #x
#define LOG_TAG    "cloudbox-app"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#endif /* DEF_H_ */
