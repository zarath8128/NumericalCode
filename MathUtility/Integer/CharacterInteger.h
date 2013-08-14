#ifndef ZARATH_CHARACTER_INTEGER_H
#define ZARATH_CHARACTER_INTEGER_H

#include<cstdint>
#include<iostream>

namespace zarath
{
	class CharacterInteger
	{
	public:
		CharacterInteger(int num);
		CharacterInteger(const char *num);
		~CharacterInteger();

		char &operator[](uint32_t index) const;
		const uint32_t &Length() const{return len;}
	protected:
	private:
		char *data;
		uint32_t len;
	};

	std::ostream &operator<<(std::ostream &dest, const CharacterInteger &num);
}

#endif
