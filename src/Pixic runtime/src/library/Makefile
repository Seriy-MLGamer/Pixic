compile=gcc -o "$@" -c "$<" -O -s -I include -I ../../include -I ../../../.. -I ../../../../include
all: main.o test.o Pixic.o Safe\ memory.o containers.o core.o
	gcc -o test main.o test.o Pixic.o "Safe memory.o" containers.o core.o -O -s
main.o: src/static\ library/src/main.c
	$(compile)
test.o: test.c
	$(compile)
Pixic.o: src/library\ core/src/Pixic.c
	$(compile)
Safe\ memory.o: ../../../core\ library/src/Safe\ memory.c
	$(compile)
containers.o: src/library\ core/src/containers.c
	$(compile)
core.o: src/library\ core/src/core/core.c
	$(compile)