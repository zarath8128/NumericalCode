#include "MathLib.h"
#include "Utility/Align.h"
#include <iostream>
#include <ctime>
#include "Vector.hpp"

using namespace zarath;

int main()
{
	Vector<int, 3> v, w;
	v[0] = 2;
	v[1] = 3;
	v[2] = 4;
	w[0] = w[1] = w[2] = 1;	

	clock_t t0 = clock();
	for(int i = 0; i < 1000000000; ++i)
		v += w;
	clock_t t1 = clock();
	std::cout << (t1 - t0)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << v << std::endl;	


	return 0;
}
