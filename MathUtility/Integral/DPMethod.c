#include "DPMethod.h"

typedef unsigned int uint;

double DPMethod(Vector arg, Vector param, Vector *ans, double *dt, double rel_err, double abs_err, V_VFunc f)
{
	Vector k1 = CreateVector(ans->dim), k2 = CreateVector(ans->dim),  k3 = CreateVector(ans->dim), k4 = CreateVector(ans->dim), k5 = CreateVector(ans->dim), k6 = CreateVector(ans->dim), k7 = CreateVector(ans->dim);
	Vector ans_buf = CreateVector(ans->dim);

	double delta = *dt;
	double max_abs_err = 0, max_rel_err = 0, flag_err = -1;

	do{
		f(arg, param, &k1);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*(1./5.)*k1.val[i];

		f(*ans, param, &k2);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((3./40.)*k1.val[i] + (9./40.)*k2.val[i]);

		f(*ans, param, &k3);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((44./45.)*k1.val[i] - (56./15.)*k2.val[i] + (32./9.)*k3.val[i]);

		f(*ans, param, &k4);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((19372./6561.)*k1.val[i] - (25360./2187.)*k2.val[i] + (64448./6561.)*k3.val[i] - (212./729.)*k4.val[i]);

		f(*ans, param, &k5);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((9017./3168.)*k1.val[i] - (355./33.)*k2.val[i] + (46732./5247.)*k3.val[i] + (49./176.)*k4.val[i] - (5103./18656.)*k5.val[i]);

		f(*ans, param, &k6);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((35./384.)*k1.val[i] - (0)*k2.val[i] + (500./1113.)*k3.val[i] + (125./192.)*k4.val[i] - (2187./6784.)*k5.val[i] + (11./84)*k6.val[i]);

		f(*ans, param, &k7);

		for(uint i = 0; i < ans->dim; ++i)
			ans_buf.val[i] = arg.val[i] + delta*((5179./57600.)*k1.val[i] + (7571./16695.)*k3.val[i] + (393./640.)*k4.val[i] - (92097./339200.)*k5.val[i] + (187./2100.)*k6.val[i] + (1./40.)*k7.val[i]);

		for(uint i = 0; i < ans->dim; ++i)
			ans->val[i] = arg.val[i] + delta*((35./384.)*k1.val[i] + (500./1113.)*k3.val[i] + (125./192.)*k4.val[i] - (2187./6784.)*k5.val[i] + (11./84.)*k6.val[i]);


		max_abs_err = MaxAbsoluteError(*ans, ans_buf);

		if(max_abs_err > abs_err)
		{
			delta *= pow(abs_err/max_abs_err, 1./5);
			continue;
		}

		max_rel_err = MaxRelativeError(*ans, ans_buf);


		if(max_rel_err > rel_err)
		{
			delta *= pow(rel_err/max_rel_err, 1./5);
			continue;
		}

		flag_err = MAX(max_rel_err, max_abs_err);

	}while(flag_err == -1);

	*dt = ((flag_err == 0)?(*dt*2):(delta * pow(MAX(rel_err, abs_err)/flag_err, 1./5)));

	DeleteVector(&k1);
	DeleteVector(&k2);
	DeleteVector(&k3);
	DeleteVector(&k4);
	DeleteVector(&k5);
	DeleteVector(&k6);
	DeleteVector(&k7);
	DeleteVector(&ans_buf);

	return delta;
}

