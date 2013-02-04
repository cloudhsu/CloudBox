/*
 *  CBFactoryMethod.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/11/25.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBFACTORYMETHOD_H_
#define _CBFACTORYMETHOD_H_

class CBAudioBase;
class CBEffectBase;
class CBUtilityBase;
class CBStoreBase;
class CBDialog;
class CBTextureBuilderBase;
class CBMotionBase;
class CBLedBase;

class CBFactoryMethod
{
private:
public:
    static CBAudioBase* createAudio();
    static CBEffectBase* createEffect();
    static CBUtilityBase* createUtility();
    static CBStoreBase* createStore();
    static CBStoreBase* createSimulateStore();
    static CBDialog* createSystemDialog();
    static CBTextureBuilderBase* createTextureBuilder();
    static CBMotionBase* createMotion();
    static CBLedBase* createLed();
};

#endif
