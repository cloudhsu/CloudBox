/*
 *  CBBuilderAndroid.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "CBAndroidTextureBuilder.h"
#include "../CBTexture.h"
#include "../CBImage.h"
#include "../CBLabel.h"
#include "../CBButton.h"
#include "../CBScene.h"
#include "../CBSprite.h"
#include "../CBString.h"
#include "../CBNumber.h"
#include "../CBTexturePool.h"
#include "../CBLibrary.h"
#include "CBTextManager.h"
#include "def.h"
#include <GLES/gl.h>
#include <stdio.h>
#include <zip.h>
extern "C" {
#include <png.h>
}

CBAndroidTextureBuilder::CBAndroidTextureBuilder()
{
	// construct
}

CBAndroidTextureBuilder::~CBAndroidTextureBuilder()
{
	// Deconstruct
}

#define TEXTURE_LOAD_ERROR 0

//Taken from http://en.wikibooks.org/wiki/OpenGL_Programming/Intermediate/Textures
/** loadTexture
 *   loads a png file into an opengl texture object, using cstdio , libpng, and opengl.
 *
 *   \param filename : the png file to be loaded
 *   \param width : width of png, to be updated as a side effect of this function
 *   \param height : height of png, to be updated as a side effect of this function
 *
 *   \return GLuint : an opengl texture id.  Will be 0 if there is a major error,
 *           should be validated by the client of this function.
 *
 */
zip_file* file;

void png_zip_read(png_structp png_ptr, png_bytep data, png_size_t length) {
  zip_fread(file, data, length);
}

GLuint CBAndroidTextureBuilder::loadTextureFromPNG (const char* filename, int &width, int &height, int &rpixWidth, int &rpixHeight)
{
    file = zip_fopen(APKArchive, filename, 0);
    if (!file)
    {
        LOGE("Error opening %s from APK", filename);
        return TEXTURE_LOAD_ERROR;
    }

    //header for testing if it is a png
    png_byte header[8];

    //read the header
    zip_fread(file, header, 8);

    //test if png
    int is_png = !png_sig_cmp(header, 0, 8);
    if (!is_png)
    {
        zip_fclose(file);
        LOGE("Not a png file : %s", filename);
        return TEXTURE_LOAD_ERROR;
    }

    //create png struct
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL,
        NULL, NULL);
    if (!png_ptr)
    {
        zip_fclose(file);
        LOGE("Unable to create png struct : %s", filename);
        return (TEXTURE_LOAD_ERROR);
    }

    //create png info struct
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        png_destroy_read_struct(&png_ptr, (png_infopp) NULL, (png_infopp) NULL);
        LOGE("Unable to create png info : %s", filename);
        zip_fclose(file);
        return (TEXTURE_LOAD_ERROR);
    }

    //create png info struct
    png_infop end_info = png_create_info_struct(png_ptr);
    if (!end_info)
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
        LOGE("Unable to create png end info : %s", filename);
        zip_fclose(file);
        return (TEXTURE_LOAD_ERROR);
    }

    //png error stuff, not sure libpng man suggests this.
    if (setjmp(png_jmpbuf(png_ptr)))
    {
        zip_fclose(file);
        LOGE("Error during setjmp : %s", filename);
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        return (TEXTURE_LOAD_ERROR);
    }

    //init png reading
    //png_init_io(png_ptr, fp);
    png_set_read_fn(png_ptr, NULL, png_zip_read);

    //let libpng know you already read the first 8 bytes
    png_set_sig_bytes(png_ptr, 8);

    // read all the info up to the image data
    png_read_info(png_ptr, info_ptr);

    //variables to pass to get info
    int bit_depth = 0;
    int color_type = 0;
    png_uint_32 twidth = 0;
    png_uint_32 theight = 0;

    png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type, NULL, NULL, NULL);

    //update width and height based on png info
    width = twidth;
    height = theight;
    int pixelWidth = width;
    int pixelHeight = height;
    int i;
    bool sizeToFit = false;
    if((pixelWidth != 1) && (pixelWidth & (pixelWidth - 1)))
    {
        i = 1;
        while((sizeToFit ? 2 * i : i) < pixelWidth)
         	i *= 2;
        pixelWidth = i;
    }
    if((pixelHeight != 1) && (pixelHeight & (pixelHeight - 1)))
    {
        i = 1;
        while((sizeToFit ? 2 * i : i) < pixelHeight)
           	i *= 2;
        pixelHeight = i;
    }

    // Update the png info struct.
    png_read_update_info(png_ptr, info_ptr);

    // Row size in bytes.
    int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

    // Allocate the image_data as a big block, to be given to opengl
    //png_byte *image_data = new png_byte[rowbytes * height];
    png_byte *image_data = new png_byte[pixelWidth * pixelHeight*4];
    if (!image_data)
    {
        //clean up memory and close stuff
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        LOGE("Unable to allocate image_data while loading %s ", filename);
        zip_fclose(file);
        return TEXTURE_LOAD_ERROR;
    }

    //row_pointers is for pointing to image_data for reading the png with libpng
    //png_bytep *row_pointers = new png_bytep[height];
    png_bytep *row_pointers = new png_bytep[pixelHeight];
    if (!row_pointers)
    {
        //clean up memory and close stuff
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        delete[] image_data;
        LOGE("Unable to allocate row_pointer while loading %s ", filename);
        zip_fclose(file);
        return TEXTURE_LOAD_ERROR;
    }
    // set the individual row_pointers to point at the correct offsets of image_data
    for (int i = 0; i < height; ++i)
    	row_pointers[height - 1 - i] = image_data + i * pixelWidth*4;
        //row_pointers[height - 1 - i] = image_data + i * rowbytes;

    //read the png into image_data through row_pointers
    png_read_image(png_ptr, row_pointers);

    rpixWidth = pixelWidth;
    rpixHeight = pixelHeight;
    //Now generate the OpenGL texture object

    GLuint texture;
    glGenTextures(1, &texture);
    GLenum errorCode = glGetError();
    if(GL_NO_ERROR != errorCode)
	    LOGE("OpenGL Error in glGenTextures: %d ", errorCode);

    glBindTexture(GL_TEXTURE_2D, texture);
    errorCode = glGetError();
    if(GL_NO_ERROR != errorCode)
  	    LOGE("OpenGL Error in glBindTexture: %d ", errorCode);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

    switch (color_type)
    {
        case PNG_COLOR_TYPE_RGBA:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pixelWidth, pixelHeight, 0,
           	    		GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image_data);
            break;
        case PNG_COLOR_TYPE_RGB:
          	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, pixelWidth, pixelHeight, 0,
           			GL_RGB, GL_UNSIGNED_SHORT_5_6_5, (GLvoid*) image_data);
            break;
        default:
        	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, pixelWidth, pixelHeight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, (GLvoid*) image_data);
            break;
    }
    errorCode = glGetError();
    if(GL_NO_ERROR != errorCode)
    {
    	int maxtexsize;
    	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxtexsize);
  	    LOGE("OpenGL Error in glTexImage2D: %d ", errorCode);
  	    LOGE("width:%d, height:%d",width,height);
  	    LOGE("pixel width:%d, pixel height:%d",pixelWidth,pixelHeight);
  	    LOGE("OpenGL maximum texture size is: %d ", maxtexsize);
    }

    //clean up memory and close stuff
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    delete[] image_data;
    delete[] row_pointers;
    zip_fclose(file);

    return texture;
}

