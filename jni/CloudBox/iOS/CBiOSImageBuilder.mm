//
//  CBiOSImageBuilder.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2012/4/4.
//  Copyright 2012 Orz. All rights reserved.
//

#import "CBiOSImageBuilder.h"
#import "Texture2D.h"

CBiOSImageBuilder::CBiOSImageBuilder()
{
}
CBiOSImageBuilder::~CBiOSImageBuilder()
{
}

CBImageData* CBiOSImageBuilder::loadImageData(const string& fileName)
{
	NSString *name = [[NSString alloc] initWithUTF8String: fileName.c_str()];
	UIImage *image = nil;
	
	image = [UIImage imageNamed: name];
    NSLog(@"name:%s width:%f height:%f\n",fileName.c_str(),image.size.width,image.size.height);
	
	CBImageData *data = [Texture2D loadWithImage: image];
	
	return data;
}
CBImageData* CBiOSImageBuilder::loadTextData(const string& text, float size)
{
	NSString *str = [[NSString alloc] initWithUTF8String: text.c_str()];
	
	CBImageData *data = [Texture2D loadWithString:str dimensions:CGSizeMake(TEXTURE_SIZE, TEXTURE_SIZE) alignment:UITextAlignmentLeft fontName:@"Arial" fontSize:size];
	
	return data;
}

void CBiOSImageBuilder::releaseImage(GLvoid* data)
{
	free(data);
}
