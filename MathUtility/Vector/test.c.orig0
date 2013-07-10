#include <stdio.h>
#include <time.h>

#include "VectorD.hpp"
#include "UnrolledVectorD.hpp"

const int s = 30000;

int main(void)
{
	VectorD v = CreateVectorD(s), w = CreateVectorD(s);
	URVectorD u = CreateURVectorD(s), t = CreateURVectorD(s);
	for(uint32_t i = 0; i < s; ++i)
		v.buf[i] = w.buf[i] = u.buf[i] = t.buf[i] =  1./(1 + i);
	clock_t t0 = clock();
	for(uint32_t i = 0; i < s - 1; ++i)
			ADD_VectorD(&v, &w, &v);
			//URVectorD_ADD(u.buf, t.buf, s, u.buf);
	clock_t t1 = clock();
	PrintVectorD(&v);
	//PrintURVectorD(&u);
	printf("time = %f(sec)\n", (t1 - t0)/(double)(CLOCKS_PER_SEC));
	DeleteVectorD(&v);
	DeleteVectorD(&w);
	return 0;
}
