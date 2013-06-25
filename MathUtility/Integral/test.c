#include <stdio.h>
#include <math.h>
#include "Vector/Vector.h"
#include "EulerMethod.h"
#include "RKMethod.h"
#include "RKFMethod.h"

void f(Vector arg, Vector param, Vector *ans)
{
	ans->val[0] = 1;
	ans->val[1] = cos(arg.val[0]);
}

int main()
{
	const int count = 1000001;
	double e = sin(1);
	Vector v = CreateVector(2), w = CreateVector(2);
	for(int i = 1; i < count; i *= 10)
	{
		v.val[0] = 0;
		v.val[1] = 0;
		RKMethodIterate(v, v, &w, 1./i, i, f);
		PrintVector(w);
		printf("%10d:%22.14e\n",i , fabs(e - w.val[1])/e);
	}
	v.val[0] = 0;
	v.val[1] = 0;
	double t = 0, dt = 0.0001, err = 1e-14;
	int c = 0;
	do{
		t += RKFMethod(v, v, &w, &dt, err, err, f);
		VectorMov(w, &v);
		++c;
	}while(t < 1);

	printf("%10d:%22.14e\n",c , fabs(sin(t) - v.val[1])/sin(t));

	printf("Hallo World!\n");
	return 0;
}
