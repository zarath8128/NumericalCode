#ifndef LU_DECOMPOSITION_HPP
#define LU_DECOMPOSITION_HPP

#ifdef __cplusplus
#include <cstdint>
#include <ostream>
#include <iomanip>
#else
#include <stdint.h>
#endif



#ifdef __cplusplus
namespace zarath
{
	extern "C" 
	{
#endif




#ifdef __cplusplus
	}
	
	class LUBuffer
	{
	public:
		LUBuffer(uint32_t size):Size(size)
		{
			buffer = new double[Size*Size];
			U = new double*[Size];
			L = new double*[Size - 1];

			double *tp = buffer;
			for(uint32_t i = 0; i < Size; ++i)
				U[i] = (tp += i);
			tp += Size;
			for(uint32_t i = 0; i < Size -1 ; ++i)
				L[i] = (tp += i);
		}

		~LUBuffer()
		{
			delete [] U;
			delete [] L;
			delete [] buffer;
		}

		double& operator()(uint32_t row, uint32_t column)
		{
			if(row > column)
				return L[row - 1][column];
			else
				return U[column][row];
		}
		
		double getL(uint32_t row, uint32_t column)
		{
			if(row > column)
				return L[row - 1][column];
			else if(row == column)
				return 1;
			else
				return 0;
		}
	
		double getU(uint32_t row, uint32_t column)
		{
			if(row > column)
				return 0;
			else
				return U[column][row];
		}

		int LUDecomposition()
		{
			double buf;
			for(uint32_t i = 0; i < Size; ++i)
			{
				//U
				for(uint32_t c = i; c < Size; ++c)
				{
					for(uint32_t r = 0; r < i; ++r)
						U[c][i] -= (L[i - 1][r] * U[c][r]);
				}

				//L
				for(uint32_t r = i; r < (Size - 1); ++r)
				{
					for(uint32_t c = 0; c < i; ++c)
						L[r][i] -= (L[r][c] * U[i][c]);
					L[r][i] /= U[i][i];
				}
			}
			return 0;
		}
		
		//b <- this-composite
		int LUComposition(LUBuffer& b)
		{
			double buf;
			for(int i = 0; i < Size; ++i)
				for(int j = 0; j < Size; ++j)
				{
					buf = 0;
					for(int k = 0; k < Size; ++k)
						buf += this->getL(i, k)*this->getU(k, j);
					b(i, j) = buf;
				}
			return 0;
		}

		uint32_t getSize(){return Size;}

	private:
		uint32_t Size;
		double **L;
		double **U;
		double *buffer;
	};

	std::ostream& operator << (std::ostream& dist, LUBuffer& buf)
	{
		for(uint32_t i = 0; i < buf.getSize(); ++i)
		{
			for(uint32_t j = 0; j < buf.getSize(); ++j)
			{
				dist << std::setw(15) << std::left << buf(i, j);
			}
			dist << std::endl;
		}
		return dist;
	}
}
#endif


#endif
