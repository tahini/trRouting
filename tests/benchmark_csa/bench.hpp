#ifndef TR_BENCH
#define TR_BENCH

#include <sys/time.h>
#include <sys/resource.h>

/**
 * Get the current time, in microseconds precision 
 */
long long get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec * 1e6 + t.tv_usec;
}

#endif // TR_BENCH