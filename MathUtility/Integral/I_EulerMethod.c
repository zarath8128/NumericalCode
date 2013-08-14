#include "I_EulerMethod.h"

void I_EulerMethod(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f)
{
	Vector k1 = CreateVector(arg.dim), k2 = CreateVector(arg.dim);
	f(arg, param, &k1);
	for(unsigned int i = 0; i < arg.dim; ++i)
		ans->val[i] = arg.val[i] + dt*(k1.val[i]/2);

	f(*ans, param, &k2);
	for(unsigned int i = 0; i < arg.dim; ++i)
		ans->val[i] = arg.val[i] + dt*( k2.val[i]);

	DeleteVector(&k1);
	DeleteVector(&k2);
}

