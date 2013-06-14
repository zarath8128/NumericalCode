#include <stdlib.h>
#include <stdio.h>
#include "VectorD.hpp"

VectorD CreateVectorD(uint32_t dimension)
{
	VectorD t;
	InitializeVectorD(dimension, &t);
	return t;
}

void DeleteVectorD(VectorD *v)
{
	free(v->unaligned_buf);
	v->buf = v->unaligned_buf = 0;
}

void InitializeVectorD(uint32_t dimension, VectorD *v)
{
	v->dimension = dimension;
	v->unaligned_buf = (double*)malloc(dimension * sizeof(double));
	v->buf = Align(v->unaligned_buf, 16);
}

void FinalizeVectorD(VectorD *v)
{
	free(v->unaligned_buf);
	v->buf = v->unaligned_buf = 0;
}

void PrintVectorD(VectorD *v)
{
	for(uint32_t i = 0; i < v->dimension; ++i)
		printf("%e\n", v->buf[i]);
}

void ADD_VectorD(VectorD *v, VectorD *w, VectorD *ans)
{
/*	for(uint32_t i = 0; i < v->dimension; ++i)
		ans->buf[i] = v->buf[i] + w->buf[i];
*/
	VectorD_ADD(v->buf, w->buf, v->dimension, ans->buf);

}

