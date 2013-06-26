#include <stdio.h>
#include <math.h>
#include "Vector/Vector.h"
#include "EulerMethod.h"
#include "RKMethod.h"
#include "RKFMethod.h"
#include "DPMethod.h"

void f(Vector arg, Vector param, Vector *ans)
{
	ans->val[0] = 1;
	ans->val[1] = cos(arg.val[0]);
}

int main()
{
	double e = sin(1);
	Vector v = CreateVector(2), w = CreateVector(2);

	v.val[0] = 0;
	v.val[1] = 0;
	double t = 0, dt = 0.0001, err = 1e-14;
	int c = 0;
	do{
		t += RKFMethod(v, v, &w, &dt, err, err, f);
		VectorMov(w, &v);
		++c;
	}while(t < 1);

	printf("RKF:%10d:%22.14e\n",c , fabs(sin(t) - v.val[1])/sin(t));

	v.val[0] = 0;
	v.val[1] = 0;
	t = 0, dt = 0.0001;
	c = 0;
	do{
		t += DPMethod(v, v, &w, &dt, err, err, f);
		VectorMov(w, &v);
		++c;
	}while(t < 1);

	printf("DP:%10d:%22.14e\n",c , fabs(sin(t) - v.val[1])/sin(t));

	printf("Hallo World!\n");
	return 0;
}
