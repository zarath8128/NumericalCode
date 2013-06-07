#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

#include "Kite.hpp"
#include "LookAtManager.hpp"

using namespace zarath;

void display(void);
void special(int key, int x, int y);
LookAtData d = {3, 0, 0, 0, 0, 0, 0, 0, 0};
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

  std::cout << "\x1b[?6h"  << std::flush;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1200/600, 1200/600, -900/600., 900/600., 1, 10);

  gluLookAt(d);

  glutMainLoop();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  gluLookAt(d);

  glColor3f(0, 0, 0);
  glPointSize(4);
  glBegin(GL_POINTS);
  {
    glVertex3f(0, 0, 0);
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
    glVertex3f(0, 0, 0);
    glVertex3f(1.5, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 2, 0);
    glVertex3f(0, 0, -.5);
    glVertex3f(0, 0, 1);
  }
  glEnd();

  glutSwapBuffers();
}

void special(int key, int x, int y)
{
  switch(key)
  {
  case GLUT_KEY_RIGHT:
    if(GLUT_ACTIVE_SHIFT == glutGetModifiers())
      d.pPhi += 0.0625;
    else
      d.dPhi += 0.0625;
    glutPostRedisplay(); 
    break;
  case GLUT_KEY_LEFT:
    if(GLUT_ACTIVE_SHIFT == glutGetModifiers())
      d.pPhi -= 0.0625;
    else
      d.dPhi -= 0.0625;
    glutPostRedisplay();
    break;
  case GLUT_KEY_UP:
    if(GLUT_ACTIVE_SHIFT == glutGetModifiers())
      d.pTheta += 0.0625;
    else
      d.dTheta += 0.0625;
    glutPostRedisplay(); 
    break;
  case GLUT_KEY_DOWN:
    if(GLUT_ACTIVE_SHIFT == glutGetModifiers())
      d.pTheta -= 0.0625;
    else
      d.dTheta -= 0.0625;
    glutPostRedisplay();
    break;
  }
}
