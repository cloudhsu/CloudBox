/*
 *  utils.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#ifndef UTILS_H_
#define UTILS_H_

//Filename will be looked up in the apk (should start with assets/ or res/
GLuint loadTextureFromPNG (const char* filename, int &width, int &height);

GLuint createText(const char* text, float size,float* rWidth, float* rHeight);

#endif /* UTILS_H_ */
