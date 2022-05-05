#pragma once

#include <Pixic/core/typedefs/variable/Var.h>
#include <Pixic/core library/C OOP.h>

#include <Pixic/core/typedefs/variable/Var_null.h>
#include <Pixic/core/typedefs/variable/Var_int.h>
#include <Pixic/core/typedefs/variable/Var_float.h>
#include <Pixic/core/typedefs/variable/Arithmetical.h>
#include <Pixic/core/typedefs/Int.h>
#include <Pixic/core/typedefs/Float.h>

struct Var
{
	Object;
};
struct Var_f
{
	void
		(*set)(void *self, Var *rvalue),
		(*set2)(void *self, Var_null *lvalue),
		(*set3)(void *self, Var_int *lvalue),
		(*set4)(void *self, Var_float *lvalue);
	Arithmetical
		(*op_mod)(void *self, Var *roperand),
		(*op_mod2)(void *self, Var_int *loperand),
		(*op_mod3)(void *self, Var_float *loperand),
		(*op_div)(void *self, Var *roperand),
		(*op_div2)(void *self, Var_int *loperand),
		(*op_div3)(void *self, Var_float *loperand),
		(*op_idiv)(void *self, Var *roperand),
		(*op_idiv2)(void *self, Var_int *loperand),
		(*op_idiv3)(void *self, Var_float *loperand),
		(*op_mul)(void *self, Var *roperand),
		(*op_mul2)(void *self, Var_int *loperand),
		(*op_mul3)(void *self, Var_float *loperand),
		(*op_not)(void *self),
		(*op_bnot)(void *self),
		(*op_add)(void *self, Var *roperand),
		(*op_add2)(void *self, Var_int *loperand),
		(*op_add3)(void *self, Var_float *loperand),
		(*op_neg)(void *self),
		(*op_sub)(void *self, Var *roperand),
		(*op_sub2)(void *self, Var_int *loperand),
		(*op_sub3)(void *self, Var_float *loperand),
		(*op_rsh)(void *self, Var *roperand),
		(*op_rsh2)(void *self, Var_int *loperand),
		(*op_rsh3)(void *self, Var_float *loperand),
		(*op_lsh)(void *self, Var *roperand),
		(*op_lsh2)(void *self, Var_int *loperand),
		(*op_lsh3)(void *self, Var_float *loperand),
		(*op_eq)(void *self, Var *roperand),
		(*op_eq2)(void *self, Var_int *loperand),
		(*op_eq3)(void *self, Var_float *loperand),
		(*op_neq)(void *self, Var *roperand),
		(*op_neq2)(void *self, Var_int *loperand),
		(*op_neq3)(void *self, Var_float *loperand),
		(*op_less)(void *self, Var *roperand),
		(*op_less2)(void *self, Var_int *loperand),
		(*op_less3)(void *self, Var_float *loperand),
		(*op_great)(void *self, Var *roperand),
		(*op_great2)(void *self, Var_int *loperand),
		(*op_great3)(void *self, Var_float *loperand),
		(*op_leq)(void *self, Var *roperand),
		(*op_leq2)(void *self, Var_int *loperand),
		(*op_leq3)(void *self, Var_float *loperand),
		(*op_geq)(void *self, Var *roperand),
		(*op_geq2)(void *self, Var_int *loperand),
		(*op_geq3)(void *self, Var_float *loperand),
		(*op_bor)(void *self, Var *roperand),
		(*op_bor2)(void *self, Var_int *loperand),
		(*op_bor3)(void *self, Var_float *loperand),
		(*op_bxor)(void *self, Var *roperand),
		(*op_bxor2)(void *self, Var_int *loperand),
		(*op_bxor3)(void *self, Var_float *loperand),
		(*op_band)(void *self, Var *roperand),
		(*op_band2)(void *self, Var_int *loperand),
		(*op_band3)(void *self, Var_float *loperand),
		(*op_or)(void *self, Var *roperand),
		(*op_or2)(void *self, Var_int *loperand),
		(*op_or3)(void *self, Var_float *loperand),
		(*op_and)(void *self, Var *roperand),
		(*op_and2)(void *self, Var_int *loperand),
		(*op_and3)(void *self, Var_float *loperand);
	Int (*to_int)(void *self);
	Float (*to_float)(void *self);
};