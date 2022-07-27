all: test.o Safe\ memory.o Hash_map.o hash.o Tree_map.o
	gcc -o test test.o "Safe memory.o" Hash_map.o hash.o Tree_map.o -O
test.o: test.c
	gcc -c "$<" -O -I include -I ../../../../../../include -fms-extensions
Safe\ memory.o: ../../../../../core\ library/src/Safe\ memory.c
	gcc -c "$<" -O -I include -I ../../../../../../include -fms-extensions
Hash_map.o: src/hash\ table/Hash_map.c
	gcc -c "$<" -O -I include -I ../../../../../../include -fms-extensions
hash.o: src/hash\ table/system/hash.c
	gcc -c "$<" -O -I include -I ../../../../../../include -fms-extensions
Tree_map.o: src/my\ own/Tree_map.c
	gcc -c "$<" -O -I include -I ../../../../../../include -fms-extensions