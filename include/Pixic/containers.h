#pragma once

#include <Pixic/core/typedefs/variable/Var_int.h>
#include <Pixic/core/typedefs/variable/Arithmetical.h>

extern Var_int pсINT8;
extern Var_int pсINT16;
extern Var_int pсINT32;
extern Var_int pcFLOAT32;
extern Var_int pcINT64;
extern Var_int pcFLOAT64;
extern Var_int pcINT;
extern Var_int pcFLOAT;
extern Var_int pcPIXEL;

extern Var_int pcCFLAG_INTERP;
extern Var_int pcGL_MIN_LINEAR;
extern Var_int pcGL_MAG_LINEAR;
extern Var_int pcGL_NICEST;
extern Var_int pcGL_NO_XREPEAT;
extern Var_int pcGL_NO_YREPEAT;
extern Var_int pcGL_NO_ALPHA;

extern Var_int pcRESIZE_INTERP1;
extern Var_int pcRESIZE_INTERP2;
extern Var_int pcRESIZE_UNSIGNED_INTERP2;
extern Var_int pcRESIZE_COLOR_INTERP1;
extern Var_int pcRESIZE_COLOR_INTERP2;

extern Var_int pcCOPY_NO_AUTOROTATE;
extern Var_int pcCOPY_CLIPPING;

extern Var_int pcZ_NO_COMPRESSION;
extern Var_int pcZ_BEST_SPEED;
extern Var_int pcZ_BEST_COMPRESSION;
extern Var_int pcZ_DEFAULT_COMPRESSION;

extern Arithmetical (*pfnew)(unsigned long argument_count, ...);
extern Arithmetical (*pfremove)(unsigned long argument_count, ...);