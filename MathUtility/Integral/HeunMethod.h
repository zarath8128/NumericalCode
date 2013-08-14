#ifndef ZARATH_HEUN_METHOD_H
#define ZARATH_HEUN_METHOD_H

#include "Vector/Vector.h"

void HeunMethod(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f);


#endif
