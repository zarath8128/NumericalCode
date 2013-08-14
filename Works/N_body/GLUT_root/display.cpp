#include "../GLUT_root.h"

namespace zarath
{
	void display(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(0.1, 0.1, 0);
		}
		glEnd();
		glutSwapBuffers();
		return;
	}
}
