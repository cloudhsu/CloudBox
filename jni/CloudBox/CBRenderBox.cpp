//
//  CBDrawBox.cpp
//  CloudBox Cross-Platform Framework Project
//
//  Created by Cloud on 2011/7/26.
//  Copyright 2011 Cloud Hsu. All rights reserved.
//

#include "CBRenderBox.h"
#include "CBImage.h"
#include "CBString.h"
#include "CBLayout.h"

CBRenderBox::CBRenderBox()
{
	// construct
    m_isRetina = false;
}

CBRenderBox::~CBRenderBox()
{
	// Deconstruct
}

void CBRenderBox::render(GLfloat* coordinates,GLfloat* vertices)
{
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	glPushMatrix();
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, coordinates);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
	glDisableClientState (GL_VERTEX_ARRAY);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
}

void CBRenderBox::renderImage(CBImage* image,GLfloat* coordinates,GLfloat* vertices)
{
	glColor4f(image->getColor().r,image->getColor().g,image->getColor().b,image->getColor().a);
	//image->bindTexture();
	render(coordinates,vertices);
}

//void CBRenderBox::setScreen(GLint screenWidth,GLint screenHeight,CBOrientation orientation)
//{
//	m_orientation = orientation;
//	m_screenWidth = screenWidth;
//	m_screenHeight = screenHeight;
//}

//void CBRenderBox::initialize()
//{
//    SLayout.initScale(m_screenWidth,m_screenHeight);
//	glViewport(0, 0, m_screenWidth, m_screenHeight);
//	
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrthof(0, (float)m_screenWidth, 0, (float)m_screenHeight, 0, 100);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	
////	glEnableClientState (GL_VERTEX_ARRAY);
////	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
//
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//}

void CBRenderBox::beginRender()
{
	glLoadIdentity();
	
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

//void CBRenderBox::fillColor(float r,float g,float b)
//{
//	glColor4f(r, g, b, 1.0f);
//}

void CBRenderBox::render(CBImage* image)
{	
	if(!image->getVisible())
		return;
	//GLfloat _maxS = image->getMaxS();
//	GLfloat _maxT = image->getMaxT();
	GLfloat _maxS = 0;
	GLfloat _maxT = 0;
	
	GLfloat	coordinates[] = 
	{
		0,				_maxT,
		_maxS,			_maxT,
		0,				0,
		_maxS,			0
	};
	GLfloat x = image->getX();
	GLfloat y = image->getY();
	GLfloat	width = image->getWidth();
	GLfloat height = image->getHeight();

	y = m_screenHeight - y;
	
#ifdef __CBIOS__
	GLfloat	vertices[] = 
	{
		x,		     (y - height),		      0,
		x + width,	 (y - height),		      0,
		x,		     y,     0,
		x + width,	 y,     0
	};
#else
	GLfloat	vertices[] =
	{
		x,		     y,		      0,
		x + width,	 y,		      0,
		x,		     (y - height),     0,
		x + width,	 (y - height),     0
	};
#endif
	
	renderImage(image,coordinates,vertices);
	
}

void CBRenderBox::render(CBImage* image, float x, float y)
{
	image->moveTo(x, y);
	render(image);
}

void CBRenderBox::renderString(CBString* image)
{
	if(!image->getVisible())
			return;
//	GLfloat _maxS = image->getMaxS();
//	GLfloat _maxT = image->getMaxT();
	GLfloat _maxS = 0;
	GLfloat _maxT = 0;

	GLfloat	coordinates[] =
	{
		0,				_maxT,
		_maxS,			_maxT,
		0,				0,
		_maxS,			0
	};
	GLfloat x = image->getX();
	GLfloat y = image->getY();
	GLfloat	width = image->getWidth();
	GLfloat height = image->getHeight();
	y = m_screenHeight - y;

	GLfloat	vertices[] =
	{
		x,		     (y - height),		      0,
		x + width,	 (y - height),		      0,
		x,		     y,     0,
		x + width,	 y,     0
	};

	//renderImage(image,coordinates,vertices);
}

void CBRenderBox::renderString(CBString* image, float x, float y)
{
	image->moveTo(x, y);
	renderString(image);
}


void CBRenderBox::fillScreen(float r, float g, float b)
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

void CBRenderBox::fillRect(CBRect rt, CBColor color)
{
	rt.y = m_screenHeight - rt.y;

	//GLfloat vertices[] =
//	{
//		rt.x,		      rt.y,              0,
//		rt.x + rt.width,  rt.y - rt.height,  0,
//		rt.x,          	  rt.y - rt.height,	 0,
//		rt.x + rt.width,  rt.y,	             0
//	};
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
