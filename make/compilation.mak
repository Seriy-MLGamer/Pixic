#Dependencies.
#core.mak

ifeq ($(operating_system), Windows)
	ifeq ($(architecture), x86)
		arch_root=i686-w64-mingw32
	endif
	ifeq ($(architecture), x86_64)
		arch_root=x86_64-w64-mingw32
	endif
endif
ifeq ($(operating_system), Linux)
	ifeq ($(architecture), x86)
		arch_root=i386-linux-gnu
	endif
	ifeq ($(architecture), x86_64)
		arch_root=x86_64-linux-gnu
	endif
endif
bin=./$(root)/bin/$(arch_root)
obj=./$(root)/obj/$(arch_root)
lib=./$(root)/lib/$(arch_root)
configuration=./$(root)/configuration.h

compilation_flags=$(specific_flags) $(optimizators) $(include_path) $(cflags)
link_flags=$(lib_path) $(libs) $(ldflags)

specific_flags=-std=c11 -fms-extensions
ifeq ($(architecture), x86)
	ifeq ($(operating_system), Windows)
		specific_flags+=-march=i686
	endif
	ifeq ($(operating_system), Linux)
		specific_flags+=-march=i386
	endif
endif
ifeq ($(architecture), x86_64)
	specific_flags+=-m64
endif
optimizators=-O3 -s
include_path=$(system_include_path) $(user_include_path)
system_include_path=-I "./$(root)/include" -I include
lib_path=$(system_lib_path) $(user_lib_path)
system_lib_path=-L "$(lib)"

compile=gcc -o "$@" -c "$<" $(compilation_flags)

$(bin) $(obj) $(lib):
	mkdir -p "$@"