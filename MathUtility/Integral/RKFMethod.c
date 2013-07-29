#include "RKFMethod.h"

typedef unsigned int uint;

double RKFMethod(Vector arg, Vector param, Vector *ans, double *dt, double rel_err, double abs_err, V_VFunc f)
{
	Vector k1 = CreateVector(ans->dim), k2 = CreateVector(ans->dim),  k3 = CreateVector(ans->dim), k4 = CreateVector(ans->dim), k5 = CreateVector(ans->dim), k6 = CreateVector(ans->dim);
	Vector ans_buf = CreateVector(ans->dim);

	double delta = *dt, d;
	double err = 0, flag_err = -1;
	const double limit = 3;

	do{
		f(arg, param, &k1);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*(1./4.)*k1.val[i];

		f(*ans, param, &k2);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((3./32.)*k1.val[i] + (9./32.)*k2.val[i]);

		f(*ans, param, &k3);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((1932./2197.)*k1.val[i] - (7200./2197.)*k2.val[i] + (7296./2197.)*k3.val[i]);

		f(*ans, param, &k4);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((439./216.)*k1.val[i] - 8.*k2.val[i] + (3680./513.)*k3.val[i] - (845./4104.)*k4.val[i]);

		f(*ans, param, &k5);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*(-(8./27.)*k1.val[i] + 2.*k2.val[i] - (3544./2565.)*k3.val[i] + (1859./4104.)*k4.val[i] - (11./40.)*k5.val[i]);

		f(*ans, param, &k6);

		for(uint i = 0; i < ans->dim; ++i)
			ans_buf.val[i] = arg.val[i] + delta*((25./216.)*k1.val[i] + (1408./2565.)*k3.val[i] + (2197./4104.)*k4.val[i] - (1./5.)*k5.val[i]);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((16./135.)*k1.val[i] + (6656./12825.)*k3.val[i] + (28561./56430.)*k4.val[i] - (9./50.)*k5.val[i] + (2./55.)*k6.val[i]);
		
		err = MaxError(*ans, ans_buf, abs_err, rel_err);

		d = pow(1/err, 0.2);

		d = 0.8*((d>limit)?(limit):((d<(1/limit))?(1/limit):(d)));

		if(err < 1)
			break;


		delta *= d;

	}while(err != 0);

	*dt = ((err != 0)?(delta*d):(*dt));

	DeleteVector(&k1);
	DeleteVector(&k2);
	DeleteVector(&k3);
	DeleteVector(&k4);
	DeleteVector(&k5);
	DeleteVector(&k6);
	DeleteVector(&ans_buf);

	return delta;
}

