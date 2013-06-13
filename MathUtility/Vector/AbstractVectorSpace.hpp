#ifndef ZARATH_ABSTRACT_VECTOR_SPACE_HPP
#define ZARATH_ABSTRACT_VECTOR_SPACE_HPP

//**************************************************************/
//
//
//**************************************************************/


#include <iostream>
#include <cmath>
#include <cstdint>

namespace zarath
{
	template<class scalar, class vector_space>
	class AbstractVectorSpace
	{
	public:
		virtual vector_space operator+(vector_space &v) = 0;
		virtual vector_space &operator+=(vector_space &v) = 0;
		virtual vector_space operator-() = 0;
		virtual vector_space operator-(vector_space &v) = 0;
		virtual vector_space &operator-=(vector_space &v) = 0;
		
		virtual vector_space operator*(scalar &s) = 0;
		virtual vector_space &operator*=(scalar &s) = 0;

		virtual vector_space &operator=(vector_space &v) = 0;
		virtual bool operator==(vector_space &v) = 0;
		virtual bool operator!=(vector_space &v) = 0;
	};

	template<class scalar, class norm, class norm_space>
	class AbstractNormSpace
		:AbstractVectorSpace<scalar, norm_space>
	{
	public:
		virtual norm Norm() = 0;
	};

	template<class scalar, class inner, class inner_product_space>
	class AbstractInnerProductSpace
		:AbstractVectorSpace<scalar, inner_product_space>
	{
	public:
		virtual inner Dot(inner_product_space &v, inner_product_space &w) = 0;
	};

	template<class scalar, class numeric, class numerical_vector_space>
	class AbstractNumericalVectorSpace
		:AbstractVectorSpace<scalar, numerical_vector_space>
	{
	public:
		virtual uint32_t Dimension() = 0;
		virtual numeric &operator()(uint32_t i) = 0;

		numerical_vector_space operator+(numerical_vector_space &v)
		{
			numerical_vector_space t(Dimension());
			for(uint32_t i = 0; i < Dimension(); ++i)
				t(i) = (*this)(i) + v(i);
			return t;
		}

		numerical_vector_space &operator+=(numerical_vector_space &v)
		{
			for(uint32_t i = 0; i < Dimension(); ++i)
				(*this)(i) += v(i);
			return *(numerical_vector_space*)this;
		}

		numerical_vector_space &operator+=(numerical_vector_space &&v)
		{
			for(uint32_t i = 0; i < Dimension(); ++i)
				(*this)(i) += v(i);
			return *(numerical_vector_space*)this;
		}

		numerical_vector_space operator-()
		{
			numerical_vector_space t(Dimension());
			for(uint32_t i = 0; i < Dimension(); ++i)
				t(i) = -(*this)(i);
			return t;
		}

		numerical_vector_space operator-(numerical_vector_space &v)
		{
			numerical_vector_space t(Dimension());
			for(uint32_t i = 0; i < Dimension(); ++i)
				t(i) = (*this)(i) - v(i);
			return t;
		}

		numerical_vector_space &operator-=(numerical_vector_space &v)
		{
			for(uint32_t i = 0; i < Dimension(); ++i)
				(*this)(i) -= v(i);
			return *(numerical_vector_space*)this;
		}

		numerical_vector_space operator*(scalar &s)
		{
			numerical_vector_space t(Dimension());
			for(uint32_t i = 0; i < Dimension(); ++i)
				t(i) = (*this)(i) * s;
			return t;
		}

		numerical_vector_space &operator*=(scalar &s)
		{
			for(uint32_t i = 0; i < Dimension(); ++i)
				(*this) *= s;
			return *(numerical_vector_space*)this;
		}

		numerical_vector_space &operator=(numerical_vector_space &v)
		{
			for(uint32_t i = 0; i < Dimension(); ++i)
				(*this)(i) = v(i);
			return *(numerical_vector_space*)this;
		}	
		
		bool operator==(numerical_vector_space &v)
		{
			return !((*this) != v);
		}

		bool operator!=(numerical_vector_space &v)
		{
			for(uint32_t i = 0; i < Dimension(); ++i)
				if((*this)(i) != v(i))
					return true;
			return false;
		}
	};

	template<class scalar, class numeric, class numerical_vector_space>
	std::ostream &operator<<(std::ostream &dest, AbstractNumericalVectorSpace<scalar, numeric, numerical_vector_space> &v)
	{
		for(uint32_t i = 0; i < v.Dimension(); ++i)
			dest << v(i) << "\n";
		return dest;
	}

	
	template<class scalar, class numeric, class numerical_vector_space>
	std::ostream &operator<<(std::ostream &dest, AbstractNumericalVectorSpace<scalar, numeric, numerical_vector_space> &&v)
	{
		for(uint32_t i = 0; i < v.Dimension(); ++i)
			dest << v(i) << "\n";
		return dest;
	}


}

#endif
