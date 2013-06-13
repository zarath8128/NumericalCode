#ifndef ZARATH_VECTOR_H
#define ZARATH_VECTOR_H

#include <iostream>
#include <iomanip>
#include <cstdint>

#include "Matrix/Matrix.h"

namespace zarath
{
	template<class numeric>
	class VectorBase
	{
	public:
		virtual uint32_t Dimension() const = 0;
		virtual numeric &operator()(uint32_t index) = 0;
	};

	template<class numeric>
	std::ostream &operator<<(std::ostream &dist, VectorBase<numeric> &v)
	{
		for(uint32_t i = 0; i < v.Dimension(); ++i)
		{
			dist << std::setw(10) << std::right << i << ": ";
			dist << std::setw(14) << std::scientific << std::setprecision(6) << std::right <<  v(i) << "\n";
		}
		return dist;
	}

	template<class numeric>
	class Vector
		:public VectorBase<numeric>
	{
	public:
		Vector(uint32_t dimension):dim(dimension), buf(new numeric[dimension]){}
		Vector(const Vector& v):dim(v.dim), buf(new numeric[v.dim])
		{
			for(uint32_t i = 0; i < v.dim; ++i)
				buf[i] = v.buf[i];
		}
		~Vector(){delete [] buf;}

		uint32_t Dimension() const {return dim;}
		numeric &operator()(uint32_t index){return buf[index];}

		Vector operator+(const Vector &v)
		{
			Vector t(dim);
			for(uint32_t i = 0; i < dim; ++i)
				t.buf[i] = buf[i] + v.buf[i];
			return t;
		}

		Vector &operator+=(const Vector &v)
		{
			for(uint32_t i = 0; i < dim; ++i)
				buf[i] += v.buf[i];
			return *this;
		}
	
		Vector operator-()
		{
			Vector t(dim);
			for(uint32_t i = 0; i < dim; ++i)
				t.buf[i] = -buf[i];
			return t;
		}	

		Vector operator*(const numeric& s)
		{
			Vector t(dim);
			for(uint32_t i = 0; i < dim; ++i)
				t.buf[i] = buf[i]*s;
			return t;	
		}
	
		Vector &operator*=(const numeric& s)
		{
			for(uint32_t i = 0; i < dim; ++i)
				buf[i] *= s;
			return *this;
		}
		
		Vector &operator=(const Vector &v)
		{
			for(uint32_t i = 0; i < dim; ++i)
				buf[i] = v.buf[i];
			return *this;
		}
	private:
		uint32_t dim;
		numeric *buf;
	};

	template<class numeric>
	numeric dot(VectorBase<numeric> &u, VectorBase<numeric> &v)
	{
		numeric b(0);
		for(uint32_t i = 0; i < u.Dimension(); ++i)
			b += u(i)*v(i);
		return b;
	}

	template<class numeric, class vector>
	vector operator*(MatrixBase<numeric>& m, vector &v)
	{
		numeric b = 0;
		vector w(v);
		for(uint32_t i = 0; i < m.Column(); ++i)
		{
			b = 0;
			for(uint32_t j = 0; j < v.Dimension(); ++j)
				b += m(i, j)*v(j);
			w(i) = b;
		}
		return w;
	}
}

#endif
