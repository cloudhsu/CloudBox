/*
 *  app-android.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "app-android.h"
#include <GLES/gl.h>
#include "def.h"
#include <time.h>
#include <string>
#include "../CloudBox.h"
#include "../CBLogoScene.h"

zip* APKArchive;
jobject g_textmgr;
JNIEnv *g_env;
string g_apkPath;

static double _getTime(void)
{
    struct timeval  now;

    gettimeofday(&now, NULL);
    double sec = now.tv_sec;
    double usec = (double)now.tv_usec/1000/1000;
    return (double)(sec + usec);
}

static void printGLString(const char *name, GLenum s)
{
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}

static void checkGlError(const char* op)
{
    for (GLint error = glGetError(); error; error = glGetError()) {
        LOGE("after %s() glError (0x%x)\n", op, error);
    }
}

static void loadAPK (const char* apkPath)
{
    LOGI("Loading APK %s", apkPath);
    APKArchive = zip_open(apkPath, 0, NULL);
    if (APKArchive == NULL)
    {
        LOGE("Error loading APK");
        return;
    }

    //Just for debug, print APK contents
    int numFiles = zip_get_num_files(APKArchive);
    for (int i=0; i<numFiles; i++)
    {
        const char* name = zip_get_name(APKArchive, i, 0);
        if (name == NULL)
        {
            LOGE("Error reading zip file name at index %i : %s", zip_strerror(APKArchive));
            return;
        }
        LOGI("File %i : %s\n", i, name);
    }
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInit
  (JNIEnv * env, jclass cls, jstring apkPath, jstring packageName)
{
	LOGI("nativeInit");
	g_env = env;
	const char* sApkPath;
	const char* sPackageName;
    jboolean isCopy;
    sApkPath = env->GetStringUTFChars(apkPath, &isCopy);
    sPackageName = env->GetStringUTFChars(packageName, &isCopy);
    g_apkPath = string(sPackageName);
    LOGI("apk path:%s",sApkPath);
    LOGI("package name:%s",sPackageName);
    loadAPK(sApkPath);
    SGameApp.initialStore();
    SGameApp.initialArchiment();
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInitGL
  (JNIEnv * env, jclass cls)
{
	LOGI("nativeInitGL");
    SGameApp.initialTimer(_getTime());
    SGameApp.initialize();
    LOGI("End nativeInitGL");
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeSetsize
  (JNIEnv *, jclass, jint w, jint h) {
    //LOGI("nativeSetsize (%i,%i)", w, h);
    if(h == 0)
      h = 1;
    SGameApp.setScreen(w, h);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeResume
  (JNIEnv *, jclass)
{
	//LOGE("Resume");
	SGameApp.reloadTexture();
	SGameApp.applicationWillEnterForeground();
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeRender
  (JNIEnv *, jclass) {
	SGameApp.mainLoop(_getTime());
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_nativePause
  (JNIEnv* env, jclass)
{
	//LOGE("Pause");
	g_env = env;
	SGameApp.applicationDidEnterBackground();
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeTextInit
(JNIEnv* env, jclass cls, jobject textManager)
{
	g_env = env;
	g_textmgr = textManager;
	jclass business_class = env->GetObjectClass(g_textmgr);
	LOGI("initial textmanager success!");
}

// --------------------------------------------------------------------------------------------
// Event for touch
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchBegan
  (JNIEnv *, jclass, jfloat x, jfloat y)
{
	SGameApp.touchBegan(x,y);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchMoved
  (JNIEnv *, jclass, jfloat x, jfloat y)
{
	SGameApp.touchMoved(x,y);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchEnded
  (JNIEnv *, jclass, jfloat x, jfloat y)
{
	SGameApp.touchEnded(x,y);
}
// --------------------------------------------------------------------------------------------
// Event for motion
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBMotion_onSensorChanged
  (JNIEnv *, jclass, jfloat x, jfloat y, jfloat z)
{
	//LOGI("x:%f y:%f z:%f\n", x, y, z);
	SGameApp.onSersorChanged(x, y, z);
}

// --------------------------------------------------------------------------------------------
// for dialog event
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeAlertEvent
  (JNIEnv *, jclass, jint dialogType, jint dialogResult, jint buttonIndex)
{
	//LOGI("Alert EVent[ Type:%d Result:%d Index:%d]\n", dialogType, dialogResult, buttonIndex);
	SGameApp.onAndroidAlertEvent(dialogType, dialogResult, buttonIndex);
}

// --------------------------------------------------------------------------------------------
// for in-app billing event
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRequestFail
  (JNIEnv *, jclass, jstring msg)
{
	const char* myMsg;
	jboolean isCopy;
	myMsg = g_env->GetStringUTFChars(msg, &isCopy);
	string message = string(myMsg);
	SGameApp.requestFail(message);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeCompleteTransaction
  (JNIEnv *, jclass, jstring buyProductTag)
{
	const char* myMsg;
	jboolean isCopy;
	myMsg = g_env->GetStringUTFChars(buyProductTag, &isCopy);
	string productID = string(myMsg);
	SGameApp.completeTransaction(productID);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeFailedTransaction
  (JNIEnv *, jclass, jstring msg, jint errorCode)
{
	const char* myMsg;
	jboolean isCopy;
	myMsg = g_env->GetStringUTFChars(msg, &isCopy);
	string message = string(myMsg);
	SGameApp.restoreCompletedTransactionsFailed(message, errorCode);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRestoreTransaction
  (JNIEnv *, jclass, jstring buyProductTag)
{
	const char* myMsg;
	jboolean isCopy;
	myMsg = g_env->GetStringUTFChars(buyProductTag, &isCopy);
	string productID = string(myMsg);
	SGameApp.restoreTransaction(productID);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativePurchasingTransaction
  (JNIEnv *, jclass, jstring buyProductTag)
{
	const char* myMsg;
	jboolean isCopy;
	myMsg = g_env->GetStringUTFChars(buyProductTag, &isCopy);
	string productID = string(myMsg);
	SGameApp.purchasingTransaction(productID);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRestoreCompletedTransactionsFinished
  (JNIEnv *, jclass)
{
	SGameApp.restoreCompletedTransactionsFinished();
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBUtility_nativeRestoreCompletedTransactionsFailed
  (JNIEnv *, jclass, jstring msg, jint errorCode)
{
	const char* myMsg;
	jboolean isCopy;
	myMsg = g_env->GetStringUTFChars(msg, &isCopy);
	string message = string(myMsg);
	SGameApp.restoreCompletedTransactionsFailed(message, errorCode);
}
