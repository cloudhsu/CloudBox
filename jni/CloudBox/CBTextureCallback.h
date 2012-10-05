/*
 *  CBTextureCallback.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/2/19.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#ifndef _CBTEXTURECBCALLBACK_H_
#define _CBTEXTURECBCALLBACK_H_

#include <iostream>
#include "CBCallBack.h"
#include "CBImageData.h"
using namespace std;

class CBTextureCallback : public CBCallback
{
private:
	CBDelegate<void(CBImageData*)>* m_delegate;
	CBImageData* m_imageData;
public:
	CBTextureCallback();
	~CBTextureCallback();
	
	void onCallback();
	void invoke(CBImageData* imageData);
	
	template <typename T>
	void addCallbackEvent(T* target, void (T::*Func)(CBImageData*))
	{
		m_delegate = new CBDelegate<void(CBImageData*)>();
		m_delegate->initDelegate<T>(target,Func);
	}
};

#endif