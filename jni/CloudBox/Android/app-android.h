/*
 *  app-android.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */
#include <jni.h>

#ifndef _Included_com_clouddevelop_cloudbox_CloudRenderer
#define _Included_com_clouddevelop_cloudbox_CloudRenderer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_clouddevelop_cloudbox_CloudRenderer_nativeInit
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInit
  (JNIEnv *, jclass, jstring, jstring);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInitGL
  (JNIEnv *, jclass);

/*
 * Class:     com_clouddevelop_cloudbox_CloudRenderer_nativeResize
 * Method:    nativeResize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeSetsize
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_clouddevelop_cloudbox_CloudRenderer_nativeRender
 * Method:    nativeRender
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeRender
  (JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeResume
  (JNIEnv *, jclass);

/*
 * Class:     com_clouddevelop_cloudbox_CloudGLSurface_nativePause
 * Method:    nativePause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_nativePause
  (JNIEnv* env, jclass);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeTextInit
(JNIEnv* env, jclass cls, jobject textManager);

// --------------------------------------------------------------------------------------------
// Event for touch
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchBegan
  (JNIEnv *, jclass, jfloat x, jfloat y);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchMoved
  (JNIEnv *, jclass, jfloat x, jfloat y);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchEnded
  (JNIEnv *, jclass, jfloat x, jfloat y);

// --------------------------------------------------------------------------------------------
// Event for motion
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBMotion_onSensorChanged
  (JNIEnv *, jclass, jfloat x, jfloat y, jfloat z);

// --------------------------------------------------------------------------------------------
// for dialog event
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeAlertEvent
  (JNIEnv *, jclass, jint dialogType, jint dialogResult, jint buttonIndex);

// --------------------------------------------------------------------------------------------
// for in-app billing event
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRequestFail
  (JNIEnv *, jclass, jstring msg);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeCompleteTransaction
  (JNIEnv *, jclass, jstring buyProductTag);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeFailedTransaction
  (JNIEnv *, jclass, jstring msg, jint errorCode);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRestoreTransaction
  (JNIEnv *, jclass, jstring buyProductTag);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativePurchasingTransaction
  (JNIEnv *, jclass, jstring buyProductTag);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRestoreCompletedTransactionsFinished
  (JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRestoreCompletedTransactionsFailed
  (JNIEnv *, jclass, jstring msg, jint errorCode);

#ifdef __cplusplus
}
#endif
#endif
