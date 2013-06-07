#include <iostream>
#include "TriDiagLUDecomposition.hpp"
#include <ctime>

using namespace zarath;

const int s = 2500;

int main()
{
/*	Matrix<double, s, s> m, n;
	for(int i = 0; i < s; ++i)
		for(int j = 0; j < s; ++j)
			m.SetVal(i, j, 1./(i + j + 1));
	clock_t t0 = clock();
	m.LUDecomposition(n);
	clock_t t1 = clock();
	std::cout << "time :" << t1 - t0 << std::endl;
*/	
	TDLUBuffer b = CreateTDLUBuffer(3);

	std::cout << b.size << std::endl;

	for(int i = 0; i < b.size - 1; ++i)
		for(int j = 0; j < b.size; ++j)
		{
			TDLUBufferIndex(b, i, j) = 1./(1+i+j);
		}

	TDLUBufferIndex(b, 3, 2) = 123;

	TDLUDecomposition(b);

	for(int r = 0; r < b.size; ++r)
	{
		for(int c = 0; c < b.size; ++c)
			std::cout << TDLUBufferIndex(b, r, c) << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	DeleteTDLUBuffer(b);
	return 0;
}
