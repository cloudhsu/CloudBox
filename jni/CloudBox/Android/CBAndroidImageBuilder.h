//
//  CBAndroidImageBuilder.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2012/4/4.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBANDROIDIMAGEBUILDER_H_
#define _CBANDROIDIMAGEBUILDER_H_

#include "../CBImageBuilder.h"
extern "C" {
#include <png.h>
}
#include <stdio.h>
#include "def.h"
#include <zip.h>

class CBAndroidImageBuilder : public CBImageBuilder
{
public:
	CBAndroidImageBuilder();
	~CBAndroidImageBuilder();
	
	CBImageData* loadImageData(const string& fileName);
	CBImageData* loadTextData(const string& text, float size);
	
	void releaseImage(GLvoid* data);
};

#endif
