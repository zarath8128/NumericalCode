#include "MathLib.h"
#include "Utility/Align.h"
#include <iostream>

int main()
{
	AlignedArray<double, 16> d(2);
	d[0] = 12;
	d[1] = 5;
	std::cout << norm_asm(&d[0]) << std::endl;
	return 0;
}
