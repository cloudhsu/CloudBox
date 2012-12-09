/*
 *  CBEnvironment.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/24.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _CBENVIRONMENT_H_
#define _CBENVIRONMENT_H_

#include "CBDevice.h"

// 1 to skip CBLogoScene, default scene is HelloScene
//#define SKIP_LOGO true
#define SKIP_LOGO false

class CBEnvironment
{
private:
	static float m_screenWidth;
	static float m_screenHeight;
	static bool m_isRetina;
public:
	static inline const float getScreenWidth() { return m_screenWidth; }
	static inline const float getScreenHeight() { return m_screenHeight; }
    static inline const bool isRetina() { return m_isRetina; }
    static inline const CBOrientation getOrientation() { return DEFAULT_ORIENTATION;}
	
	static inline void setScreenWidth(float screenWidth) { m_screenWidth = screenWidth; }
	static inline void setScreenHeight(float screenHeight) { m_screenHeight = screenHeight; }
    static inline void setRetina(bool isRetina) { m_isRetina = isRetina; }
    static inline void retinaDisplay() { m_isRetina = true; }
};

#endif
