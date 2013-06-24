#include <stdio.h>
#include <math.h>
#include "Vector/Vector.h"
#include "EulerMethod.h"
#include "RKMethod.h"

void f(Vector arg, Vector param, Vector *ans)
{
	VectorMov(arg, ans);
}

int main()
{
	const int count = 1000001;
	double e = exp(1);
	Vector v = CreateVector(1), w = CreateVector(1);
	for(int i = 1; i < count; i *= 10)
	{
		v.val[0] = 1;
		RKMethodIterate(v, v, &w, 1./i, i, f);
		PrintVector(w);
		printf("%10d:%22.14e\n",i , fabs(e - w.val[0])/e);
	}
	printf("Hallo World!\n");
}
