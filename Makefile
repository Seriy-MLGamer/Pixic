cflags=-O3 -s
src=src/Pixic
begin=gcc $(cflags) -I$(src)/include -c $(src)
build:
	if cd obj; then cd ..; else mkdir obj; fi
	$(begin)/Pixic.c++ -o obj/Pixic.o
	$(begin)/src/classes/Parsing.c++ -o obj/Parsing.o
	$(begin)/src/classes/UTF-8/UTF8_file.c++ -o obj/UTF8_file.o
	if cd bin; then cd ..; else mkdir bin; fi
	cd obj; g++ $(cflags) -static -o ../bin/Pixic\
		Pixic.o\
		Parsing.o\
		UTF8_file.o\
		UTF8_exception.o
test:
	if cd obj; then cd ..; else mkdir obj; fi
	$(begin)/Test.c++ -o obj/Test.o
	$(begin)/src/algorithms.c++ -o obj/algorithms.o
	$(begin)/src/classes/UTF-8/UTF8_file.c++ -o obj/UTF8_file.o
	$(begin)/src/classes/UTF-8/UTF8_exception.c++ -o obj/UTF8_exception.o
	if cd bin; then cd ..; else mkdir bin; fi
	cd obj; g++ $(cflags) -o ../bin/UTF-8\
		Test.o\
		algorithms.o\
		UTF8_file.o\
		UTF8_exception.o