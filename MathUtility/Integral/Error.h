#ifndef ZARATH_ERROR_H
#define ZARATH_ERROR_H

#include "Vector/Vector.h"

static double ABS(double r){return ((r > 0)?(r):(-r));}
static double MAX(double a, double b){return ((a > b)?(a):(b));}
static double MIN(double a, double b){return ((a < b)?(a):(b));}
double MaxAbsoluteError(Vector t, Vector e);
double MaxRelativeError(Vector t, Vector e);
double MaxError(Vector t, Vector e, double abs_err, double rel_err);

#endif
