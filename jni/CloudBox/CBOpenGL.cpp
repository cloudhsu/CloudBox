/*
 *  CBOpenGL.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2012/3/28.
 *  Copyright 2012 Orz. All rights reserved.
 *
 */

#include "CBOpenGL.h"
#include "CBEnvironment.h"
#include "CBTexture.h"
#include "CBView.h"
#include "CBLayout.h"

CBOpenGL::CBOpenGL()
{
	// construct
	resetTextureCounter();
}

CBOpenGL::~CBOpenGL()
{
	// Deconstruct
}

GLuint CBOpenGL::genTexture()
{
	GLuint textureID = m_textureCounter++;
	return textureID;
}
void CBOpenGL::resetTextureCounter()
{
	m_textureCounter = 0;
}

GLuint CBOpenGL::generateTexture(GLvoid* data, int width, int height)
{
	GLuint textureId = 0;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
				 GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	return textureId;
}

void CBOpenGL::beforeRender()
{
	glLoadIdentity();
	
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

void CBOpenGL::initialize2D()
{
	m_screenWidth = CBEnvironment::getScreenWidth();
	m_screenHeight = CBEnvironment::getScreenHeight();
	
	SLayout.initial(m_screenWidth,m_screenHeight);
	
	glViewport(0, 0, m_screenWidth, m_screenHeight);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#if !WIN32
	glOrthof(0, (float)m_screenWidth, 0, (float)m_screenHeight, -100, 100);
	//glOrthof(0, (float)m_screenWidth, 0, (float)m_screenHeight, 0, 100);
#else
    glOrtho(0, (float)m_screenWidth, 0, (float)m_screenHeight, -100, 100);
#endif
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glEnable(GL_TEXTURE_2D);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void CBOpenGL::render(CBView* view, CBTexture* texture)
{
	GLfloat _maxS = texture->getMaxS();
	GLfloat _maxT = texture->getMaxT();
	
	GLfloat	coordinates[] = 
	{
		0,				_maxT,
		_maxS,			_maxT,
		0,				0,
		_maxS,			0
	};
	GLfloat x = view->getX();
	GLfloat y = view->getY();
    GLfloat z = view->getZ();
	GLfloat	width = view->getWidth();
	GLfloat height = view->getHeight();
	
	y = m_screenHeight - y;
	
#ifdef __CBIOS__
	GLfloat	vertices[] = 
	{
		x,		     (y - height),		      z,
		x + width,	 (y - height),		      z,
		x,		     y,     z,
		x + width,	 y,     z
	};
#else
	GLfloat	vertices[] =
	{
		x,		     y,		      z,
		x + width,	 y,		      z,
		x,		     (y - height),     z,
		x + width,	 (y - height),     z
	};
#endif
	//texture->bind();
	render(view, texture, coordinates,vertices);
}

void CBOpenGL::renderString(CBView* view, CBTexture* texture)
{
	GLfloat _maxS = texture->getMaxS();
	GLfloat _maxT = texture->getMaxT();
	
	GLfloat	coordinates[] = 
	{
		0,				_maxT,
		_maxS,			_maxT,
		0,				0,
		_maxS,			0
	};
	GLfloat x = view->getX();
	GLfloat y = view->getY();
	GLfloat	width = view->getWidth();
	GLfloat height = view->getHeight();
	
	//DebugLog("x:%f,y:%f\n",x,y);
	
	y = m_screenHeight - y;
	
	GLfloat	vertices[] =
	{
		x,		     (y - height),		      0,
		x + width,	 (y - height),		      0,
		x,		     y,     0,
		x + width,	 y,     0
	};
	//texture->bind();
	//setColor(view->getColor());
	render(view, texture, coordinates,vertices);
}

void CBOpenGL::setColor(CBColor color)
{
	//glEnableClientState(GL_COLOR_BUFFER_BIT);
	glColor4f(color.r,color.g,color.b,color.a);
	//glDisableClientState (GL_COLOR_BUFFER_BIT);
    //Draw stuff..
    //glDisable(GL_BLEND);
}

void CBOpenGL::render(CBView* view, CBTexture* texture, GLfloat* coordinates,GLfloat* vertices)
{
	texture->bind();
	
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	
	glPushMatrix();
    
    setColor(view->getColor());
	// rotate
	glTranslatef(view->getCenterX(), (m_screenHeight - view->getCenterY()), 0);
    if(RotateAxisX == view->getRotateAxis())
        glRotatef(-view->getAngle(), 1.0f, 0.0f, 0.0f);
    else if(RotateAxisY == view->getRotateAxis())
        glRotatef(-view->getAngle(), 0.0f, 1.0f, 0.0f);
    else if(RotateAxisZ == view->getRotateAxis())
        glRotatef(-view->getAngle(), 0.0f, 0.0f, 1.0f);
	glTranslatef(-view->getCenterX(), -(m_screenHeight - view->getCenterY()), 0);
	// draw
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, coordinates);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	
	glDisableClientState (GL_VERTEX_ARRAY);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
}

void CBOpenGL::fillScreen(float r, float g, float b)
{
	CBRect rt;
	rt.x = 0;
	rt.y = 0;
	rt.width = m_screenWidth;
	rt.height = m_screenHeight;
	CBColor color;
	color.r = r;
	color.g = g;
	color.b = b;
	fillRect(rt,color);
}

void CBOpenGL::fillRect(CBRect rt, CBColor color)
{
	rt.y = m_screenHeight - rt.y;
	
	GLfloat vertices[] =
	{
		rt.x,		      rt.y,              0,
		rt.x,          	  rt.y - rt.height,	 0,
		rt.x + rt.width,  rt.y,	             0,
		rt.x + rt.width,  rt.y - rt.height,  0,
	};
	
	glDisable(GL_TEXTURE_2D);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
	
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	glPushMatrix();
	
	glColor4f(color.r, color.g, color.b, 1.0f);
	
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glPopMatrix();
	glDisableClientState (GL_VERTEX_ARRAY);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
	
	glEnable(GL_TEXTURE_2D);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
}
