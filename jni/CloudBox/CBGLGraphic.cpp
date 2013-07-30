//
//  CBGLGraphic.cpp
//  ___PROJECTNAME___
//
//  Created by Cloud on 13/5/4.
//
//

#include "CBEnvironment.h"
#include "CBGLGraphic.h"
#include "CBLayout.h"
#include "CBTexture.h"
#include "CBView.h"
#include <math.h>

CBGLGraphic::CBGLGraphic()
{
    m_screenWidth = CBEnvironment::getScreenWidth();
    m_screenHeight = CBEnvironment::getScreenHeight();
}
CBGLGraphic::~CBGLGraphic()
{
}

// initial graphic
void CBGLGraphic::initial2D()
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

void CBGLGraphic::beforeRender()
{
	glLoadIdentity();
	
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// for draw line function
void CBGLGraphic::drawLine(CBPoint& ptStart,CBPoint& ptEnd)
{
    CBColor color;
    color.r = 1;
    color.g = 0;
    color.b = 0;
    color.a = 1;
    drawLine(ptStart, ptEnd, color, 1);
}

void CBGLGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size)
{
    CBColor color;
    color.r = 1;
    color.g = 0;
    color.b = 0;
    color.a = 1;
    drawLine(ptStart, ptEnd, color, size);
}
void CBGLGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color)
{
    drawLine(ptStart, ptEnd, color, 1);
}
void CBGLGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor& color, float size)
{
    ptStart.x = SLayout.scaleX(ptStart.x);
    ptStart.y = SLayout.scaleY(ptStart.y);
    ptEnd.x = SLayout.scaleX(ptEnd.x);
    ptEnd.y = SLayout.scaleY(ptEnd.y);
    float y1 = m_screenHeight - ptStart.y;
    float y2 = m_screenHeight - ptEnd.y;
    GLfloat line[] =
    {
        ptStart.x, y1, //point A
        ptEnd.x, y2, //point B
    };
    
    drawLines(line, color, size);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void CBGLGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4)
{
    CBColor color;
    color.r = 1;
    color.g = 0;
    color.b = 0;
    color.a = 1;
    drawLineLoop(p1, p2, p3, p4, color, 1);
}
void CBGLGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, float size)
{
    CBColor color;
    color.r = 1;
    color.g = 0;
    color.b = 0;
    color.a = 1;
    drawLineLoop(p1, p2, p3, p4, color, size);
}
void CBGLGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color)
{
    drawLineLoop(p1, p2, p3, p4, color, 1);
}
void CBGLGraphic::drawLineLoop(CBPoint& p1, CBPoint& p2, CBPoint& p3, CBPoint& p4, CBColor& color, float size)
{
    p1.x = SLayout.scaleX(p1.x);
    p1.y = SLayout.scaleY(p1.y);
    p2.x = SLayout.scaleX(p2.x);
    p2.y = SLayout.scaleY(p2.y);
    p3.x = SLayout.scaleX(p3.x);
    p3.y = SLayout.scaleY(p3.y);
    p4.x = SLayout.scaleX(p4.x);
    p4.y = SLayout.scaleY(p4.y);
    float y1 = m_screenHeight - p1.y;
    float y2 = m_screenHeight - p2.y;
    float y3 = m_screenHeight - p3.y;
    float y4 = m_screenHeight - p4.y;
    GLfloat line[] =
    {
        p1.x, y1, 0, //point A
        p2.x, y2, 0, //point B
        p3.x, y3, 0, //point C
        p4.x, y4, 0  //point D
    };
    
    drawLineLoop(line, color, size);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void CBGLGraphic::drawRect(CBRect& rect)
{
    CBColor color;
    color.r = 1;
    color.g = 1;
    color.b = 1;
    color.a = 1;
    rect.x = SLayout.scaleX(rect.x);
    rect.y = SLayout.scaleY(rect.y);
    rect.width = SLayout.scaleWidth(rect.width);
    rect.height = SLayout.scaleHeight(rect.height);
    drawRect(rect, color);
}
void CBGLGraphic::drawRect(CBRect& rect,CBColor& color)
{
    rect.x = SLayout.scaleX(rect.x);
    rect.y = SLayout.scaleY(rect.y);
    rect.width = SLayout.scaleWidth(rect.width);
    rect.height = SLayout.scaleHeight(rect.height);

    rect.y = m_screenHeight - rect.y;
	
	GLfloat vertices[] =
	{
		rect.x,		          rect.y,                0,
		rect.x,          	  rect.y - rect.height,	 0,
		rect.x + rect.width,  rect.y,	             0,
		rect.x + rect.width,  rect.y - rect.height,  0,
	};
	
	drawRect(vertices,color);
}

void CBGLGraphic::drawRect(GLfloat* vtx, CBColor& color)
{
    glDisable(GL_TEXTURE_2D);
    glDisableClientState (GL_TEXTURE_COORD_ARRAY);

    glEnableClientState (GL_VERTEX_ARRAY);
    glEnableClientState (GL_TEXTURE_COORD_ARRAY);
    glPushMatrix();

    glColor4f(color.r, color.g, color.b, 1.0f);

    glVertexPointer(3, GL_FLOAT, 0, vtx);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glPopMatrix();
    glDisableClientState (GL_VERTEX_ARRAY);
    glDisableClientState (GL_TEXTURE_COORD_ARRAY);

    glEnable(GL_TEXTURE_2D);
    glEnableClientState (GL_TEXTURE_COORD_ARRAY);
}

void CBGLGraphic::fillScreen(float r, float g, float b)
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
	drawRect(rt,color);
}


