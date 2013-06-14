#include <iostream>
#include <ctime>

#include "Vector.h"
#include "NumericalVectorSpace.hpp"
#include "VectorD.hpp"

using namespace zarath;

constexpr int s = 30001;

int main()
{
	Vector<double> v(s), u(s);
	NumericalVectorSpace<double, s> w;
	VectorD<s> a;

	double ds = 1.01;
	float fs = 1.01;

	for(int i = 0; i < v.Dimension(); ++i)
		a(i) = v(i) = w(i) = 1./(1 + i), u(i) = 2 + i*i;

	clock_t t0 = clock();
	for(int i = 0; i < 1000; ++i)
		w += w;	
	clock_t t1 = clock();
	for(int i = 0; i < 1000; ++i)
		v += v;
	clock_t t2 = clock();
	for(int i = 0; i < 1000; ++i)
		a += a;
	clock_t t3 = clock();	

	//std::cout << a << std::endl;
	std::cout << "w:" << (t1 - t0)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << "v:" << (t2 - t1)/(double)CLOCKS_PER_SEC << std::endl;
	std::cout << "a:" << (t3 - t2)/(double)CLOCKS_PER_SEC << std::endl;
	return 0;
}
