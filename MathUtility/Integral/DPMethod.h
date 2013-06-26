#ifndef ZARATH_DORMAND_PRINCE_METHOD_H
#define ZARATH_DORMAND_PRINCE_METHOD_H

#include "Vector/Vector.h"
#include "Error.h"

double DPMethod(Vector arg, Vector param, Vector *ans, double *dt, double rel_err, double abs_err, V_VFunc f);
void DPMethodIterate(Vector arg, Vector param, Vector *ans, double dt, unsigned int count, V_VFunc f);


#endif
