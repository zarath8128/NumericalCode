#include "../GLUT_root.h"

namespace zarath
{
	void reshape(int width, int height)
	{
		root.width = width;
		root.height = height;
		glutPostRedisplay();
	}
}
