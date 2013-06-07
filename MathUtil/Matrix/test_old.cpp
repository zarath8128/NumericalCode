#include <iostream>
#include <cmath>
#include "LUDecomposition.hpp"
#include <ctime>

using namespace zarath;

const int s = 10000;

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

	b.LUComposition(d);
	clock_t t2 = clock();
	
	double buf = 0;
	
	for(int i = 0; i < s; ++i)
		for(int j = 0; j < s; ++j)
			(buf += ((c(i, j) - d(i, j))*(c(i, j) - d(i, j)))/(c(i, j)*c(i ,j)));

	clock_t t3 = clock();	
	//std::cout << d << std::endl;
	
	std::cout << "size= " << s << std::endl;
	std::cout << "err = " << sqrt(buf) << std::endl;
	std::cout << "time= " << (t1 - t0)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << "time= " << (t2 - t1)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << "time= " << (t3 - t2)/(double)CLOCKS_PER_SEC << std::endl;

	return 0;
}
