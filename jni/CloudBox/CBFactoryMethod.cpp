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

// --------------------------------------------------
// include for cross-platform header file.
#ifdef __CBIOS__
#include "CBiOSAudioManager.h"
#include "CBiOSEffectManager.h"
#include "CBiOSUtility.h"
#include "CBiOSStoreWrapper.h"
#include "CBiOSDialog.h"
#else
#include "Android/CBAndroidAudioManager.h"
#include "Android/CBAndroidEffectManager.h"
#include "Android/CBAndroidUtility.h"
#include "Android/CBAndroidStoreWrapper.h"
#include "Android/CBAndroidDialog.h"
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
#else
// for Android
typedef CBAndroidAudioManager AUDIO_MANAGER;
typedef CBAndroidEffectManager EFFECT_MANAGER;
typedef CBAndroidUtility UTILITY;
typedef CBAndroidStoreWrapper STORE_MANAGER;
typedef CBAndroidDialog SYSTEM_DIALOG;
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
CBDialog* CBFactoryMethod::createSystemDialog()
{
    return CBFactory::create<SYSTEM_DIALOG>();
}