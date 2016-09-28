#include <stdint.h>

/*It use the 4byte*/

int clz( uint32_t x) {
	return x ? clz( x >> 1) - 1 : 32;
}
