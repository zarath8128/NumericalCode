#include <iostream>
#include <ctime>

#include "Matrix.h"

using namespace zarath;

int s = 500;
int main()
{
	clock_t t0 = clock();
	Matrix<double> m(s, s);
	LUMatrix LU(s);
	clock_t t1 = clock();
	for(uint32_t r = 0; r < m.Row(); ++r)
		for(uint32_t c = 0; c < m.Column(); ++c)
			m(r, c) = 1./(1 + r + c);
	clock_t t2 = clock();	
	std::cout << m << std::endl;
	LU.LUDecomposition(m);
	clock_t t3 = clock();

	double buf = 0;
	for(uint32_t r = 0; r < m.Row(); ++r)
		for(uint32_t c = 0; c < m.Column(); ++c)
		{
			buf = 0; 
			for(int32_t i = 0; i < s; ++i)
				buf += ((r>i)?(LU(r, i)):((r==i)?(1):(0)))*((i>c)?(0):(LU(i, c)));
			m(r, c) = buf;
		}


	std::cout << m << std::endl;
	std::cout << "Allocate :" << (t1 - t0)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << "Init     :" << (t2 - t1)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << "LUDecomp :" << (t3 - t2)/(double)CLOCKS_PER_SEC << std::endl;
	return 0;
}