void CBGLGraphic::drawCircle(CBPoint& pt, float radius)
{
    CBColor color(1,1,1);
    drawCircle(pt, radius, color);
}

void CBGLGraphic::drawCircle(CBPoint& pt, float radius, CBColor& color)
{
    drawCircle(pt,radius,color,true);
}

void CBGLGraphic::drawCircle(CBPoint& pt, float radius, CBColor& color, bool filled)
{
    pt.x = SLayout.scaleX(pt.x);
    pt.y = SLayout.scaleY(pt.y);
    float w = SLayout.scaleWidth(radius);
    float h = SLayout.scaleHeight(radius);
    drawEllipse(32, w, h, pt.x, pt.y, 0.0, filled, color);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// for texture
void CBGLGraphic::render(CBView* view, CBTexture* texture)
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
	render(view, texture, coordinates,vertices);
}

void CBGLGraphic::renderString(CBView* view, CBTexture* texture)
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
	
	y = m_screenHeight - y;
	
	GLfloat	vertices[] =
	{
		x,		     (y - height),		      0,
		x + width,	 (y - height),		      0,
		x,		     y,     0,
		x + width,	 y,     0
	};
	
	render(view, texture, coordinates,vertices);
}

void CBGLGraphic::render(CBView* view, CBTexture* texture, GLfloat* coordinates,GLfloat* vertices)
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

void CBGLGraphic::setColor(CBColor color)
{
	glColor4f(color.r,color.g,color.b,color.a);
}

void CBGLGraphic::drawLines(GLfloat* vtx, CBColor& color, float siz)
{
    glDisable(GL_TEXTURE_2D);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
    
    glPushMatrix();
    
    glColor4f(color.r,color.g,color.b,color.a);
    
    glEnableClientState (GL_VERTEX_ARRAY);
    //glEnableClientState (GL_COLOR_ARRAY);
    
    glLineWidth(siz);
    glVertexPointer( 2, GL_FLOAT, 0, vtx );
    //glColorPointer( 4, GL_FLOAT, 0, col );
    glDrawArrays(GL_LINES, 0, 2);
    
    glDisableClientState (GL_VERTEX_ARRAY);
    //glDisableClientState (GL_COLOR_ARRAY);
    glPopMatrix();
    
    glEnable(GL_TEXTURE_2D);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
}

void CBGLGraphic::drawLineLoop(GLfloat* vtx, CBColor& color, float siz)
{
    glDisable(GL_TEXTURE_2D);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
    
    glPushMatrix();
    
    glColor4f(color.r,color.g,color.b,color.a);
    
    glEnableClientState (GL_VERTEX_ARRAY);
    //glEnableClientState (GL_COLOR_ARRAY);
    
    glLineWidth(siz);
    glVertexPointer( 3, GL_FLOAT, 0, vtx );
    //glColorPointer( 4, GL_FLOAT, 0, col );
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    
    glPopMatrix();
    
    glDisableClientState (GL_VERTEX_ARRAY);
    //glDisableClientState (GL_COLOR_ARRAY);
    
    glEnable(GL_TEXTURE_2D);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
}

void CBGLGraphic::drawEllipse(int seg,float w,float h,float px,float py,float pz,bool filled, CBColor& color)
{
    glDisable(GL_TEXTURE_2D);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
    glEnableClientState (GL_VERTEX_ARRAY);
    
    glPushMatrix();
    
    glColor4f(color.r,color.g,color.b,color.a);
    py = m_screenHeight - py;
    glTranslatef(px, py, pz);
    float* vertices = new float[seg*2];
    int count=0;
    for(float i=0; i<360.0f; i+=(360.0f/seg)){
        vertices[count++] = (float)cos( DEGREES_TO_RADIANS(i) )*w;
        vertices[count++] = (float)sin( DEGREES_TO_RADIANS(i) )*h;
    }
    glVertexPointer( 2, GL_FLOAT, 0, vertices);
    glDrawArrays((filled)?GL_TRIANGLE_FAN:GL_LINE_LOOP, 0, seg);
    
    glPopMatrix();
    
    glDisableClientState (GL_VERTEX_ARRAY);
    //glDisableClientState (GL_COLOR_ARRAY);
    
    glEnable(GL_TEXTURE_2D);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
}