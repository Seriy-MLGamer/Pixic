#pragma once

#include <Pixic/core/Var.h>

extern void (*set_element)(Var *pixi, Var *x, Var *value);
extern void (*set_element2)(Var *pixi, Var *x, Var *y, Var *value);
extern Var (*get_element)(Var *pixi, Var *x);
extern Var (*get_element2)(Var *pixi, Var *x, Var *y);

extern Var
	pcINT8,
	pcINT16,
	pcINT32,
	#ifdef X64
	pcINT64,
	#endif
	pcFLOAT32;
#ifdef X64
extern Var pcFLOAT64;
#endif
#ifdef X32
#define pcINT pcINT32
#define pcFLOAT pcFLOAT32
#endif
#ifdef X64
#define pcINT pcINT64
#define pcFLOAT pcFLOAT64
#endif
#define pcPIXEL pcINT32

extern Var (*pfnew)(unsigned argument_count, ...);
extern Var (*pfremove)(unsigned argument_count, ...);