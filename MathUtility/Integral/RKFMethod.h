#ifndef ZARATH_RUNGE_KUTTA_FEHLBERG_METHOD_H
#define ZARATH_RUNGE_KUTTA_FEHLBERG_METHOD_H

#include "Vector/Vector.h"
#include "Error.h"

double RKFMethod(Vector arg, Vector param, Vector *ans, double *dt, double rel_err, double abs_err, V_VFunc f);
void RKFMethodIterate(Vector arg, Vector param, Vector *ans, double dt, unsigned int count, V_VFunc f);


#endif
