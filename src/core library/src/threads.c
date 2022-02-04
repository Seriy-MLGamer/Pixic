#include "Pixic/core library/threads.h"

#include "configuration.h"

#include "stdlib.h"

#ifdef OS_Windows
	#include "processthreadsapi.h"
	#include "handleapi.h"
	#include "synchapi.h"

	Thread Thread_new(void (*function)(void *arguments), void *arguments)
	{
		return CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)function, arguments, 0, NULL);
	}
	bool Thread_delete(Thread thread)
	{
		return CloseHandle(thread);
	}
	Mutex Mutex_new()
	{
		LPCRITICAL_SECTION result=malloc(sizeof(CRITICAL_SECTION));
		if (!result) return NULL;
		InitializeCriticalSection(result);
		return result;
	}
	void Mutex_lock(Mutex mutex)
	{
		EnterCriticalSection(mutex);
	}
	bool Mutex_trylock(Mutex mutex)
	{
		return TryEnterCriticalSection(mutex);
	}
	void Mutex_unlock(Mutex mutex)
	{
		LeaveCriticalSection(mutex);
	}
	void Mutex_delete(Mutex mutex)
	{
		DeleteCriticalSection(mutex);
		free(mutex);
	}
	void sleep(unsigned long milliseconds)
	{
		Sleep(milliseconds);
	}
#else
	#include "stdio.h"
	#include "pthread.h"

	Thread Thread_new(void (*function)(void *arguments), void *arguments)
	{
		pthread_t *result=malloc(sizeof(pthread_t));
		if (!result) return NULL;
		if (pthread_create(result, NULL, (void *(*)(void *))function, arguments))
		{
			free(result);
			return NULL;
		}
		return result;
	}
	bool Thread_delete(Thread thread)
	{
		bool result=!pthread_cancel(*(pthread_t *)thread);
		free(thread);
		return result;
	}
	Mutex Mutex_new()
	{
		pthread_mutex_t *result=malloc(sizeof(pthread_mutex_t));
		if (!result) return NULL;
		pthread_mutex_init(result, NULL);
		return result;
	}
	void Mutex_lock(Mutex mutex)
	{
		pthread_mutex_lock(mutex);
	}
	bool Mutex_trylock(Mutex mutex)
	{
		return !pthread_mutex_trylock(mutex);
	}
	void Mutex_unlock(Mutex mutex)
	{
		pthread_mutex_unlock(mutex);
	}
	void Mutex_delete(Mutex mutex)
	{
		pthread_mutex_destroy(mutex);
		free(mutex);
	}
	void sleep(unsigned long milliseconds)
	{
		struct timespec delay={milliseconds/1000, milliseconds%1000*1000000};
		pthread_delay_np(&delay);
	}
#endif