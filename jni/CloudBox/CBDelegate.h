/*
 *  CBDelegate.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/10/10.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef __CBDELEGATE_H__
#define __CBDELEGATE_H__

template <typename TSignature>
class CBDelegate;

#define PARAMETER_COUNT 0
#include "CBDelegateImpl.h"
#undef PARAMETER_COUNT

#define PARAMETER_COUNT 1
#include "CBDelegateImpl.h"
#undef PARAMETER_COUNT

#define PARAMETER_COUNT 2
#include "CBDelegateImpl.h"
#undef PARAMETER_COUNT

#define PARAMETER_COUNT 3
#include "CBDelegateImpl.h"
#undef PARAMETER_COUNT

#define PARAMETER_COUNT 4
#include "CBDelegateImpl.h"
#undef PARAMETER_COUNT

#define PARAMETER_COUNT 5
#include "CBDelegateImpl.h"
#undef PARAMETER_COUNT

#endif