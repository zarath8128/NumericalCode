#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include <cstdint>

template<class BufferType, uint32_t BufferNum>
class BufferManager
{
public:
	BufferType *buffer[BufferNum];

	BufferManager()
	{
		for(int i = 0; i < BufferNum; ++i)
			buffer[i] = nullptr;
	}

	BufferManager(const BufferType initial[])
	{
		for(int i = 0; i < BufferNum; ++i)
			buffer[i] = new BufferType(initial[i]);
	}

	~BufferManager()
	{
		for(int i = 0; i < BufferNum; ++i)
			delete buffer[i];
	}

	void swap(uint64_t i, uint64_t j)
	{
		BufferType *t = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = t;
	}

	void reverse()
	{
		BufferType *t = buffer[0];
		for(int i = 0; i < BufferNum - 1; ++i)
			buffer[i] = buffer[i+1];
		buffer[BufferNum - 1] = t;
	}
	
	void rotate()
	{
		BufferType *t = buffer[BufferNum - 1];
		for(int i = BufferNum - 1; 0 < i; --i)
			buffer[i] = buffer[i - 1];
		buffer[0] = t;
	}
	
<<<<<<< HEAD
	void initialize(const BufferType initial[])
	{
		
	}
	
=======
>>>>>>> 13d816d7697f2d6430cc54c72c38e86de0ed8422
	const BufferType& operator[](uint32_t index)
	{
		return *buffer[index];
	}
protected:
private:
};


#endif
