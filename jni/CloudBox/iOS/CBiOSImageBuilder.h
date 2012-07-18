//
//  CBiOSImageBuilder.h
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2012/4/4.
//  Copyright 2012 Orz. All rights reserved.
//

#ifndef _CBIOSIMAGEBUILDER_H_
#define _CBIOSIMAGEBUILDER_H_

#include "CBImageBuilder.h"

class CBiOSImageBuilder : public CBImageBuilder
{
public:
	CBiOSImageBuilder();
	~CBiOSImageBuilder();
	
	CBImageData* loadImageData(const string& fileName);
	CBImageData* loadTextData(const string& text, float size);
	
	void releaseImage(GLvoid* data);
};

#endif