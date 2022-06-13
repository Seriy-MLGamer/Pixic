#include <Pixic.h>

#include <stdlib.h>
#include <Pixic/core library/Safe memory.h>
#include <containers.h>

inline int Pixic_init()
{
	if (safe_memory_init()) return 1;
	if (containers_init()) return 2;
	return 0;
}
inline void Pixic_deinit()
{
	containers_deinit();
	safe_memory_deinit(true);
	if (not_freed)
	{
		printf("I should free these memory blocks, but I didn't.\n\n");
		size_t sum=0;
		for (size_t a=0; a!=not_freed_size; a++)
		{
			Memory_data *data=not_freed+a;
			printf("%s: %lu\n", data->name, data->size);
			sum+=data->size;
		}
		if (sum==memory_allocated) printf("\n%lu bytes was not freed!\n", sum);
		else printf("\nError in safe memory: sum (%lu bytes) != memory_allocated (%lu bytes).\n", sum, memory_allocated);
		free(not_freed);
	}
}
static int iPixic(void (*main)())
{
	if (Pixic_init()) return 1;
	main();
	Pixic_deinit();
	return 0;
}

int (*Pixic)(void (*main)())=iPixic;