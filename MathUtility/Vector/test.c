#include <stdio.h>
#include "Vector.h"

const int s = 1000;

int main()
{
	Vector v = CreateVector(s);
	for(int i = 0; i < s; ++i)
		v.val[i] = 1./(1+i);
	VectorSca(10, &v);
	PrintVector(v);
	DeleteVector(&v);
	return 0;
}