GLuint CBAndroidTextureBuilder::reloadText(const string& text, const float size)
{
	float width = 0;
	float height = 0;
	//GLuint texID = createText(text.c_str(),size,&width,&height);
	GLuint texID = createText(text.c_str(), size, width, height);
	//DebugLog("CBBuilderAndroid::ReloadText:%s,%d",s.c_str(),texID);
	return texID;
}

GLuint CBAndroidTextureBuilder::reloadTexture(const string& filename)
{
	int width = 0;
	int height = 0;
	int pixWidth = 0;
	int pixHeight = 0;
	string name = "assets/" + filename;
	GLuint texID = loadTextureFromPNG(name.c_str(), width, height, pixWidth, pixHeight);
	//DebugLog("CBBuilderAndroid::ReloadTexture:%s,%d",filename.c_str(),texID);
    return texID;
}

CBTexture* CBAndroidTextureBuilder::buildTexture(const string& filename)
{
	string name = "assets/" + filename;
	int width = 0;
	int height = 0;
	int pixWidth = 0;
	int pixHeight = 0;
	CBTexture* texture;
	GLuint texID = loadTextureFromPNG(name.c_str(), width, height, pixWidth, pixHeight);
	texture = new CBTexture(texID, width, height, pixWidth, pixHeight);
	return texture;
}

CBTexture* CBAndroidTextureBuilder::buildStringTexture(const string& text, const float size)
{
	float width = 0;
	float height = 0;
	CBTexture* texture;
	GLuint texID = createText(text.c_str(), size, width, height);
	texture = new CBTexture(texID, width, height, width, height, text, size);
	return texture;
}

GLuint CBAndroidTextureBuilder::createText(const char* text, float size,float& rWidth, float& rHeight)
{
	static CBTextManager manager;
	return manager.createText(text, size, rWidth, rHeight);
}

