#include <iostream>
#include "LUDecomposition.hpp"
#include <ctime>

using namespace zarath;

const int s = 500;

int main()
{
	LUBuffer b(s), c(s), d(s);

	for(int i = 0; i < s; ++i)
		for(int j = 0; j < s; ++j)
			b(i, j) = c(i, j) = 1./(i + j + 1);
	//std::cout << b << std::endl;

	clock_t t0 = clock();
	b.LUDecomposition();
	clock_t t1 = clock();

	//std::cout << b << std::endl;

//	b.LUComposition(d);
	clock_t t2 = clock();
	
	//std::cout << d << std::endl;
	
	std::cout << "size= " << s << std::endl;
	std::cout << "time= " << (t1 - t0)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << "time= " << (t2 - t1)/(double)CLOCKS_PER_SEC << std::endl;
	return 0;
}
