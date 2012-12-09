//
//  CBiOSTextureBuilder.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/24.
//  Refactoring by Cloud on 2012/12/09.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#include "CBiOSTextureBuilder.h"
#include "Texture2D.h"
#include "CBTexture.h"
#include "CBImage.h"
#include "CBLabel.h"
#include "CBButton.h"
#include "CBScene.h"
#include "CBSprite.h"
#include "CBString.h"
#include "CBNumber.h"
#include "CBTexturePool.h"

CBiOSTextureBuilder::CBiOSTextureBuilder()
{
	// construct
}

CBiOSTextureBuilder::~CBiOSTextureBuilder()
{
	// Deconstruct
}

CBTexture* CBiOSTextureBuilder::buildTexture(const string& filename)
{
	CBTexture* texture = STexturePool.getTexture(filename);
	if(!texture)
	{
		NSString *name = [[NSString alloc] initWithUTF8String: filename.c_str()];
		UIImage *image = nil;
	
		image = [UIImage imageNamed: name];
	
		Texture2D *tex = [[Texture2D alloc] initWithImage: image];
	
		texture = new CBTexture([tex name], tex.contentSize.width, tex.contentSize.height, tex.pixelsWide, tex.pixelsHigh);
		STexturePool.registerToPool(filename,texture);
		[tex release];
		[name release];
	}
	return texture;
}

CBTexture* CBiOSTextureBuilder::buildStringTexture(const string& text,const float size)
{
	NSString *str = [[NSString alloc] initWithUTF8String: text.c_str()];
	
	stringstream ss;
	ss << text << "_" << size;
	CBTexture* texture = STexturePool.getTexture(ss.str());
	Texture2D *tex;
	if(!texture)
	{
		tex = [[Texture2D alloc] initWithString:str dimensions:CGSizeMake(TEXTURE_SIZE, TEXTURE_SIZE) alignment:UITextAlignmentLeft fontName:@"Arial" fontSize:size];
		texture = new CBTexture([tex name], tex.contentSize.width, tex.contentSize.height, tex.pixelsWide, tex.pixelsHigh);
		[tex release];
		STexturePool.registerToPool(ss.str(),texture);
	}
	[str release];
	return texture;
}