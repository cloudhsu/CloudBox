#pragma comment (lib, "gdiplus.lib")

#include <windows.h>
#include <gdiplus.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "../CBGameApp.h"

static void Init(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
  glDisable(GL_DITHER);

  SGameApp.initialize();
  SGameApp.initialTimer(((double)GetTickCount())/1000.0);
}

/* ARGSUSED1 */
static void Key(unsigned char key, int x, int y)
{
  switch (key) {
  case 27:
    exit(0);
  }
}

static void Mouse(int button, int state, int x, int y)
{
    static bool isDrag = false;
    if(GLUT_LEFT_BUTTON == button)
    {
        if(GLUT_DOWN == state && isDrag == false)
        {
            isDrag = true;
            SGameApp.touchBegan(x, y);
        }
        else if(GLUT_UP == state)
        {
            isDrag = false;
            SGameApp.touchEnded(x, y);
        }
        if(isDrag)
        {
            SGameApp.touchMoved(x, y);
        }
    }
}

static void Draw(void)
{
    double time = ((double)GetTickCount())/1000.0;
    SGameApp.mainLoop(time);
    glutSwapBuffers();
    glutPostRedisplay();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int iCmdShow)
{
  int argc = 0;
  glutInit(&argc, (char**)"");

  // initial GDI+
  ULONG_PTR m_gdiplusToken;
  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
  Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

  glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
  SGameApp.setScreen(960, 640);
  glutInitWindowSize(960,640);
  glutCreateWindow("CloudBox Demo");
  const GLubyte* ver = glGetString(GL_VERSION);
  printf( "OpenGL Version : %s \n",glGetString(GL_VERSION)); 
  //glutFullScreen();  
  if (!glutExtensionSupported("GL_EXT_abgr")) {
    printf("Couldn't find abgr extension.\n");
    // uninitial GDI+
    Gdiplus::GdiplusShutdown(m_gdiplusToken);
    exit(0);
  }

  Init();
  //glutKeyboardFunc(Key);
  glutMouseFunc(Mouse);
  glutDisplayFunc(Draw);
  
  glutMainLoop();

  // uninitial GDI+
  Gdiplus::GdiplusShutdown(m_gdiplusToken);
  return 0;             /* ANSI C requires main to return int. */
}
