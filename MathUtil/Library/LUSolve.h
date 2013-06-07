#ifndef ZARATH_LUSOLVE_H
#define ZARATH_LUSOLVE_H

#include "Matrix/Matrix.h"
#include "Vector/Vector.h"

namespace zarath
{
	template<class numeric>
	void LUSolve(MatrixBase<numeric> &A, VectorBase<numeric> &b, VectorBase<numeric> &x)
	{
		double buf;

		LUMatrix M(b.Dimension());

		M.LUDecomposition(A);
		for(uint32_t i = 0; i < b.Dimension(); ++i)
                {
                        buf = 0;
                        for(uint32_t j = 0; j < i; ++j)
                                buf += M(i, j)*x(j);
                        x(i) = b(i) - buf;
                }

		for(uint32_t i = b.Dimension(); i != 0;)
		{
			--i;
			buf = 0;
			for(uint32_t j = i + 1; j < b.Dimension(); ++j)
				buf += M(i, j)*x(j);
			x(i) = (x(i) - buf)/M(i, i);
		}
	}
}

#endif
