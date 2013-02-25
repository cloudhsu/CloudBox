/*
 *  CBWin32TextureBuilder.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/25.
 *  Copyright 2013 Orz. All rights reserved.
 *
 */

#include "CBWin32TextureBuilder.h"
#include "../CBTexture.h"
#include "../CBTexturePool.h"
#include "../CBLibrary.h"
#include <GL/glut.h>
#include <stdio.h>
#include <png.h>

CBWin32TextureBuilder::CBWin32TextureBuilder()
{
	// construct
}

CBWin32TextureBuilder::~CBWin32TextureBuilder()
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
//zip_file* file;

//void png_zip_read(png_structp png_ptr, png_bytep data, png_size_t length) {
//  zip_fread(file, data, length);
//}

GLuint CBWin32TextureBuilder::loadTextureFromPNG (const char* filename, int &width, int &height, int &rpixWidth, int &rpixHeight)
{
    png_structp png_ptr;
    png_infop info_ptr;
    unsigned int sig_read = 0;
    int color_type, interlace_type;
    FILE *fp = NULL;

    if ((fp = fopen(filename, "rb")) == NULL)
        return false;

    // Check the validity of the file
    unsigned char header[8];
    fread(header, 1, 8, fp);
    if(!png_check_sig(header, 8))
        // Not a valid PNG
        return false;

    /* Create and initialize the png_struct
     * with the desired error handler
     * functions.  If you want to use the
     * default stderr and longjump method,
     * you can supply NULL for the last
     * three parameters.  We also supply the
     * the compiler header file version, so
     * that we know if the application
     * was compiled with a compatible version
     * of the library.  REQUIRED
     */
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
            NULL, NULL, NULL);

    if (png_ptr == NULL) {
        fclose(fp);
        return false;
    }

    /* Allocate/initialize the memory
     * for image information.  REQUIRED. */
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        fclose(fp);
        png_destroy_read_struct(&png_ptr, png_infopp_NULL, png_infopp_NULL);
        return false;
    }

    /* Set error handling if you are
     * using the setjmp/longjmp method
     * (this is the normal method of
     * doing things with libpng).
     * REQUIRED unless you  set up
     * your own error handlers in
     * the png_create_read_struct()
     * earlier.
     */
    if (setjmp(png_jmpbuf(png_ptr))) {
        /* Free all of the memory associated
         * with the png_ptr and info_ptr */
        png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
        fclose(fp);
        /* If we get here, we had a
         * problem reading the file */
        return false;
    }

    /* Set up the output control if
     * you are using standard C streams */
    png_init_io(png_ptr, fp);

    /* If we have already
     * read some of the signature */
    png_set_sig_bytes(png_ptr, 8);

    /*
     * If you have enough memory to read
     * in the entire image at once, and
     * you need to specify only
     * transforms that can be controlled
     * with one of the PNG_TRANSFORM_*
     * bits (this presently excludes
     * dithering, filling, setting
     * background, and doing gamma
     * adjustment), then you can read the
     * entire image (including pixels)
     * into the info structure with this
     * call
     *
     * PNG_TRANSFORM_STRIP_16 |
     * PNG_TRANSFORM_PACKING  forces 8 bit
     * PNG_TRANSFORM_EXPAND forces to
     *  expand a palette into RGB
     */
    int bit_depth = 0;
    png_uint_32 twidth = 0;
    png_uint_32 theight = 0;
    // read all the info up to the image data
    //png_read_info(png_ptr, info_ptr);
    //png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type, NULL, NULL, NULL);
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, png_voidp_NULL);

    

    //update width and height based on png info
    width = info_ptr->width;
    height = info_ptr->height;
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
        png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
        fclose(fp);
        return TEXTURE_LOAD_ERROR;
    }

    //row_pointers is for pointing to image_data for reading the png with libpng
    //png_bytep *row_pointers = new png_bytep[height];
    png_bytep *row_pointers = new png_bytep[pixelHeight];
    if (!row_pointers)
    {
        //clean up memory and close stuff
        png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
        delete[] image_data;
        fclose(fp);
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
	    DebugLog("OpenGL Error in glGenTextures: %d ", errorCode);

    glBindTexture(GL_TEXTURE_2D, texture);
    errorCode = glGetError();
    if(GL_NO_ERROR != errorCode)
  	    DebugLog("OpenGL Error in glBindTexture: %d ", errorCode);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

    switch (color_type)
    {
        case PNG_COLOR_TYPE_RGBA:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pixelWidth, pixelHeight, 0,
           	    		GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image_data);
            break;
        /*case PNG_COLOR_TYPE_RGB:
          	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, pixelWidth, pixelHeight, 0,
           			GL_RGB, GL_UNSIGNED_SHORT_5_6_5, (GLvoid*) image_data);
            break;*/
        default:
        	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, pixelWidth, pixelHeight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, (GLvoid*) image_data);
            break;
    }
    errorCode = glGetError();
    if(GL_NO_ERROR != errorCode)
    {
    	int maxtexsize;
    	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxtexsize);
    }

    //clean up memory and close stuff
    png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
    delete[] image_data;
    delete[] row_pointers;
    fclose(fp);

    return texture;
}


CBTexture* CBWin32TextureBuilder::buildTexture(const string& filename)
{
	string name = "Win32Resource/" + filename;
	int width = 0;
	int height = 0;
	int pixWidth = 0;
	int pixHeight = 0;
	CBTexture* texture;
	GLuint texID = loadTextureFromPNG(name.c_str(), width, height, pixWidth, pixHeight);
	texture = new CBTexture(texID, width, height, pixWidth, pixHeight);
	return texture;
}

CBTexture* CBWin32TextureBuilder::buildStringTexture(const string& text, const float size)
{
	float width = 0;
	float height = 0;
	CBTexture* texture;
	GLuint texID = createText(text.c_str(), size, width, height);
	texture = new CBTexture(texID, width, height, width, height, text, size);
	return texture;
}

GLuint CBWin32TextureBuilder::createText(const char* text, float size,float& rWidth, float& rHeight)
{
	//static CBTextManager manager;
	//return manager.createText(text, size, rWidth, rHeight);
    return 0;
}

