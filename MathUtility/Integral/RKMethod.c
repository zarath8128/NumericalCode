#include "RKMethod.h"

void RKMethod(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f)
{
	Vector k1 = CreateVector(arg.dim), k2 = CreateVector(arg.dim), k3 = CreateVector(arg.dim), k4 = CreateVector(arg.dim);
	f(arg, param, &k1);

	VectorMov(k1, ans);
	VectorSca(0.5*dt, ans);
	VectorAdd(arg, ans);
	f(*ans, param, &k2);

	VectorMov(k2, ans);
	VectorSca(0.5*dt, ans);
	VectorAdd(arg, ans);
	f(*ans, param, &k3);

	VectorMov(k3, ans);
	VectorSca(dt, ans);
	VectorAdd(arg, ans);
	f(*ans, param, &k4);

	VectorSca(2, &k2);
	VectorSca(2, &k3);

	VectorMov(k1, ans);
	VectorAdd(k2, ans);
	VectorAdd(k3, ans);
	VectorAdd(k4, ans);
	VectorSca(1./6*dt, ans);
	VectorAdd(arg, ans);
	DeleteVector(&k1);
	DeleteVector(&k2);
	DeleteVector(&k3);
	DeleteVector(&k4);

}

void RKMethodIterate(Vector arg, Vector param, Vector *ans, double dt, unsigned int count, V_VFunc f)
{
	Vector k1 = CreateVector(arg.dim), k2 = CreateVector(arg.dim), k3 = CreateVector(arg.dim), k4 = CreateVector(arg.dim);
	for(unsigned int i = 0; i < count; ++i)
	{
		f(arg, param, &k1);

		VectorMov(k1, ans);
		VectorSca(0.5*dt, ans);
		VectorAdd(arg, ans);
		f(*ans, param, &k2);

		VectorMov(k2, ans);
		VectorSca(0.5*dt, ans);
		VectorAdd(arg, ans);
		f(*ans, param, &k3);

		VectorMov(k3, ans);
		VectorSca(dt, ans);
		VectorAdd(arg, ans);
		f(*ans, param, &k4);

		VectorSca(2, &k2);
		VectorSca(2, &k3);

		VectorMov(k1, ans);
		VectorAdd(k2, ans);
		VectorAdd(k3, ans);
		VectorAdd(k4, ans);
		VectorSca(1./6*dt, ans);
		VectorAdd(arg, ans);
		VectorMov(*ans, &arg);
	}
	DeleteVector(&k1);
	DeleteVector(&k2);
	DeleteVector(&k3);
	DeleteVector(&k4);

}
