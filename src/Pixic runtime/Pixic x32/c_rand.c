#include "time.h"
#include "stdio.h"

#define RAND_MAX 32767
static long next=1;

int c_rand()
{
	next=next*1103515245+12345;
	return (next/65536)%(RAND_MAX+1);
}

int main()
{
	short array[1000000];
	clock_t start=clock();
	size_t a=0;
	while (a!=1000000)
	{
		array[a]=c_rand();
		a++;
	}
	printf("%lu ms\n", clock()-start);
	a=999999;
	while (a!=999989)
	{
		printf("%hi\n", array[a]);
		a--;
	}
}