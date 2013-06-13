#ifndef ZARATH_VECTOR_D_HPP
#define ZARATH_VECTOR_D_HPP

#include <cstdint>
#include "AbstractVectorSpace.hpp"
#include "Utility/Align.h"

namespace zarath
{
	extern "C" 
	{
		void VectorD_ADD(double* src1, double* src2, uint32_t dimension, double *dest);
		void VectorD_SUB(double* src1, double* src2, uint32_t dimension, double *dest);//dest <- src2 - src1
		void VectorD_NEG(double* src, double* dest, uint32_t dimension);
		void VectorD_SCA(double *src, double *dest, uint32_t dimension, double d);
	}

/*	template<uint32_t dimension>
	using VectorD = VectorD<double, dimension>;
	
	template<uint32_t dimension>
	std::ostream &operator<<(std::ostream &dest, VectorD<dimension> &v)
	{
		for(uint32_t i = 0; i < dimension; ++i)
			dest << v(i) << "\n";
		return dest;
	}
*/
	template<uint32_t dimension>
	class VectorD
		:public AbstractNumericalVectorSpace<double, double, VectorD<dimension> >
	{
	private:
		double *unaligned_buf;
	public:
		double *buf;		

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
		
	};
}

#endif
