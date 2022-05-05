#pragma once

#include <Pixic/core/typedefs/variable/Var_int.h>
#include <Pixic/core/variable/Var.h>

struct Var_int
{
	Var;

	Int value;
};
extern void
	(*Var_int_set)(Var_int *self, Var *rvalue),
	(*Var_int_set2)(Var_int *self, Var_null *lvalue),
	(*Var_int_set3)(Var_int *self, Var_int *lvalue),
	(*Var_int_set4)(Var_int *self, Var_float *lvalue);
extern Arithmetical
	(*Var_int_op_mod)(Var_int *self, Var *roperand),
	(*Var_int_op_mod2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_mod3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_div)(Var_int *self, Var *roperand),
	(*Var_int_op_div2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_div3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_idiv)(Var_int *self, Var *roperand),
	(*Var_int_op_idiv2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_idiv3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_mul)(Var_int *self, Var *roperand),
	(*Var_int_op_mul2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_mul3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_not)(Var_int *self),
	(*Var_int_op_bnot)(Var_int *self),
	(*Var_int_op_add)(Var_int *self, Var *roperand),
	(*Var_int_op_add2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_add3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_neg)(Var_int *self),
	(*Var_int_op_sub)(Var_int *self, Var *roperand),
	(*Var_int_op_sub2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_sub3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_rsh)(Var_int *self, Var *roperand),
	(*Var_int_op_rsh2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_rsh3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_lsh)(Var_int *self, Var *roperand),
	(*Var_int_op_lsh2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_lsh3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_eq)(Var_int *self, Var *roperand),
	(*Var_int_op_eq2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_eq3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_neq)(Var_int *self, Var *roperand),
	(*Var_int_op_neq2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_neq3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_less)(Var_int *self, Var *roperand),
	(*Var_int_op_less2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_less3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_great)(Var_int *self, Var *roperand),
	(*Var_int_op_great2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_great3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_leq)(Var_int *self, Var *roperand),
	(*Var_int_op_leq2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_leq3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_geq)(Var_int *self, Var *roperand),
	(*Var_int_op_geq2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_geq3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_bor)(Var_int *self, Var *roperand),
	(*Var_int_op_bor2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_bor3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_bxor)(Var_int *self, Var *roperand),
	(*Var_int_op_bxor2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_bxor3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_band)(Var_int *self, Var *roperand),
	(*Var_int_op_band2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_band3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_or)(Var_int *self, Var *roperand),
	(*Var_int_op_or2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_or3)(Var_int *self, Var_float *loperand),
	(*Var_int_op_and)(Var_int *self, Var *roperand),
	(*Var_int_op_and2)(Var_int *self, Var_int *loperand),
	(*Var_int_op_and3)(Var_int *self, Var_float *loperand);
extern Int (*Var_int_to_int)(Var_int *self);
extern Float (*Var_int_to_float)(Var_int *self);

extern Var_int (*Var_int_new)(Int number);