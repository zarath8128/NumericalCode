#include "RK3_8Method.h"

void RK3_8Method(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f)
{
	Vector k1 = CreateVector(arg.dim), k2 = CreateVector(arg.dim), k3 = CreateVector(arg.dim), k4 = CreateVector(arg.dim);
	f(arg, param, &k1);
	for(unsigned int i = 0; i < arg.dim; ++i)
		ans->val[i] = arg.val[i] + dt*(k1.val[i]/3);

	f(*ans, param, &k2);
	for(unsigned int i = 0; i < arg.dim; ++i)
		ans->val[i] = arg.val[i] + dt*(-1./3 *k1.val[i] + k2.val[i]);

	f(*ans, param, &k3);
	for(unsigned int i = 0; i < arg.dim; ++i)
		ans->val[i] = arg.val[i] + dt*(k1.val[i] - k2.val[i] + k3.val[i]);

	f(*ans, param, &k4);
	for(unsigned int i = 0; i < arg.dim; ++i)
		ans->val[i] = arg.val[i] + dt/8 *(k1.val[i] + 3*k2.val[i] + 3*k3.val[i] + k4.val[i]);

	DeleteVector(&k1);
	DeleteVector(&k2);
	DeleteVector(&k3);
	DeleteVector(&k4);

}

