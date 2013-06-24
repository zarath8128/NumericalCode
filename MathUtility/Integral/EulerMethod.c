#include "EulerMethod.h"

void EulerMethod(Vector arg, Vector param, Vector *ans, double dt, V_VFunc f)
{
	f(arg, param, ans);
	VectorSca(dt, ans);
	VectorAdd(arg, ans);
}

void EulerMethodIterate(Vector arg, Vector param, Vector *ans, double dt, unsigned int count, V_VFunc f)
{
	for(unsigned int i = 0; i < count; ++i)
	{
		f(arg, param, ans);
		VectorSca(dt, ans);
		VectorAdd(arg, ans);
		VectorMov(*ans, &arg);
	}
}
