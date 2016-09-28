#include <stdio.h>
#include <stdint.h>

#include "clz.h"

/**
 * reference "int nlz10a":
 * http://www.hackersdelight.org/hdcodetxt/nlz.c.txt
 */

int clz( uint32_t x)
{
		// "0xFF" will represent no use element
    static uint8_t const Table[] = {
			32, 31, 0xFF, 16, 0xFF, 30, 3, 0xFF,
			15, 0xFF, 0xFF, 0xFF, 29, 10, 2, 0xFF,
			0xFF, 0xFF, 12, 14, 21, 0xFF, 19, 0xFF,
			0xFF, 28, 0xFF, 25, 0xFF, 9, 1, 0xFF,
			17, 0xFF, 4, 0xFF, 0xFF, 0xFF, 11, 0xFF,
			13, 22, 20, 0xFF, 26, 0xFF, 0xFF, 18,
			5, 0xFF, 0xFF, 23, 0xFF, 27, 0xFF, 6,
			0xFF, 24, 7, 0xFF, 8, 0xFF, 0, 0xFF,
		};

		/* Propagate leftmost 1-bit to the right */
		printf("Propagate leftmost 1-bit to the right\n");
		prtBinary( x);
		x = x | (x >> 1);
		prtBinary( x);
		x = x | (x >> 2);
		prtBinary( x);
		x = x | (x >> 4);
		prtBinary( x);
		x = x | (x >> 8);
		prtBinary( x);
		x = x | (x >> 16);
		prtBinary( x);

		/* x = x * 0x6EB14F9 */
		printf("x = x * 0x6EB14F9\n");
		x = (x << 3) - x;   /* Multiply by 7. */
		prtBinary( x);
		x = (x << 8) - x;   /* Multiply by 255. */
		prtBinary( x);
		x = (x << 8) - x;   /* Again. */
		prtBinary( x);
		x = (x << 8) - x;   /* Again. */
		prtBinary( x);
		
		printf("table index = %d\n",  x >> 26);
		printf("clz = %d\n", Table[ x >> 26]);
		return Table[x >> 26];
}
