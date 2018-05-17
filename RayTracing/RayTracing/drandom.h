#ifndef _DRANDOM_H_  
#define _DRANDOM_H_  

#include <stdlib.h>  

#define RAND_M 0x100000000LL  
#define RAND_C 0xB16  
#define RAND_A 0x5DEECE66DLL  

static unsigned long long RAND_SEED = 1;

double drand48(void)
{
	RAND_SEED = (RAND_A * RAND_SEED + RAND_C) & 0xFFFFFFFFFFFFLL;
	unsigned int x = RAND_SEED >> 16;
	return  ((double)x / (double)RAND_M);

}

void srand48(unsigned int i)
{
	RAND_SEED = (((long long int)i) << 16) | rand();
}

#endif 