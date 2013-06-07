#ifndef ZARATH_MATRIX_H
#define ZARATH_MATRIX_H

#include <cstdint>
#include <iostream>
#include <iomanip>

namespace zarath
{
	template<class numeric>
	class MatrixBase
	{
	public:
		virtual uint32_t Row() const = 0;
		virtual uint32_t Column() const = 0;
		virtual numeric& operator()(uint32_t row, uint32_t column) = 0;
	};

	template<class numeric>
	std::ostream &operator<<(std::ostream &dist, MatrixBase<numeric> &m)
	{
		dist << std::setw(12) << " ";
		for(uint32_t c = 0; c < m.Column(); ++c)
			dist << std::setw(14) << std::right << c;
		dist << "\n";

		for(uint32_t r = 0; r < m.Row(); ++r)
		{
			dist << std::setw(10) << std::right << r << ": ";
			for(uint32_t c = 0; c < m.Column(); ++c)
				dist << std::setw(14) << std::scientific << std::setprecision(6) << std::right << m(r, c);
			dist << "\n";
		}
		return dist << "\n";
	}

	template<class numeric>
	class Matrix
		:public MatrixBase<numeric>
	{
	public:
		Matrix(uint32_t row, uint32_t column):row(row), column(column), buf(new numeric[row*column]){}
		~Matrix(){delete [] buf;}

		uint32_t Row() const {return row;}
		uint32_t Column() const {return column;}
		numeric& operator()(uint32_t row, uint32_t column)
		{
			return buf[row*this->column + column];
		}

	private:
		uint32_t row, column;
		numeric *buf;
	};
	
	class LUMatrix
		:public MatrixBase<double>
	{
	public:
		LUMatrix(uint32_t size):size(size), buf(new double[size*size]), L(new double*[size - 1]), U(new double*[size])
		{
			double *p = buf;
			for(uint32_t c = 0; c < size; ++c)
				U[c] = (p += c);
			p += size;
			for(uint32_t r = 0; r < size - 1; ++r)
				L[r] = (p += r);
		}
		~LUMatrix(){delete [] buf;delete [] L; delete [] U;}

		double &operator()(uint32_t row, uint32_t column)
		{
			return (row > column)?(L[row - 1][column]):(U[column][row]);
		}

		template<class numeric>
		void LUDecomposition(MatrixBase<numeric> &m)
		{
			double b;
			for(uint32_t i = 0; i < size; ++i)
			{
				//U
				for(uint32_t c = i; c < size; ++c)
				{
					b = m(i, c);
					for(uint32_t r = 0; r < i; ++r)
						b -= L[i - 1][r]*U[c][r];
					U[c][i] = b;
				}

				//L
				for(uint32_t r = i; r < size - 1; ++r)
				{
					b = m(r + 1, i);
					for(uint32_t c = 0; c < i; ++c)
						b -= L[r][c]*U[i][c];
					L[r][i] = b/U[i][i];
				}
			}
		}

		uint32_t Row() const {return size;}
		uint32_t Column() const {return size;}
	private:
		uint32_t size;
		double *buf;
		double **L;
		double **U;
	};
}

#endif
