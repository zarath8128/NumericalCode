#include <stdio.h>
#include <time.h>

#include "VectorD.hpp"

const int s = 30000;

int main(void)
{
	VectorD v = CreateVectorD(s), w = CreateVectorD(s);
	for(uint32_t i = 0; i < s; ++i)
		v.buf[i] = w.buf[i] = 1./(1 + i);
	clock_t t0 = clock();
	for(uint32_t i = 0; i < 1000; ++i)
		ADD_VectorD(&v, &w, &v);
	clock_t t1 = clock();
	PrintVectorD(&v);
	printf("time = %f(sec)\n", (t1 - t0)/(double)(CLOCKS_PER_SEC));
	DeleteVectorD(&v);
	DeleteVectorD(&w);
	return 0;
}
