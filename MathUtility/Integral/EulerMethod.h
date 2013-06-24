#ifndef ZARATH_EULER_METHOD_H
#define ZARATH_EULER_METHOD_H

#include "Vector/Vector.h"

void EulerMethod(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f);
void EulerMethodIterate(Vector arg, Vector param, Vector *ans, double dt, unsigned int count, V_VFunc f);

#endif
