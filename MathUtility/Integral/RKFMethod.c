#include "RKFMethod.h"

void RKFMethod(Vector arg, Vector param, Vector *ans, double *dt, double rel_err, double abs_err, V_VFunc f)
{
	Vector k1 = CreateVector(ans->dim), k2 = CreateVector(ans->dim),  k3 = CreateVector(ans->dim), k4 = CreateVector(ans->dim), k5 = CreateVector(ans->dim), k6 = CreateVector(ans->dim);
	Vector ans_buf = CreateVector(ans->dim);

	double delta = *dt;

	f(arg, param, &k1);	

	VectorMov(k1, ans);
	VectorSca(0.25*delta, ans);
	VectorAdd(arg, ans);
	f(*ans, param, &k2);

	VectorMov(k1, ans);
	VectorSca(3./32*delta, ans);
	VectorMov(k2, &ans_buf);
	VectorSca(9./32*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorAdd(arg, ans);
	f(*ans, param, &k3);

	VectorMov(k1, ans);
	VectorSca(1932./2197*delta, ans);
	VectorMov(k2, &ans_buf);
	VectorSca(-7200./2197*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k3, &ans_buf);
	VectorSca(7296./2197*delta, &ans_buf);
	f(*ans, param, &k4);

	VectorMov(k1, ans);
	VectorSca(439./216*delta, ans);
	VectorMov(k2, &ans_buf);
	VectorSca(-8*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k3, &ans_buf);
	VectorSca(3680./513*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k4, &ans_buf);
	VectorSca(845./4104*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	f(*ans, param, &k5);

	VectorMov(k1, ans);
	VectorSca(-8./27*delta, ans);
	VectorMov(k2, &ans_buf);
	VectorSca(2*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k3, &ans_buf);
	VectorSca(-3544./2565*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k4, &ans_buf);
	VectorSca(1859./4104*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k5, &ans_buf);
	VectorSca(-11./40*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	f(*ans, param, &k6);
	
	VectorMov(k1, ans);
	VectorSca(16./135*delta, ans);
	VectorMov(k3, &ans_buf);
	VectorSca(6656./12825*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k4, &ans_buf);
	VectorSca(28561./56430*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k5, &ans_buf);
	VectorSca(-9./50*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorMov(k6, &ans_buf);
	VectorSca(2./55*delta, &ans_buf);
	VectorAdd(ans_buf, ans);
	VectorAdd(arg, ans);

	VectorMov(k1, &ans_buf);
	VectorSca(25./216*delta, &ans_buf);
	VectorMov(k3, &k2);
	VectorSca(1408./2565*delta, &k2);
	VectorAdd(k2, &ans_buf);
	VectorMov(k4, &k2);
	VectorSca(2197./4104*delta, &k2);
	VectorAdd(k2, &ans_buf);
	VectorMov(k5, &k2);
	VectorSca(-1./5*delta, &k2);
	VectorAdd(k2, &ans_buf);
	VectorAdd(arg, &ans_buf);

	VectorSub(*ans, &ans_buf);


	DeleteVector(&k1);
	DeleteVector(&k2);
	DeleteVector(&k3);
	DeleteVector(&k4);
	DeleteVector(&k5);
	DeleteVector(&k6);
	DeleteVector(&ans_buf);
}

