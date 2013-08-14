#include "CharacterInteger.h"

namespace zarath
{
	CharacterInteger::CharacterInteger(int num)
	{
		int temp = num, c = 1;
		while(temp /= 10)
			c++;
		data = new char[len = c];
		c = 0;

		for(int i = 0; i < len; ++i, num /= 10)
			data[i] = '0' + (num % 10);
	}

	CharacterInteger::CharacterInteger(const char *num)
	{
		int c = -1;
		while(num[++c] != '\0');

		data = new char[len = c];

		for(int i = 0; i < len; ++i)
			data[i] = num[len - 1 - i];
	}

	CharacterInteger::~CharacterInteger()
	{
		delete data;
	}

	char &CharacterInteger::operator[](uint32_t index) const
	{
		static char dammy = 0;
		dammy = 0;
		return (index >= 0 && index <= len)?(data[index]):(dammy);
	}

	std::ostream &operator<<(std::ostream &dest, const CharacterInteger &num)
	{
		for(int i = num.Length() - 1; i >= 0; --i)
			dest << num[i];
		return dest;
	}

}
