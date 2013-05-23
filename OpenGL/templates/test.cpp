#include <cmath>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>



void display(void);
void special(int key, int x, int y);
int main(int argc, char *argv[])
{

  glutInit(&argc, argv);
  glutInitWindowPosition(300, 200);
  glutInitWindowSize(1200, 900);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

  glutCreateWindow("test window");
  glutDisplayFunc(display);
  glutSpecialFunc(special);
  glClearColor(1, 1, 1, 0);
  glClearDepth(1);

  //std::cout << "\x1b[?6h"  << std::flush;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1200/600, 1200/600, -900/600., 900/600., 1, 10);

  gluLookAt(1, 1, 1, 0, 0, 0, 0, 0, 1);

  glutMainLoop();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  glColor3f(0, 0, 0);
  glPointSize(4);
  glBegin(GL_POINTS);
  {
    //glVertex3f(0, 0, 0);
  }
  glEnd();
  glBegin(GL_LINE_LOOP);
  {
    for(int i = 0; i < 255; ++i)
      glVertex3f(cos(2*M_PI*i/255), sin(2*M_PI*i/255), 0);
  }
  glEnd();
  glBegin(GL_LINE_LOOP);
  {
    for(int i = 0; i < 255; ++i)
      glVertex3f(cos(2*M_PI*i/255), 0, sin(2*M_PI*i/255));
  }
  glEnd();
  glBegin(GL_LINE_LOOP);
  {
    for(int i = 0; i < 255; ++i)
      glVertex3f(0, cos(2*M_PI*i/255), sin(2*M_PI*i/255));
  }
  glEnd();

  glBegin(GL_LINES);
  {
    glVertex3f(-10, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(0, -10, 0);
    glVertex3f(0, 10, 0);
    glVertex3f(0, 0, -10);
    glVertex3f(0, 0, 10);
  }
  glEnd();

  glutSwapBuffers();
}

void special(int key, int x, int y)
{
  switch(key)
  {
  case GLUT_KEY_RIGHT:
  case GLUT_KEY_LEFT:
  case GLUT_KEY_DOWN:
    glutPostRedisplay();
    break;
  }
}
