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
void SUB_C(double *v, double *w, double *buf);
void MUL_C(double *v, double *w, double *buf);
void DIV_C(double *v, double *w, double *buf);

//add equal by complex(+=)
void ADD_E_C(double *src, double *dist);
void SUB_E_C(double *src, double *dist);
void MUL_E_C(double *src, double *dist);
void DIV_E_C(double *src, double *dist);

#ifdef __cplusplus
}
#endif


#endif
