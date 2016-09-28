#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

int clz( uint32_t x);

static void inline
prtHex( uint32_t x)
{
	printf("%u = 0x%08x\n", x, x);
}

static void inline
prtBinary( uint32_t x)
{
	//FIXME:gun99 not define it
	/*static char buff[33];
	itoa( x, buff, 2);
	printf("%u = %s\n", x, buff);*/

	printf("%u = ", x);
	for( int i = 0; i < sizeof( x) * 8; i++)
		printf("%d", (x & (0x80000000 >> i)) != 0 ? 1: 0 );
		//FIXME:why isn't correct//printf("%d", (x & ( (1 << 31) >> i)) != 0 ? 1: 0 );
	printf("\n");
}
