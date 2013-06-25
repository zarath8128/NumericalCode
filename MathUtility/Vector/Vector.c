#include "Vector.h"

Vector CreateVector(unsigned int dim)
{
	Vector t;
	t.val = (double*)malloc(sizeof(double) * dim);
	t.dim = dim;
	return t;
}

void DeleteVector(Vector *v)
{
	v->dim = 0;
	free(v->val);
}

void PrintVector(Vector v)
{
	for(unsigned int i = 0; i < v.dim; ++i)
		printf("%10d:%22.14e\n", i, v.val[i]);
}

void VectorAdd(Vector src, Vector *dist)
{
	for(unsigned int i = 0; i < src.dim; ++i)
		dist->val[i] += src.val[i];
}

void VectorSub(Vector src, Vector *dist)
{
	for(unsigned int i = 0; i < src.dim; ++i)
		dist->val[i] -= src.val[i];
}

void VectorSca(double sca, Vector *dist)
{
	for(unsigned int i = 0; i < dist->dim; ++i)
		dist->val[i] *= sca;
}

void VectorMov(Vector src, Vector *dist)
{
	for(unsigned int i = 0; i < dist->dim; ++i)
		dist->val[i] = src.val[i];
}

double VectorNorm(Vector v)
{
	double t = 0;
	for(unsigned int i = 0; i < v.dim; ++i)
		t += v.val[i] * v.val[i];
	return sqrt(t);
}

double VectorMaxNorm(Vector v)
{
	double t = v.val[0];
	for(unsigned int i = 1; i < v.dim; ++i)
		t = ((((v.val[i]>0)?(v.val[i]):(-v.val[i])) < t)?(t):((v.val[i]>0)?(v.val[i]):(-v.val[i])));
	return t;
}

double VectorDot(Vector v, Vector w)
{
	double t = 0;
	for(unsigned int i = 0; i < v.dim; ++i)
		t += v.val[i] * w.val[i];
	return t;
}

