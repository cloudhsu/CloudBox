/*
 *  CBWin32TextureBuilder.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2013/02/25.
 *  Copyright 2013 Orz. All rights reserved.
 *
 */
#pragma comment (lib, "gdiplus.lib")

#include <windows.h>
#include <gdiplus.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include "CBWin32TextureBuilder.h"
#include "../CBTexture.h"
#include "../CBTexturePool.h"
#include "../CBLibrary.h"
using namespace std;

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

GLuint CBWin32TextureBuilder::loadTextureFromPNG(const char* filename, int &width, int &height, int &rpixWidth, int &rpixHeight)
{
    // GDI+ requires unicode strings.
    // This trick only works for strings containing English ASCII text.
    std::string asciiFilename(filename);
    std::wstring unicodeFilename(asciiFilename.length(), L' ');
    std::copy(asciiFilename.begin(), asciiFilename.end(), unicodeFilename.begin());

    Gdiplus::Bitmap* pBitmap = Gdiplus::Bitmap::FromFile(unicodeFilename.c_str(), FALSE);

    if (pBitmap == NULL )
    {
        return false;
    }

    // GDI+ orients bitmap images top-bottom.
    // OpenGL expects bitmap images to be oriented bottom-top by default.
    pBitmap->RotateFlip(Gdiplus::RotateNoneFlipY);

    // GDI+ pads each scanline of the loaded bitmap image to 4-byte memory
    // boundaries. Fortunately OpenGL also aligns bitmap images to 4-byte
    // memory boundaries by default.
    width = pBitmap->GetWidth();
    height = pBitmap->GetHeight();
    int pitch = ((width * 32 + 31) & ~31) >> 3;

    std::vector<unsigned char> pixels(pitch * height);
    Gdiplus::BitmapData data;
    Gdiplus::Rect rect(0, 0, width, height);

    // Convert to 32-bit BGRA pixel format and fetch the pixel data.

    if (pBitmap->LockBits(&rect, Gdiplus::ImageLockModeRead, PixelFormat32bppARGB, &data) != Gdiplus::Ok)
        return false;

    if (data.Stride == pitch)
    {
        memcpy(&pixels[0], data.Scan0, pitch * height);
    }
    else
    {
        unsigned char *pSrcPixels = static_cast<unsigned char *>(data.Scan0);

        for (int i = 0; i < height; ++i)
            memcpy(&pixels[i * pitch], &pSrcPixels[i * data.Stride], pitch);
    }

    pBitmap->UnlockBits(&data);

    // Create an OpenGL texture object to store the loaded bitmap image.

    GLuint g_texture;

    glGenTextures(1, &g_texture);
    glBindTexture(GL_TEXTURE_2D, g_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, &pixels[0]);

    rpixWidth = width;
    rpixHeight = height;
    delete pBitmap;
    return g_texture;
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
	texture = new CBTexture(texID, width, height, 256, 256, text, size);
	return texture;
}

GLuint CBWin32TextureBuilder::createText(const char* text, float size,float& rWidth, float& rHeight)
{
    std::string asciiText(text);
    std::wstring unicodeText(asciiText.length(), L' ');
    std::copy(asciiText.begin(), asciiText.end(), unicodeText.begin());

    Gdiplus::Bitmap* pBitmap = new Gdiplus::Bitmap(256,256);
    Gdiplus::Graphics *g = Gdiplus::Graphics::FromImage(pBitmap);
    Gdiplus::Font myFont(L"Arial", 16);
    Gdiplus::PointF origin(0.0f, 0.0f);
    Gdiplus::SolidBrush blackBrush(Gdiplus::Color(255, 255, 0, 0));
    g->DrawString(unicodeText.c_str(), unicodeText.size(), &myFont, origin, &blackBrush);

    Gdiplus::RectF layoutRect(0, 0, 256, 256);
    Gdiplus::RectF textRect(0, 0, 256, 256);
    g->MeasureString(unicodeText.c_str(), unicodeText.size(), &myFont,layoutRect,&textRect);
    UINT width = pBitmap->GetWidth();
    UINT height = pBitmap->GetHeight();
    int pitch = ((width * 32 + 31) & ~31) >> 3;

    std::vector<unsigned char> pixels(pitch * height);
    Gdiplus::BitmapData data;
    Gdiplus::Rect rect(0, 0, width, height);

    // Convert to 32-bit BGRA pixel format and fetch the pixel data.

    if (pBitmap->LockBits(&rect, Gdiplus::ImageLockModeRead, PixelFormat32bppARGB, &data) != Gdiplus::Ok)
        return false;

    if (data.Stride == pitch)
    {
        memcpy(&pixels[0], data.Scan0, pitch * height);
    }
    else
    {
        unsigned char *pSrcPixels = static_cast<unsigned char *>(data.Scan0);

        for (int i = 0; i < height; ++i)
            memcpy(&pixels[i * pitch], &pSrcPixels[i * data.Stride], pitch);
    }

    pBitmap->UnlockBits(&data);

    // Create an OpenGL texture object to store the loaded bitmap image.

    GLuint g_texture;

    glGenTextures(1, &g_texture);
    glBindTexture(GL_TEXTURE_2D, g_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, &pixels[0]);

    rWidth = textRect.Width;
    rHeight = textRect.Height;
    delete pBitmap;

    return g_texture;
}

