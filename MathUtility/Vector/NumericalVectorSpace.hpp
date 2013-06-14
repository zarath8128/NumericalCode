#ifndef ZARATH_NUMERICAL_VECTOR_SPACE_HPP
#define ZARATH_NUMERICAL_VECTOR_SPACE_HPP

#ifdef __cplusplus

#include "AbstractVectorSpace.hpp"

namespace zarath
{
	template<class numeric, uint32_t dimension>
	class NumericalVectorSpace
		:public AbstractNumericalVectorSpace<numeric, numeric, NumericalVectorSpace<numeric, dimension>>
	{
	public:
		numeric *buf;
		
		NumericalVectorSpace():buf(new numeric[dimension]){}
		NumericalVectorSpace(uint32_t dim):NumericalVectorSpace(){}
		NumericalVectorSpace(NumericalVectorSpace &&v):buf(v.buf){v.buf = 0;}
		~NumericalVectorSpace(){delete [] buf;}

		uint32_t Dimension(){return dimension;}

		NumericalVectorSpace operator+(NumericalVectorSpace &v)
		{
			NumericalVectorSpace t;
			for(uint32_t i = 0; i < dimension; ++i)
				t.buf[i] = buf[i] + v.buf[i];
			return t;
		}

		NumericalVectorSpace &operator+=(NumericalVectorSpace &v)
		{
			for(uint32_t i = 0; i < dimension; ++i)
				buf[i] += v.buf[i];
			return *this;
		}

		NumericalVectorSpace &operator+=(NumericalVectorSpace &&v)
		{
			for(uint32_t i = 0; i < dimension; ++i)
				buf[i] += v.buf[i];
			return *this;
		}

		NumericalVectorSpace operator-()
		{
			NumericalVectorSpace t;
			for(uint32_t i = 0; i < dimension; ++i)
				t.buf[i] = -buf[i];
			return t;
		}
	
		NumericalVectorSpace operator-(NumericalVectorSpace &v)
		{
			NumericalVectorSpace t;
			for(uint32_t i = 0; i < dimension; ++i)
				t.buf[i] = buf[i] - v.buf[i];
			return t;
		}

		NumericalVectorSpace &operator-=(NumericalVectorSpace &v)
		{
			for(uint32_t i = 0; i < dimension; ++i)
				buf[i] -= v.buf[i];
			return *this;
		}

		NumericalVectorSpace operator*(numeric &s)
		{
			NumericalVectorSpace t;
			for(uint32_t i = 0;i < dimension; ++i)
				t.buf[i] = buf[i]*s;
			return t;
		}

		NumericalVectorSpace &operator*=(numeric &s)
		{
			for(uint32_t i = 0; i < dimension; ++i)
				buf[i] *= s;
			return *this;
		}

		NumericalVectorSpace &operator=(NumericalVectorSpace &v)
		{
			for(uint32_t i = 0; i < dimension; ++i)
				buf[i] = v.buf[i];
			return *this;
		}

		NumericalVectorSpace &operator=(NumericalVectorSpace &&v)
		{
			buf = v.buf;
			v.buf = nullptr;
			return *this;
		}


		numeric &operator()(uint32_t i)
		{
			return buf[i];
		}
	};

}

#endif

#endif
