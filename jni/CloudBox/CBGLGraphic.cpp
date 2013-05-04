//
//  CBGLGraphic.cpp
//  ___PROJECTNAME___
//
//  Created by Cloud on 13/5/4.
//
//

#include "CBGLGraphic.h"

CBGLGraphic::CBGLGraphic()
{
}
CBGLGraphic::~CBGLGraphic()
{
}
// initial graphic
void CBGLGraphic::initial2D()
{
    
}

// for draw function
void CBGLGraphic::drawLine(CBPoint& ptStart,CBPoint& ptEnd)
{
    GLfloat line[] =
    {
        ptStart.x, ptStart.y, //point A
        ptEnd.x, ptEnd.y, //point B
    };
}

void CBGLGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, float size)
{
    
}
void CBGLGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor color, float size)
{
    
}
void CBGLGraphic::drawLine(CBPoint& ptStart, CBPoint& ptEnd, CBColor color)
{
    
}

void CBGLGraphic::drawRect(CBRect& rect)
{
    
}
void CBGLGraphic::drawCircle(CBPoint& pt, float radius)
{
    
}

// for texture
void CBGLGraphic::render()
{
    
}
void CBGLGraphic::renderString()
{
    
}

void CBGLGraphic::drawLines(GLfloat* vtx, GLfloat* col, float siz)
{
    glDisable(GL_TEXTURE_2D);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
    
    glEnableClientState (GL_VERTEX_ARRAY);
    glEnableClientState (GL_COLOR_ARRAY);
    
    glLineWidth(siz);
    glVertexPointer( 3, GL_FLOAT, 0, vtx );
    glColorPointer( 4, GL_FLOAT, 0, col );
    glDrawArrays(GL_LINES, 0, 2);
    
    glDisableClientState (GL_VERTEX_ARRAY);
    glDisableClientState (GL_COLOR_ARRAY);
    
    glEnable(GL_TEXTURE_2D);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
}

void CBGLGraphic::drawLineLoop(GLfloat* vtx, GLfloat* col, float siz)
{
    glDisable(GL_TEXTURE_2D);
	glDisableClientState (GL_TEXTURE_COORD_ARRAY);
    
    glEnableClientState (GL_VERTEX_ARRAY);
    glEnableClientState (GL_COLOR_ARRAY);
    
    glLineWidth(siz);
    glVertexPointer( 3, GL_FLOAT, 0, vtx );
    glColorPointer( 4, GL_FLOAT, 0, col );
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    
    glDisableClientState (GL_VERTEX_ARRAY);
    glDisableClientState (GL_COLOR_ARRAY);
    
    glEnable(GL_TEXTURE_2D);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
}