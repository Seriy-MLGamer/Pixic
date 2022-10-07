#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <hash table/Hash_map.h>
#include <my own/Tree_map.h>
#include <system/C OOP.h>

#define pair_count 7
#define iterations 1000000

inline int rand_range(int min, int max)
{
	return min+
	#if RAND_MAX>=1<<16
	(int64_t)(max-min)*rand()/((int64_t)RAND_MAX+1);
	#else
	(int32_t)(max-min)*rand()/((int32_t)RAND_MAX+1);
	#endif
}
struct pair
{
	char *key;
	char *value;
	Hash hash;
};
int main()
{
	safe_memory_init();

	Hash_map map=Hash_map_new();

	struct pair pairs[pair_count];
	printf("List of pairs.\n");
	for (int a=0; a!=pair_count; a++)
	{
		int key_length=8;//rand_range(4, 17);
		int value_length=rand_range(16, 65);
		char *key=new_array(char, key_length+1);
		char *value=new_array(char, value_length+1);
		key[key_length]=0;
		value[value_length]=0;
		for (int a=0; a!=key_length; a++) key[a]=rand_range('a', 'z'+1);
		for (int a=0; a!=value_length; a++) value[a]=rand_range('a', 'z'+1);
		pairs[a]=(struct pair){key, value, hash(key)};
		printf("  %s: %s\n", key, value);
	}
	clock_t start=clock();
	for (int a=0; a!=iterations; a++) for (int a=0; a!=pair_count; a++) Hash_map_set2(&map, pairs[a].hash, pairs[a].value);
	printf("\nset(): %i ms\n", (int)((clock()-start)*1000/CLOCKS_PER_SEC));
	//Раскомментируйте строку ниже, чтобы переполнить консоль.
	//Hash_map_show(&map);
	struct pair randomized_pairs[pair_count];
	memset(randomized_pairs, 0, sizeof randomized_pairs);
	int a=0;
	while (a!=pair_count)
	{
		int position=rand_range(0, pair_count);
		if (!randomized_pairs[position].key)
		{
			randomized_pairs[position]=pairs[a];
			a++;
		}
	}
	start=clock();
	for (int b=0; b!=iterations; b++)
	{
		for (a=0; a!=pair_count; a++) if (Hash_map_get2(&map, randomized_pairs[a].hash)!=randomized_pairs[a].value) break;
		if (a!=pair_count) break;
	}
	printf("get(): ");
	if (a!=pair_count) printf("failed\n");
	else printf("%i ms\n", (int)((clock()-start)*1000/CLOCKS_PER_SEC));
	for (int a=0; a!=pair_count; a++)
	{
		delete(pairs[a].key);
		delete(pairs[a].value);
	}
	safe_memory_deinit(true);
	if (not_freed)
	{
		printf("\n%zu blocks of %zu bytes was allocated.\n", not_freed_size, memory_allocated);
		free(not_freed);
	}
	return 0;
}