#ifndef ZARATH_VECTOR_D_HPP
#define ZARATH_VECTOR_D_HPP

#include "Utility/Align.h"
#include "AbstractVectorSpace.hpp"

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#endif

#ifdef __cplusplus
namespace zarath
{
	extern "C" 
	{
#endif
		void VectorD_ADD(double* src1, double* src2, uint32_t dimension, double *dest);
		void VectorD_SUB(double* src1, double* src2, uint32_t dimension, double *dest);//dest <- src2 - src1
		void VectorD_NEG(double* src, double* dest, uint32_t dimension);
		void VectorD_SCA(double *src, double *dest, uint32_t dimension, double d);

#ifdef __cplusplus
	}
#else
#endif


#ifdef __cplusplus
	template<uint32_t dimension>
	class
#else
	typedef struct
#endif

	VectorD

#ifdef __cplusplus
		:public AbstractNumericalVectorSpace<double, double, VectorD<dimension> >
#endif
	{
#ifdef __cplusplus
	private:
#else
		uint32_t dimension;
#endif
		double *unaligned_buf;
#ifdef __cplusplus
	public:
#endif
		double *buf;		

#ifdef __cplusplus
		VectorD():unaligned_buf(new double[dimension + 1]), buf((double*)Align(unaligned_buf, 16)){}
		VectorD(uint32_t i):VectorD(){}		
		VectorD(VectorD &&v):unaligned_buf(v.unaligned_buf), buf(v.buf){v.unaligned_buf = nullptr;}
		~VectorD(){delete [] unaligned_buf;}
		
		uint32_t Dimension(){return dimension;}

		VectorD operator+(VectorD &v)
		{
			VectorD t;
			VectorD_ADD(buf, v.buf, dimension, t.buf);
			return t;	
		}

		VectorD &operator+=(VectorD &v)
		{
			VectorD_ADD(buf, v.buf, dimension, buf);
			return *this;
		}

		VectorD &operator+=(VectorD &&v)
		{
			VectorD_ADD(buf, v.buf, dimension, buf);
			return *this;
		}

		VectorD operator-()
		{
			VectorD t;
			VectorD_NEG(buf, t.buf, dimension);
			return t;
		}

		VectorD operator-(VectorD &v)
		{
			VectorD t;
			VectorD_SUB(v.buf, buf, dimension, t.buf);
			return t;
		}

		VectorD &operator-=(VectorD &v)
		{
			VectorD_SUB(v.buf, buf, dimension, buf);
			return *this;
		}

		VectorD operator*(double &s)
		{
			VectorD t;
			VectorD_SCA(buf, t.buf, dimension, s);
			return t;
		}

		VectorD &operator*=(double &s)
		{
			VectorD_SCA(buf, buf, dimension, s);
			return *this;
		}
		
		VectorD &operator=(VectorD &v)
		{
			for(uint32_t i = 0; i < dimension; ++i)
				buf[i] = v.buf[i];
			return *this;
		}

		VectorD &operator=(VectorD &&v)
		{
			buf = v.buf;
			unaligned_buf = v.unaligned_buf;
			v.unaligned_buf = 0;
			return *this;
		}

		double &operator()(uint32_t i){return buf[i];}
#endif
	}
#ifndef __cplusplus
	VectorD
#endif
	;
#ifdef __cplusplus
#else
	inline void InitializeVectorD(uint32_t dimension, VectorD *v)
	{
		v->dimension = dimension;
		v->unaligned_buf = (double*)malloc(dimension * sizeof(double));
		v->buf = Align(v->unaligned_buf, 16);
	}

	inline VectorD CreateVectorD(uint32_t dimension)
	{
		VectorD t;
		InitializeVectorD(dimension, &t);
		return t;
	}

	inline void DeleteVectorD(VectorD *v)
	{
		free(v->unaligned_buf);
		v->buf = v->unaligned_buf = 0;
	}

	inline void FinalizeVectorD(VectorD *v)
	{
		free(v->unaligned_buf);
		v->buf = v->unaligned_buf = 0;
	}

	inline void PrintVectorD(VectorD *v)
	{
		for(uint32_t i = 0; i < v->dimension; ++i)
			printf("%e\n", v->buf[i]);
	}

	inline void ADD_VectorD(VectorD *v, VectorD *w, VectorD *ans)
	{
		VectorD_ADD(v->buf, w->buf, v->dimension, ans->buf);
	}
#endif

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#else
	VectorD CreateVectorD(uint32_t dimension);
	void DeleteVectorD(VectorD *v);
	void InitializeVectorD(uint32_t dimension, VectorD *v);
	void FinalizeVectorD(VectorD *v);

	void PrintVectorD(VectorD *v);

	void ADD_VectorD(VectorD *v, VectorD *w, VectorD *ans);

#endif

#endif


