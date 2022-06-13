#include <main.h>

#include <Pixic.h>

int main()
{
	#ifdef OS_WINDOWS
	library=LoadLibraryA("libPixic");
	Pixic=(int (*)(void (*)()))GetProcAddress(library, "Pixic");
	Pixic(app);
	FreeLibrary(library);
	#endif
	#ifdef OS_LINUX
	library=dlopen("Pixic", RTLD);
	Pixic=(int (*)(void (*)()))dlsym()
	#endif
}