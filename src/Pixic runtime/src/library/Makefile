compile=gcc -o "$@" -c "$<" -O -s -I include -I ../.. -I ../../include -I ../../../../out/pixic/src/include
all: main.o test.o Pixic.o Safe\ memory.o containers.o core.o
	gcc -o main main.o test.o Pixic.o "Safe memory.o" containers.o core.o -O -s
main.o: src/static\ library/main.c
	$(compile)
test.o: test.c
	$(compile)
Pixic.o: src/Pixic.c
	$(compile)
Safe\ memory.o: src/system/Safe\ memory.c
	$(compile)
containers.o: src/containers.c
	$(compile)
core.o: src/core/core.c
	$(compile)