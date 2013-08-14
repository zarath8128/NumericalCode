#ifndef ZARATH_RUNGE_KUTTA_3_8_METHOD_H
#define ZARATH_RUNGE_KUTTA_3_8_METHOD_H

#include "Vector/Vector.h"

void RK3_8Method(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f);


#endif
