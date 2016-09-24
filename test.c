#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "clz.h"

#define ASSERT_CLZ( x, znum) assert( clz( x) == znum && #x " clz != " #znum "\n")

int main( int argc, char** argv)
{
	for( int i = 0; i < 32; i++){
		int in = 1 << i, ans = 31 -i;
		ASSERT_CLZ( in, ans);
	}
		
}
