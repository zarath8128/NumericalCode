#include <iostream>

#include "Vector.h"

using namespace zarath;

int s = 3;

int main()
{
	Vector<double> v(s), u(s);
	for(int i = 0; i < v.Dimension(); ++i)
		v(i) = 1./(2+ i), u(i) = 2 + i*i;
	std::cout << v << std::endl << u << std::endl;
	std::cout << dot(v, u) << std::endl;
	return 0;
}
