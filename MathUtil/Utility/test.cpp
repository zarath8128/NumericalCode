#include <iostream>
#include "Align.h"

int main()
{
	AlignedArray<double, 16> d(4000000000UL); 	
	std::cout << "Hallo World!" << std::endl;
	d[0] = 1.2;
	std::cout << &d[0] << std::endl;
	return 0;
}
