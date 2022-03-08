include_path=-I include -I ../../../.. -I ../../../../include
ifeq ($(module), core/variable)
    ifeq ($(lang), C)
        test: bin/variable
			$<
        bin/variable: obj/variable.o obj/Var_null.o obj/Var_int.o obj/Var_float.o bin
			gcc -o $@ obj/variable.o obj/Var_null.o obj/Var_int.o obj/Var_float.o
        obj/variable.o: test/$(module)/variable.c obj
			gcc -c -o $@ $< $(include_path) -O
        obj/Var_null.o: src/$(module)/Var_null.c obj
			gcc -c -o $@ $< $(include_path) -O
        obj/Var_int.o: src/$(module)/Var_int.c obj
			gcc -c -o $@ $< $(include_path) -O
        obj/Var_float.o: src/$(module)/Var_float.c obj
			gcc -c -o $@ $< $(include_path) -O
        bin obj:
			mkdir $@
    endif
    ifeq ($(lang), Pixilang)
        test: test/$(module)/variable.pixi
			pixilang_console $<
    endif
endif