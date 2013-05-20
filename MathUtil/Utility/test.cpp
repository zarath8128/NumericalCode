#include <iostream>
#include "Align.h"
#include "BufferManager.hpp"

int main()
{
	double *a[3];
	a[0] = new double[3];
	a[1] = new double[3];
	a[2] = new double[3];

	a[0][0] = 0.1;
	a[0][1] = 0.2;
	a[0][2] = 0.3;

	BufferManager<double*, 3> buf(a);

	buf.reverse();

	for(int j = 0; j < 3; ++j){
	for(int i = 0; i < 3; ++i)
		std::cout << buf[j][i] << "\t";
	std::cout << std::endl;	}

	return 0;
}
