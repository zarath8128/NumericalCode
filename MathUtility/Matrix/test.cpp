#include <iostream>
#include <iomanip>
#include "TriDiagLUDecomposition.hpp"
#include <ctime>
#include "Matrix.hpp"

using namespace zarath;

const int s = 4000;

int main()
{
//	Matrix<double, s, s> m, n;
	TDLUBuffer tdlubuf = CreateTDLUBuffer(s);

	for(int i = 0; i < s; ++i)
		for(int j = 0; j < s; ++j)
			TDLUBufferIndex(tdlubuf, i, j) = 1./(1 + i + j);//m.SetVal(i, j, 1./(i + j + 1));
	clock_t t0 = clock();
	TDLUDecomposition(tdlubuf);//m.LUDecomposition(n);
	clock_t t1 = clock();
	//std::cout << "time :" << (t1 - t0)/(double)CLOCKS_PER_SEC << std::endl;
	for(int i = 0; i < s; ++i)
	{
		for(int j = ((i < 1)?(0):(i - 1)); j < ((i < s - 1)?(i + 2):(i + 1)); ++j)
			std::cout << std::setw(12) << TDLUBufferIndex(tdlubuf, i, j);
		std::cout << "\n";
	}
	std::cout << std::endl;
	return 0;
}
