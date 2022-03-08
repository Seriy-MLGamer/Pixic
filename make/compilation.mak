ifeq ($(operating_system), Windows)
	ifeq ($(architecture), x86)
		arch_root=$(root)/i686-w64-mingw32
	endif
	ifeq ($(architecture), x86_64)
		arch_root=$(root)/x86_64-w64-mingw32
	endif
endif
ifeq ($(operating_system), Linux)
	ifeq ($(architecture), x86)
		arch_root=$(root)/i386-linux-gnu
	endif
	ifeq ($(architecture), x86_64)
		arch_root=$(root)/x86_64-linux-gnu
	endif
endif
bin=$(arch_root)/bin
obj=$(arch_root)/obj
lib=$(arch_root)/lib
configuration=$(root)/configuration.h

compilation_flags=$(specific_flags) $(optimizators) $(include_path) $(cflags)
optimizators=-O3 -s
ifeq ($(architecture), x86)
	ifeq ($(operating_system), Windows)
		specific_flags=-march=i686
	endif
	ifeq ($(operating_system), Linux)
		specific_flags=-march=i386
	endif
endif
ifeq ($(architecture), x86_64)
	specific_flags=-m64
endif
linkage_flags=$(lib_path) $(libs) $(ldflags)

make_configuration=$(root)/configuration.sh $(root) x32 $(operating_system);\
	make compile
compile=gcc -c -o $@ $< $(compilation_flags)

$(bin):
	mkdir $@
$(obj):
	mkdir $@
$(lib):
	mkdir $@