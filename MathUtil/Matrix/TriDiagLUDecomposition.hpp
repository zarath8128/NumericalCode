#ifndef TRI_DIAG_LU_DECOMPOSITION_HPP
#define TRI_DIAG_LU_DECOMPOSITION_HPP

#ifdef __cplusplus
#include <cstdlib>
#include <cstdint>
#else
#include <stdlib.h>
#include <stdint.h>
#endif


#ifdef __cplusplus
namespace zarath
{

	extern "C"
	{
#endif

		typedef struct TriDiagLUBuffer
		{
			uint32_t size;
			double *buf[3];
		}TDLUBuffer;

		static TDLUBuffer CreateTDLUBuffer(uint32_t size)
		{
			TDLUBuffer buffer;
			buffer.size = size;
			buffer.buf[0] = (double*)malloc(sizeof(double)*(size - 1));
			buffer.buf[1] = (double*)malloc(sizeof(double)*(size));
			buffer.buf[2] = (double*)malloc(sizeof(double)*(size - 1));
			return buffer;
		}

		static void DeleteTDLUBuffer(TDLUBuffer& buffer)
		{
			free(buffer.buf[0]);
			free(buffer.buf[1]);
			free(buffer.buf[2]);
		}

		static double& TDLUBufferIndex(TDLUBuffer& buf, uint32_t row, uint32_t column)
		{
			static double dammy = 0;
			dammy = 0;
			if(row == column)
				return buf.buf[1][row];
			if(row == (column + 1))
				return buf.buf[2][column];
			if((row + 1) == column)
				return buf.buf[0][row];
			return dammy;
		}

		static void TDLUDecomposition(TDLUBuffer& buf)
		{
			double b = 0;
			for(int i = 1; i < buf.size - 1; ++i)
			{
				//U
				b = buf.buf[0][i - 1]*buf.buf[2][i - 1];
				buf.buf[1][i] -= b;
				buf.buf[2][i] /= buf.buf[1][i];
			}
			buf.buf[1][buf.size - 1] -= buf.buf[0][buf.size - 2]*buf.buf[2][buf.size - 2];
		}

#ifdef __cplusplus
	}
}
#endif


#endif
