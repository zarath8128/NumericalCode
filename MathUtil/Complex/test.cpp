#include <iostream>
#include "Complex.h"
#include "Utility/Align.h"

int main()
{
	short bb = 12;
	AlignedArray<double, 16> d(2), e(2), b(2);
	d[0] = 1.2;
	d[1] = 2.5;

	e[0] = 0.2;
	e[1] = 0.3;

	std::cout << d[0] << "\t" << d[1] << std::endl;
	std::cout << e[0] << "\t" << e[1] << std::endl;
	SUB_C(&d[0], &e[0], &b[0]);

	std::cout << b[0] << "\t" << b[1] << std::endl;
	DIV_C(&d[0], &e[0], &b[0]);
	std::cout << b[0] << "\t" << b[1] << std::endl;

	return 0;
}
