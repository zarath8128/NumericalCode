#include "MathLib.h"
#include "Utility/Align.h"
#include <iostream>
<<<<<<< HEAD
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


=======

int main()
{
	AlignedArray<double, 16> d(2);
	d[0] = 12;
	d[1] = 5;
	std::cout << norm_asm(&d[0]) << std::endl;
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422
	return 0;
}
