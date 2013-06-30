#include <stdio.h>
#include "Vector.h"

const int s = 10000;

int main()
{
	Vector v = CreateVector(s);
	for(int i = 0; i < s; ++i)
		v.val[i] = 1.;
	VectorSca(10, &v);
	printf("%f\n", VectorNorm(v));
	DeleteVector(&v);
	return 0;
}
