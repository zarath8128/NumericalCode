#include <cmath>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
<<<<<<< HEAD
#include <cstdlib>
#include "BufferManager.hpp"
#include <ctime>



// n which is natural number that satisfies L = dx * n must exit
constexpr int L = 4;
constexpr double dx = 0.1;
constexpr int N = L/dx;

double *buf[2];
BufferManager<double*, 2> *buffer;


void display(void);
void update(int value);
void finalize();
void initialize();

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(300, 200);
	glutInitWindowSize(1200, 900);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

	glutCreateWindow("test window");
	glutDisplayFunc(display);
	glutTimerFunc(100, update, 0);
	glClearColor(1, 1, 1, 0);
	glClearDepth(1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1200/600, 1200/600, -900/600., 900/600., -1, 10);

	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

	atexit(finalize);

	initialize();
	glutMainLoop();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	


	glutSwapBuffers();
}

void update(int value)
{
	static int i = 0;
	time_t tm;
	if((i % 100) == 0)
	{
		time(&tm);
		std::cout << clock() << std::endl;
	}
	i++;
	glutTimerFunc(100, update, 2);
}


void finalize()
{
	delete [] buf[0];
	delete [] buf[1];
	std::cout << "exited" << std::endl;
}

void initialize()
{
	buf[0] = new double[N];
	buf[1] = new double[N];
	buffer = new BufferManager<double*, 2>(buf);	
}


=======



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
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422
