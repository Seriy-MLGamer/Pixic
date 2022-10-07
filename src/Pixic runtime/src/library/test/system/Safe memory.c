#include <stdio.h>
#include <system/C OOP.h>

int main()
{
	safe_memory_init();
	int *a=new(int, 4);
	float *b=new(float, 8);
	char *c=new(char, 64);
	long long *d=new(long long, 1);
	safe_free(b);
	fwrite(c, 1, 64, stdout);
	putchar('\n');
	safe_clean(c);
	fwrite(c, 1, 64, stdout);
	putchar('\n');
	//safe_free(a);
	//safe_free(c);
	resize(d, 48);
	resize(d, 2);
	printf("Allocated: %llu bytes.\n", memory_allocated);
	safe_memory_deinit(true);
	for (size_t a=0; a!=not_freed_size; a++) printf("\"%s\": %llu\n", not_freed[a].name, not_freed[a].size);
	printf("Max allocated: %llu bytes.\n", max_memory_allocated);
}