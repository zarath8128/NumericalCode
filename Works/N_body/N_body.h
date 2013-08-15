#ifndef ZARATH_N_BODY_N_BODY_H
#define ZARATH_N_BODY_N_BODY_H

#include <cstdint>
#include <cstdlib>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "GLUT_root.h"
#include "N_body_type.h"
#include "N_body_obj.h"

namespace zarath
{
	constexpr int initial_x = 100;
	constexpr int initial_y = 100;
	constexpr uint32_t initial_width = 640;
	constexpr uint32_t initial_height = 480;
	constexpr float initial_clear_color[] = {1.0, 1.0, 1.0, 1.0};
	constexpr float initial_unit_per_pixel = 200;

	void initialize(void);
	void finalize(void);

}

#endif
