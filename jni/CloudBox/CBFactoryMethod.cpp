/*
 *  CBFactoryMethod.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/25.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBFactory.h"
#include "CBFactoryMethod.h"

#include "CBEffectBase.h"
#include "CBAudioBase.h"
#include "CBUtility.h"
#include "CBStoreBase.h"
#include "CBDialog.h"
#include "CBTextureBuilderBase.h"
// for extends
#ifdef __CBIOS__
#include "CBMotionBase.h"
#include "CBLedBase.h"
#elif __CBANDROID__
#include "Extends/CBMotionBase.h"
#include "Extends/CBLedBase.h"
#elif WIN32
#include "Extends/CBMotionBase.h"
#include "Extends/CBLedBase.h"
#endif
// --------------------------------------------------
// include for cross-platform header file.
#ifdef __CBIOS__
#include "CBiOSAudioManager.h"
#include "CBiOSEffectManager.h"
#include "CBiOSUtility.h"
#include "CBiOSStoreWrapper.h"
#include "CBiOSDialog.h"
#include "CBiOSTextureBuilder.h"
#include "CBiOSMotion.h"
#include "CBiOSLed.h"
#elif __CBANDROID__
#include "Android/CBAndroidAudioManager.h"
#include "Android/CBAndroidEffectManager.h"
#include "Android/CBAndroidUtility.h"
#include "Android/CBAndroidStoreWrapper.h"
#include "Android/CBAndroidDialog.h"
#include "Android/CBAndroidTextureBuilder.h"
#include "Android/CBAndroidMotion.h"
#include "Android/CBAndroidLed.h"
#elif WIN32
#include "Win32/CBWin32Dialog.h"
#include "Win32/CBWin32TextureBuilder.h"
#include "Win32/CBWin32Utility.h"
#else

#endif
// --------------------------------------------------

// --------------------------------------------------
// declare name
#ifdef __CBIOS__
// for iOS
typedef CBiOSAudioManager AUDIO_MANAGER;
typedef CBiOSEffectManager EFFECT_MANAGER;
typedef CBiOSUtility UTILITY;
typedef CBiOSStoreWrapper STORE_MANAGER;
typedef CBiOSDialog SYSTEM_DIALOG;
typedef CBiOSTextureBuilder TEXTURE_BUILDER;
typedef CBiOSMotion MOTION_BUILDER;
typedef CBiOSLed LED_BUILDER;
#elif __CBANDROID__
// for Android
typedef CBAndroidAudioManager AUDIO_MANAGER;
typedef CBAndroidEffectManager EFFECT_MANAGER;
typedef CBAndroidUtility UTILITY;
typedef CBAndroidStoreWrapper STORE_MANAGER;
typedef CBAndroidDialog SYSTEM_DIALOG;
typedef CBAndroidTextureBuilder TEXTURE_BUILDER;
typedef CBAndroidMotion MOTION_BUILDER;
typedef CBAndroidLed LED_BUILDER;
#elif WIN32
// for default none behavior 
typedef CBAudioSimulator AUDIO_MANAGER;
typedef CBEffectSimulator EFFECT_MANAGER;
typedef CBWin32Utility UTILITY;
typedef CBStoreSimulator STORE_MANAGER;
typedef CBWin32Dialog SYSTEM_DIALOG;
typedef CBWin32TextureBuilder TEXTURE_BUILDER;
typedef CBMotionSimulator MOTION_BUILDER;
typedef CBLedSimulator LED_BUILDER;
#else
// for default none behavior 
typedef CBAudioSimulator AUDIO_MANAGER;
typedef CBEffectSimulator EFFECT_MANAGER;
typedef CBUtilitySimulator UTILITY;
typedef CBStoreSimulator STORE_MANAGER;
typedef CBDialogSimulator SYSTEM_DIALOG;
typedef CBTextureBuilderSmulator TEXTURE_BUILDER;
typedef CBMotionSimulator MOTION_BUILDER;
typedef CBLedSimulator LED_BUILDER;
#endif
// --------------------------------------------------

CBAudioBase* CBFactoryMethod::createAudio()
{
    return CBFactory::create<AUDIO_MANAGER>();
}
CBEffectBase* CBFactoryMethod::createEffect()
{
    return CBFactory::create<EFFECT_MANAGER>();
}
CBUtilityBase* CBFactoryMethod::createUtility()
{
    return CBFactory::create<UTILITY>();
}
CBStoreBase* CBFactoryMethod::createStore()
{
    return CBFactory::create<STORE_MANAGER>();
}
CBStoreBase* CBFactoryMethod::createSimulateStore()
{
    return CBFactory::create<CBStoreSimulator>();
}
CBDialog* CBFactoryMethod::createSystemDialog()
{
    return CBFactory::create<SYSTEM_DIALOG>();
}
CBTextureBuilderBase* CBFactoryMethod::createTextureBuilder()
{
    return CBFactory::create<TEXTURE_BUILDER>();
}
CBMotionBase* CBFactoryMethod::createMotion()
{
#ifdef CBMotionEnable
    return CBFactory::create<MOTION_BUILDER>();
#else
    return CBFactory::create<CBMotionSimulator>();
#endif
}
CBLedBase* CBFactoryMethod::createLed()
{
#ifdef CBLedEnable
    return CBFactory::create<LED_BUILDER>();
#else
    return CBFactory::create<CBLedSimulator>();
#endif
}
