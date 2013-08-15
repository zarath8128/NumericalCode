#include "../GLUT_root.h"

#include <cmath>

namespace zarath
{
	void display(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		glColor3f(0, 0, 0);
		glBegin(GL_POINTS);
		{
			glVertex3f(0, 0, 0);
		}
		glEnd();

		glColor3f(1.0, 0, 0);
		glBegin(GL_LINE_LOOP);
		{
			for(int i = 0; i < 255; ++i)
				glVertex3f(cos(2*i*M_PI/255), sin(2*i*M_PI/255), 0);
		}
		glEnd();

		glColor3f(0, 1.0, 0);
		glBegin(GL_LINE_LOOP);
		{
			for(int i = 0; i < 255; ++i)
				glVertex3f(cos(2*i*M_PI/255), 0, sin(2*i*M_PI/255));
		}
		glEnd();

		glColor3f(0, 0, 1.0);
		glBegin(GL_LINE_LOOP);
		{
			for(int i = 0; i < 255; ++i)
				glVertex3f(0, cos(2*i*M_PI/255), sin(2*i*M_PI/255));
		}
		glEnd();
		
		glutSwapBuffers();
		return;
	}
}
