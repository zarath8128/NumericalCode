#ifndef ZARATH_VECTOR_D_H
#define ZARATH_VECTOR_D_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tag_Vector
{
	double *val;
	unsigned int dim;
}Vector;

typedef void (*V_VFunc)(Vector arg, Vector param, Vector *ans);
typedef double (*R_VFunc)(Vector arg, Vector param);

Vector CreateVector(unsigned int dim);
void DeleteVector(Vector *v);
void PrintVector(Vector v);
void VectorAdd(Vector src, Vector *dist);
void VectorSub(Vector src, Vector *dist);
void VectorSca(double sca, Vector *dist);
void VectorMov(Vector src, Vector *dist);

#endif
