#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>

#include "clz.h"

#ifndef VERSION
	#define VERSION "Not specify"
#endif

#define ASSERT_CLZ( x, znum) assert( clz( x) == znum && #x " clz != " #znum)

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}


int main( int argc, char** argv)
{
	struct timespec start, end;
	double cpu_time;


	clock_gettime( CLOCK_REALTIME, &start);

	for( int j = 0; j <1000 ; j++){
		ASSERT_CLZ( 0, 32);
		for( int i = 0; i < 32; i++)
			ASSERT_CLZ( 1 << i, 31 -i);
	}

	clock_gettime( CLOCK_REALTIME, &end);

	cpu_time = diff_in_second( start, end);

	printf("execution time of " VERSION " %lf sec\n", cpu_time);

	return 0;
}
