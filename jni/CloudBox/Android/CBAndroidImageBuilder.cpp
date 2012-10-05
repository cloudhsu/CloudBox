//
//  CBAndroidImageBuilder.mm
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2012/4/4.
//  Copyright 2012 Orz. All rights reserved.
//

#include "CBAndroidImageBuilder.h"
#include "CBTextManager.h"


#define TEXTURE_LOAD_ERROR 0

CBAndroidImageBuilder::CBAndroidImageBuilder()
{
}
CBAndroidImageBuilder::~CBAndroidImageBuilder()
{
}

zip_file* file2;

void png_zip_read2(png_structp png_ptr, png_bytep data, png_size_t length) {
  zip_fread(file2, data, length);
}

CBImageData* CBAndroidImageBuilder::loadImageData(const string& fileName)
{
	string name = "assets/" + fileName;
	const char* filename = name.c_str();
	file2 = zip_fopen(APKArchive, filename, 0);
	  if (!file2) {
	    LOGE("Error opening %s from APK", filename);
	    return TEXTURE_LOAD_ERROR;
	  }

	  //header for testing if it is a png
	  png_byte header[8];

	  //read the header
	  zip_fread(file2, header, 8);

	  //test if png
	  int is_png = !png_sig_cmp(header, 0, 8);
	  if (!is_png) {
	    zip_fclose(file2);
	    LOGE("Not a png file : %s", filename);
	    return TEXTURE_LOAD_ERROR;
	  }

	  //create png struct
	  png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL,
	      NULL, NULL);
	  if (!png_ptr) {
	    zip_fclose(file2);
	    LOGE("Unable to create png struct : %s", filename);
	    return (TEXTURE_LOAD_ERROR);
	  }

	  //create png info struct
	  png_infop info_ptr = png_create_info_struct(png_ptr);
	  if (!info_ptr) {
	    png_destroy_read_struct(&png_ptr, (png_infopp) NULL, (png_infopp) NULL);
	    LOGE("Unable to create png info : %s", filename);
	    zip_fclose(file2);
	    return (TEXTURE_LOAD_ERROR);
	  }

	  //create png info struct
	  png_infop end_info = png_create_info_struct(png_ptr);
	  if (!end_info) {
	    png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
	    LOGE("Unable to create png end info : %s", filename);
	    zip_fclose(file2);
	    return (TEXTURE_LOAD_ERROR);
	  }

	  //png error stuff, not sure libpng man suggests this.
	  if (setjmp(png_jmpbuf(png_ptr))) {
	    zip_fclose(file2);
	    LOGE("Error during setjmp : %s", filename);
	    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	    return (TEXTURE_LOAD_ERROR);
	  }

	  //init png reading
	  //png_init_io(png_ptr, fp);
	  png_set_read_fn(png_ptr, NULL, png_zip_read2);

	  //let libpng know you already read the first 8 bytes
	  png_set_sig_bytes(png_ptr, 8);

	  // read all the info up to the image data
	  png_read_info(png_ptr, info_ptr);

	  //variables to pass to get info
	  int bit_depth, color_type;
	  png_uint_32 twidth, theight;

	  // get info about png
	  png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type,
	      NULL, NULL, NULL);

	  CBImageData* imageData = new CBImageData();
	  //update width and height based on png info
	  imageData->imageWidth = twidth;
	  imageData->imageHeight = theight;
	  imageData->textureWidth = twidth;
	  imageData->textureHeight = theight;

	  // Update the png info struct.
	  png_read_update_info(png_ptr, info_ptr);

	  // Row size in bytes.
	  int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

	  // Allocate the image_data as a big block, to be given to opengl
	  png_byte *image_data = new png_byte[rowbytes * theight];
	  if (!image_data) {
	    //clean up memory and close stuff
	    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	    LOGE("Unable to allocate image_data while loading %s ", filename);
	    zip_fclose(file2);
	    return TEXTURE_LOAD_ERROR;
	  }

	  //row_pointers is for pointing to image_data for reading the png with libpng
	  png_bytep *row_pointers = new png_bytep[theight];
	  if (!row_pointers) {
	    //clean up memory and close stuff
	    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	    delete[] image_data;
	    LOGE("Unable to allocate row_pointer while loading %s ", filename);
	    zip_fclose(file2);
	    return TEXTURE_LOAD_ERROR;
	  }
	  // set the individual row_pointers to point at the correct offsets of image_data
	  for (int i = 0; i < theight; ++i)
	    row_pointers[theight - 1 - i] = image_data + i * rowbytes;

	  //read the png into image_data through row_pointers
	  png_read_image(png_ptr, row_pointers);

	  //Now generate the OpenGL texture object
	  imageData->textureID;
	  glGenTextures(1, &imageData->textureID);
	  glBindTexture(GL_TEXTURE_2D, imageData->textureID);
	  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageData->imageWidth, imageData->imageHeight, 0, GL_RGBA,
	      GL_UNSIGNED_BYTE, (GLvoid*) image_data);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	  //clean up memory and close stuff
	  png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	  delete[] image_data;
	  delete[] row_pointers;
	  zip_fclose(file2);

	  return imageData;
}
CBImageData* CBAndroidImageBuilder::loadTextData(const string& text, float size)
{
	DebugLog("CBAndroidImageBuilder::loadTextData1");
	static CBTextManager manager;
	DebugLog("CBAndroidImageBuilder::loadTextData2");
	return manager.createText(text.c_str(), size);
}

void CBAndroidImageBuilder::releaseImage(GLvoid* data)
{
	free(data);
}
