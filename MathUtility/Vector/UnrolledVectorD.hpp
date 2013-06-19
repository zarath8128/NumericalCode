#ifndef ZARATH_UNROLLED_VECTOR_D_HPP
#define ZARATH_UNROLLED_VECTOR_D_HPP

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#endif

#include "Utility/Align.h"
#include "NumericalVectorSpace.hpp"


#ifdef __cplusplus
namespace zarath
{
	extern "C"
	{
#endif
		void URVectorD_ADD(double *src1, double *src2, uint32_t dimension, double *dist);

#ifdef __cplusplus
	}

	class 
#else
	typedef struct
#endif
	UnrolledVectorD
#ifdef __cplusplus
		:public AbstractNumericalVectorSpace<double, double, UnrolledVectorD>
#endif
	{
#ifdef __cplusplus
	private:
#endif
		uint32_t dimension;
		double *unaligned_buf;
#ifdef __cplusplus
	public:
#endif
		double *buf;
#ifdef __cplusplus
		UnrolledVectorD(uint32_t dim)
		{
			dimension = 16*((dim / 16) + ((dim % 16 == 0)?(0):(1)));
			unaligned_buf = new double[dimension + 1];
			buf = (double*)Align(unaligned_buf, 16);
		}

		~UnrolledVectorD()
		{
			delete [] unaligned_buf;
		}

		uint32_t Dimension(){return dimension;}
		double &operator()(uint32_t dim){return buf[dim];}
#endif
	}
#ifdef __cplusplus
#else
	URVectorD
#endif
	;

#ifdef __cplusplus
#else
	static inline void PrintURVectorD(URVectorD *v)
	{
		for(uint32_t i = 0; i < v->dimension; ++i)
			printf("%e\n", v->buf[i]);
	}

	static inline void InitializeURVectorD(URVectorD *v, uint32_t dimension)
	{
		v->dimension = 16*((dimension/16) + ((dimension % 16 == 0)?(0):(1)));
		v->unaligned_buf = (double*)malloc(sizeof(double) * (v->dimension + 1));
		v->buf = (double*)Align(v->unaligned_buf, 16);
	}

	static inline URVectorD CreateURVectorD(uint32_t dimension)
	{
		URVectorD t;
		InitializeURVectorD(&t, dimension);
		return t;	
	}
#endif

#ifdef __cplusplus
}
#endif


#endif
