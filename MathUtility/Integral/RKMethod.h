#ifndef ZARATH_RUNGE_KUTTA_METHOD_H
#define ZARATH_RUNGE_KUTTA_METHOD_H

#include "Vector/Vector.h"

void RKMethod(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f);
void RKMethodIterate(Vector arg, Vector param, Vector *ans, double dt,unsigned int count, V_VFunc f);


#endif
