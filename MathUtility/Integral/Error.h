#ifndef ZARATH_ERROR_H
#define ZARATH_ERROR_H

#include "Vector/Vector.h"

extern double ABS(double r){return (r > 0)?(r):(-r);}
extern double MAX(double a, double b){return (a > b)?(a):(b);}
extern double MIN(double a, double b){return (a < b)?(a):(b);}
double MaxAbsoluteError(Vector t, Vector e);
double MaxRelativeError(Vector t, Vector e);

#endif
