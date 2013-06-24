#include "RKFMethod.h"

void RKFMethod(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f)
{
	Vector k1 = CreateVector(arg.dim), k2 = CreateVector(arg.dim),  k3 = CreateVector(arg.dim), k4 = CreateVector(arg.dim), k5 = CreateVector(arg.dim), k6 = CreateVector(arg.dim);

	



	DeleteVector(&k1);
	DeleteVector(&k2);
	DeleteVector(&k3);
	DeleteVector(&k4);
	DeleteVector(&k5);
	DeleteVector(&k6);
}

