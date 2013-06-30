#include "Error.h"

double MaxAbsoluteError(Vector t, Vector e)
{
	double err = ABS(t.val[0] - e.val[0]);
	for(unsigned int i = 1; i < t.dim; ++i)
		err = MAX(err, ABS(t.val[i] - e.val[i]));
	return err;
}

double MaxRelativeError(Vector t, Vector e)
{
	double err = ABS((t.val[0] - e.val[0])/t.val[0]);
	for(unsigned int i = 1; i < t.dim; ++i)
		err = MAX(err, ABS((t.val[i] - e.val[i])/t.val[i]));
	return err;	
}
