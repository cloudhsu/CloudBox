#pragma comment (lib, "gdiplus.lib")

#include <windows.h>
#include <gdiplus.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "../CBGameApp.h"

GLenum doubleBuffer;
GLubyte ubImage[65536];

static void Init(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
  glDisable(GL_DITHER);

  SGameApp.initialize();
}

/* ARGSUSED1 */
static void Key(unsigned char key, int x, int y)
{
  switch (key) {
  case 27:
    exit(0);
  }
}

static void Mouse(int x, int y, int x1, int y1)
{
}

static void Draw(void)
{
    /*glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glRasterPos3f(0.2, -0.8, -1.5);*/
    /*glDrawPixels(128, 128, GL_RGBA, GL_UNSIGNED_BYTE, ubImage);*/

    //TexFunc();
    double time = 0;
    SGameApp.mainLoop(time);

    glutSwapBuffers();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int iCmdShow)
{
  int argc = 0;
  glutInit(&argc, (char**)"");

  ULONG_PTR m_gdiplusToken;
  Gdiplus::GdiplusStartupInput gdiplusStartupInput;
  Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

  glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
  SGameApp.setScreen(960, 640);
  glutInitWindowSize(960,640);
  glutCreateWindow("CloudBox Demo");
  //glutFullScreen();  
  if (!glutExtensionSupported("GL_EXT_abgr")) {
    printf("Couldn't find abgr extension.\n");
    Gdiplus::GdiplusShutdown(m_gdiplusToken);
    exit(0);
  }

  Init();
  //glutKeyboardFunc(Key);
  glutMouseFunc(Mouse);
  glutDisplayFunc(Draw);
  glutMainLoop();
  Gdiplus::GdiplusShutdown(m_gdiplusToken);
  return 0;             /* ANSI C requires main to return int. */
}
