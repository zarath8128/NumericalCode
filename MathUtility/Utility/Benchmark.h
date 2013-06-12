#ifndef BENCHMARK_H
#define BENCHMARK_H

#ifdef __cplusplus
#include <cstdint>
#include <ctime>
#else
#include <stdint.h>
#include <time.h>
#endif

#ifdef __cplusplus
extern "C" 
{
	namespace zarath
	{
#endif

//"BenchMark" will return clocks used by calling "test" "count2 times
uint64_t BenchMark(void (*test)(void), uint64_t count);

uint64_t BenchMarkClock(void (*test)(void), uint64_t count);

#ifdef __cplusplus
	}
}
#endif

#endif
