#ifndef ALIGN_ASM_H
#define ALIGN_ASM_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

void* Align(void* p, uint32_t arign_size);

#ifdef __cplusplus
}

template <typename Type, uint32_t AlignSize>
class AlignedArray
{
public:
	AlignedArray(uint32_t size)
	{
		 p = new Type[size + AlignSize/sizeof(Type) + 1];
       		 align_p = (Type*)Align((void*)p, AlignSize);
	}

	~AlignedArray()
	{
		delete [] p;
	}

	Type& operator[](uint32_t index)
	{
		return align_p[index];
	}
protected:
private:
	Type *p;
	Type *align_p;
};

#endif

#endif
