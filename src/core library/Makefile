root=../..

include $(root)/make/core.mak
include $(root)/make/compilation.mak
include $(root)/make/clean.mak

include_path=\
	-I$(root)\
	-I$(root)/include
lib_path=-L$(lib)
libs=-lcorelib
ifneq ($(operating_system), Windows)
	libs+=-lpthread
endif

compile:\
	$(obj)/threads.o\
$(lib)
	ar -r -s $(lib)/libcorelib.a\
		$(obj)/threads.o
$(obj)/threads.o: threads.c $(configuration) $(obj)
	$(compile)

test: test.c
	gcc -o $@ $< $(compilation_flags) $(linkage_flags)
	./test

clean:
	if ! rm $(lib)/libthreads.a; then cd .; fi
	if ! rm $(obj)/threads.o; then cd .; fi
	if ! rm test; then cd .; fi
	$(clean_folders)