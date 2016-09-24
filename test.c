#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "clz.h"

#define ASSERT_CLZ( x, znum) assert( clz( x) == znum && #x " clz != " #znum "\n")

int main( int argc, char** argv)
{

	//assert( clz( 0x00123456) == 8 && "0x00123456 clz error\n");
	/*ASSERT_CLZ( 0xFFFFFFFF, 0);
	ASSERT_CLZ( 0x7FFFFFFF, 1);
	ASSERT_CLZ( 0x3FFFFFFF, 2);
	ASSERT_CLZ( 0x1FFFFFFF, 3);
	ASSERT_CLZ( 0x0FFFFFFF, 4);
	ASSERT_CLZ( 0x07FFFFFF, 5);
	ASSERT_CLZ( 0x03FFFFFF, 6);
	ASSERT_CLZ( 0x01FFFFFF, 7);
	ASSERT_CLZ( 0x00FFFFFF, 8);
	ASSERT_CLZ( 0x007FFFFF, 9);
	ASSERT_CLZ( 0x003FFFFF,10);
	ASSERT_CLZ( 0x001FFFFF,11);
	ASSERT_CLZ( 0x000FFFFF,12);
	ASSERT_CLZ( 0x0007FFFF,13);
	ASSERT_CLZ( 0x0003FFFF,14);
	ASSERT_CLZ( 0x0001FFFF,15);
	ASSERT_CLZ( 0x0000FFFF, 16);*/

	/*ASSERT_CLZ( 0, 32);
	ASSERT_CLZ( 1, 31);
	ASSERT_CLZ( 2, 30);
	ASSERT_CLZ( 4, 29);*/
	for( int i = 0; i < 32; i++){
		int in = 1 << i, ans = 31 -i;
		//printf("in = %d, ans = %d", in, ans);
		ASSERT_CLZ( in, ans);
		//assert( clz( in) == ans);
	}
		
}
