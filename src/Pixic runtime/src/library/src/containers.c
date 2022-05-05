#include <Pixic/containers.h>

#include <stdarg.h>
#include <stdio.h>
#include <Pixic/core/container/Container.h>
#include <Pixic/core/variable/Arithmetical.h>

enum Container_type
{
	INT8,
	INT16,
	INT32,
	#ifdef X64
	INT64,
	#endif
	FLOAT32,
	#ifdef X64
	FLOAT64,
	#endif

	type_count
};

Container **containers=NULL;
size_t
	max_container_count=8192,
	container_count=0,
	container_pointer=0;

static Arithmetical ipfnew(unsigned long argument_count, ...)
{
	va_list arguments;
	va_start(arguments, argument_count);
	Int width;
	if (argument_count>=1)
	{
		Arithmetical pixi_width=va_arg(arguments, Arithmetical);
		width=((Var_f)pixi_width.n.f)->to_Int(&pixi_width);
		if (width<1) return (Arithmetical)Var_int_new(-1);
	}
	else width=1;
	Int height;
	if (argument_count>=2)
	{
		Arithmetical pixi_height=va_arg(arguments, Arithmetical);
		height=((Var_f)pixi_height.n.f)->to_Int(&pixi_height);
		if (height<1) return (Arithmetical)Var_int_new(-1);
	}
	else height=1;
	Int type;
	if (argument_count>=3)
	{
		Arithmetical pixi_type=va_arg(arguments, Arithmetical);
		type=((Var_f)pixi_type.n.f)->to_Int(&pixi_type);
		if ((unsigned)type<0||type>=type_count) return (Arithmetical)Var_int_new(-1);
	}
	else type=pcPIXEL.value;
	if (container_count==max_container_count) return (Arithmetical)Var_int_new(-1);
	while (containers[container_pointer]!=NULL) container_pointer=(container_pointer+1)%max_container_count;
	switch (type)
	{
		case INT8:
		break;
	}
	va_end(arguments);
}

Arithmetical (*pfnew)(unsigned long argument_count, ...)=ipfnew;