#ifndef ZARATH_N_BODY_GLUT_ETC_H
#define ZARATH_N_BODY_GLUT_ETC_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "N_body_obj.h"

namespace zarath
{
	void keyboard(unsigned char key, int x, int y);
	void display(void);
	void reshape(int width, int height);
}

#endif
