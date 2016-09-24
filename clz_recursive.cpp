#include <iostream>
#include <stdint.h>

int clz(uint32_t x)
{
	// shift upper half down, rest is filled up with 0s
	uint16_t upper = (x >> 16); 
	// mask upper half away
	auto lower = std::uint16_t(x & 0xFFFF);
	// their type is std::uint16_t so a smaller overload is chosen
	return upper ? clz(upper) : 16 + clz(lower);
}
