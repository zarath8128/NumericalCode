#include <iostream>
#include "TriDiagLUDecomposition.hpp"
#include <ctime>
#include "Matrix.hpp"

using namespace zarath;

const int s = 2000;

int main()
{
	Matrix<double, s, s> m, n;
	for(int i = 0; i < s; ++i)
		for(int j = 0; j < s; ++j)
			m.SetVal(i, j, 1./(i + j + 1));
	clock_t t0 = clock();
	m.LUDecomposition(n);
	clock_t t1 = clock();
	std::cout << "time :" << (t1 - t0)/(double)CLOCKS_PER_SEC << std::endl;
	
	return 0;
}
