#ifndef COMPLEX_H
#define COMPLEX_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#include "Utility/Align.h"

#ifdef __cplusplus
extern "C"
{
#endif

//add by complex(+)
void ADD_C(double *v, double *w, double *buf);
//w - v = buf
void SUB_C(double *v, double *w, double *buf);
void MUL_C(double *v, double *w, double *buf);
//w / v = buf
void DIV_C(double *v, double *w, double *buf);

//add equal by complex(+=)
//dist += src
void ADD_E_C(double *src, double *dist);
//dist -= src (dist = dist - src)
void SUB_E_C(double *src, double *dist);
//dist *= src
void MUL_E_C(double *src, double *dist);
//dist /= src (dist = dist / src)
void DIV_E_C(double *src, double *dist);

#ifdef __cplusplus
}

template<class T>
class Complex
{
public:
	
protected:
private:
};

class Complex<double>
{
public:
	double *val;
	Complex()
	{
		val = *Align(buf, 16);
	}
protected:
private:
	double buf[3];
};


#endif


#endif
