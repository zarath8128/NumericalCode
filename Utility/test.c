#include <stdio.h>
#include "C_MACRO_UTILITY.h"

void t(void)
{
	DEBUG_REPORT;
}

int main(void)
{
	DEBUG_REPORT;
	t();
	return 0;
}
