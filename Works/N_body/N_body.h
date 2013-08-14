#ifndef ZARATH_N_BODY_N_BODY_H
#define ZARATH_N_BODY_N_BODY_H

#include <cstdint>
#include <cstdlib>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "GLUT_root.h"

namespace zarath
{
	constexpr uint32_t initial_x = 100;
	constexpr uint32_t initial_y = 100;
	constexpr uint32_t initial_width = 640;
	constexpr uint32_t initial_height = 480;
	constexpr float initial_clear_color[] = {0.0, 0.3, 0.3, 1.0};

	void initialize(void);
	void finalize(void);
}

#endif
