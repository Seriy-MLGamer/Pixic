#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "Pixic/core library/threads.h"

#define count 10
#define length 64
char array[length];
Mutex array_mutex;
Thread a, b;
bool
	delete_request=false,
	delete_response=false;

void hatsune(void *arguments)
{
	sleep(2000);
	delete_request=true;
	while (!delete_response) sleep(10);
	printf("Thread \"b\" returned %i.\n\n", Thread_delete(b));
}
void miku(void *arguments)
{
	while (true)
	{
		if (delete_request&&*(char *)arguments=='B')
		{
			delete_response=true;
			return;
		}
		char filled[count];
		Mutex_lock(array_mutex);
		memset(array, ' ', length);
		for (char a=0; a!=count; a++)
		{
			char index=rand()*length/(RAND_MAX+1);
			while (true)
			{
				char b;
				for (b=0; b!=a; b++) if (index==filled[b])
				{
					index=rand()*length/(RAND_MAX+1);
					break;
				}
				if (a==b) break;
			}
			array[index]=*(char *)arguments;
			filled[a]=index;
		}
		Mutex_unlock(array_mutex);
		//sleep(1);
	}
}

int main()
{
	array_mutex=Mutex_new();
	a=Thread_new(miku, "A");
	b=Thread_new(miku, "B");
	Thread c=Thread_new(hatsune, b);
	while (true)
	{
		Mutex_lock(array_mutex);
		fwrite(array, 1, length, stdout);
		Mutex_unlock(array_mutex);
		putchar('\n');
		sleep(10);
	}
}