#include <Pixic/core/variable/Var_null>

#include "stdio.h"
#include <Pixic/core/variable/Var>
#include <Pixic/core/variable/Arithmetical>

#define denull(function)\
	printf("Variable \"%s\" is not defined. Default value: 0.\n", self->name);\
	(*(Var_int *)self=Var_int_new(0)).Var->function;

static void set(Var_null *self, Var *rvalue)
{
	(*rvalue)->set2(rvalue, self);
}
static void set2(Var_null *self, Var_null *lvalue)
{
	printf("Variable \"%s\" is not defined. Default value: 0.\n", self->name);
	*(Var_int *)lvalue=*(Var_int *)self=Var_int_new(0);
}
static void set3(Var_null *self, Var_int *lvalue)
{
	printf("Variable \"%s\" is not defined. Default value: 0.\n", self->name);
	*lvalue=*(Var_int *)self=Var_int_new(0);
}
static Arithmetical op_mod(Var_null *self, Var *roperand)
{
	denull(op_mod(&self->Var, roperand))
}
static Arithmetical op_mod2(Var_null *self, Var_int *loperand)
{
	denull(op_mod2(&self->Var, loperand))
}
static Arithmetical op_mod3(Var_null *self, Var_float *loperand)
{
	denull(op_mod3(&self->Var, loperand))
}
static Arithmetical op_div(Var_null *self, Var *roperand)
{
	denull(op_div(&self->Var, roperand))
}
static Arithmetical op_div2(Var_null *self, Var_int *loperand)
{
	denull(op_div2(&self->Var, loperand))
}
static Arithmetical op_div3(Var_null *self, Var_float *loperand)
{
	denull(op_div3(&self->Var, loperand))
}
static Arithmetical op_idiv(Var_null *self, Var *roperand)
{
	denull(op_idiv(&self->Var, roperand))
}
static Arithmetical op_idiv2(Var_null *self, Var_int *loperand)
{
	denull(op_idiv2(&self->Var, loperand))
}
static Arithmetical op_idiv3(Var_null *self, Var_float *loperand)
{
	denull(op_idiv3(&self->Var, loperand))
}
static Arithmetical op_mul(Var_null *self, Var *roperand)
{
	denull(op_mul(&self->Var, roperand))
}
static Arithmetical op_mul2(Var_null *self, Var_int *loperand)
{
	denull(op_mul2(&self->Var, loperand))
}
static Arithmetical op_mul3(Var_null *self, Var_float *loperand)
{
	denull(op_mul3(&self->Var, loperand))
}
static Arithmetical op_not(Var_null *self)
{
	denull(op_not(&self->Var))
}
static Arithmetical op_bnot(Var_null *self)
{
	denull(op_bnot(&self->Var))
}
static Arithmetical op_add(Var_null *self, Var *roperand)
{
	denull(op_add(&self->Var, roperand))
}
static Arithmetical op_add2(Var_null *self, Var_int *loperand)
{
	denull(op_add2(&self->Var, loperand))
}
static Arithmetical op_add3(Var_null *self, Var_float *loperand)
{
	denull(op_add3(&self->Var, loperand))
}
static Arithmetical op_neg(Var_null *self)
{
	denull(op_neg(&self->Var))
}
static Arithmetical op_sub(Var_null *self, Var *roperand)
{
	denull(op_sub(&self->Var, roperand))
}
static Arithmetical op_sub2(Var_null *self, Var_int *loperand)
{
	denull(op_sub2(&self->Var, loperand))
}
static Arithmetical op_sub3(Var_null *self, Var_float *loperand)
{
	denull(op_sub3(&self->Var, loperand))
}
static Arithmetical op_rsh(Var_null *self, Var *roperand)
{
	denull(op_rsh(&self->Var, roperand))
}
static Arithmetical op_rsh2(Var_null *self, Var_int *loperand)
{
	denull(op_rsh2(&self->Var, loperand))
}
static Arithmetical op_rsh3(Var_null *self, Var_float *loperand)
{
	denull(op_rsh3(&self->Var, loperand))
}
static Arithmetical op_lsh(Var_null *self, Var *roperand)
{
	denull(op_lsh(&self->Var, roperand))
}
static Arithmetical op_lsh2(Var_null *self, Var_int *loperand)
{
	denull(op_lsh2(&self->Var, loperand))
}
static Arithmetical op_lsh3(Var_null *self, Var_float *loperand)
{
	denull(op_lsh3(&self->Var, loperand))
}
static Arithmetical op_eq(Var_null *self, Var *roperand)
{
	denull(op_eq(&self->Var, roperand))
}
static Arithmetical op_eq2(Var_null *self, Var_int *loperand)
{
	denull(op_eq2(&self->Var, loperand))
}
static Arithmetical op_eq3(Var_null *self, Var_float *loperand)
{
	denull(op_eq3(&self->Var, loperand))
}
static Arithmetical op_neq(Var_null *self, Var *roperand)
{
	denull(op_neq(&self->Var, roperand))
}
static Arithmetical op_neq2(Var_null *self, Var_int *loperand)
{
	denull(op_neq2(&self->Var, loperand))
}
static Arithmetical op_neq3(Var_null *self, Var_float *loperand)
{
	denull(op_neq3(&self->Var, loperand))
}
static Arithmetical op_less(Var_null *self, Var *roperand)
{
	denull(op_less(&self->Var, roperand))
}
static Arithmetical op_less2(Var_null *self, Var_int *loperand)
{
	denull(op_less2(&self->Var, loperand))
}
static Arithmetical op_less3(Var_null *self, Var_float *loperand)
{
	denull(op_less3(&self->Var, loperand))
}
static Arithmetical op_great(Var_null *self, Var *roperand)
{
	denull(op_great(&self->Var, roperand))
}
static Arithmetical op_great2(Var_null *self, Var_int *loperand)
{
	denull(op_great2(&self->Var, loperand))
}
static Arithmetical op_great3(Var_null *self, Var_float *loperand)
{
	denull(op_great3(&self->Var, loperand))
}
static Arithmetical op_leq(Var_null *self, Var *roperand)
{
	denull(op_leq(&self->Var, roperand))
}
static Arithmetical op_leq2(Var_null *self, Var_int *loperand)
{
	denull(op_leq2(&self->Var, loperand))
}
static Arithmetical op_leq3(Var_null *self, Var_float *loperand)
{
	denull(op_leq3(&self->Var, loperand))
}
static Arithmetical op_geq(Var_null *self, Var *roperand)
{
	denull(op_geq(&self->Var, roperand))
}
static Arithmetical op_geq2(Var_null *self, Var_int *loperand)
{
	denull(op_geq2(&self->Var, loperand))
}
static Arithmetical op_geq3(Var_null *self, Var_float *loperand)
{
	denull(op_geq3(&self->Var, loperand))
}
static Arithmetical op_bor(Var_null *self, Var *roperand)
{
	denull(op_bor(&self->Var, roperand))
}
static Arithmetical op_bor2(Var_null *self, Var_int *loperand)
{
	denull(op_bor2(&self->Var, loperand))
}
static Arithmetical op_bor3(Var_null *self, Var_float *loperand)
{
	denull(op_bor3(&self->Var, loperand))
}
static Arithmetical op_bxor(Var_null *self, Var *roperand)
{
	denull(op_bxor(&self->Var, roperand))
}
static Arithmetical op_bxor2(Var_null *self, Var_int *loperand)
{
	denull(op_bxor2(&self->Var, loperand))
}
static Arithmetical op_bxor3(Var_null *self, Var_float *loperand)
{
	denull(op_bxor3(&self->Var, loperand))
}
static Arithmetical op_band(Var_null *self, Var *roperand)
{
	denull(op_band(&self->Var, roperand))
}
static Arithmetical op_band2(Var_null *self, Var_int *loperand)
{
	denull(op_band2(&self->Var, loperand))
}
static Arithmetical op_band3(Var_null *self, Var_float *loperand)
{
	denull(op_band3(&self->Var, loperand))
}
static Arithmetical op_or(Var_null *self, Var *roperand)
{
	denull(op_or(&self->Var, roperand))
}
static Arithmetical op_or2(Var_null *self, Var_int *loperand)
{
	denull(op_or2(&self->Var, loperand))
}
static Arithmetical op_or3(Var_null *self, Var_float *loperand)
{
	denull(op_or3(&self->Var, loperand))
}
static Arithmetical op_and(Var_null *self, Var *roperand)
{
	denull(op_and(&self->Var, roperand))
}
static Arithmetical op_and2(Var_null *self, Var_int *loperand)
{
	denull(op_and2(&self->Var, loperand))
}
static Arithmetical op_and3(Var_null *self, Var_float *loperand)
{
	denull(op_and3(&self->Var, loperand))
}
static long to_long(Var_null *self)
{
	denull(to_long(&self->Var))
}
static long long to_long_long(Var_null *self)
{
	denull(to_long_long(&self->Var))
}
static float to_float(Var_null *self)
{
	denull(to_float(&self->Var))
}
static double to_double(Var_null *self)
{
	denull(to_double(&self->Var))
}
static bool to_bool(Var_null *self)
{
	denull(to_bool(&self->Var))
}

static const struct vtable_Var vtable_Var=
{
	cast_offset(Var_null, Var),

	(void (*)(Var *, Var *))set,
	(void (*)(Var *, Var_null *))set2,
	(void (*)(Var *, Var_int *))set3,
	(void (*)(Var *, Var_float *))set2,
	(Arithmetical (*)(Var *, Var *))op_mod,
	(Arithmetical (*)(Var *, Var_int *))op_mod2,
	(Arithmetical (*)(Var *, Var_float *))op_mod3,
	(Arithmetical (*)(Var *, Var *))op_div,
	(Arithmetical (*)(Var *, Var_int *))op_div2,
	(Arithmetical (*)(Var *, Var_float *))op_div3,
	(Arithmetical (*)(Var *, Var *))op_idiv,
	(Arithmetical (*)(Var *, Var_int *))op_idiv2,
	(Arithmetical (*)(Var *, Var_float *))op_idiv3,
	(Arithmetical (*)(Var *, Var *))op_mul,
	(Arithmetical (*)(Var *, Var_int *))op_mul2,
	(Arithmetical (*)(Var *, Var_float *))op_mul3,
	(Arithmetical (*)(Var *))op_not,
	(Arithmetical (*)(Var *))op_bnot,
	(Arithmetical (*)(Var *, Var *))op_add,
	(Arithmetical (*)(Var *, Var_int *))op_add2,
	(Arithmetical (*)(Var *, Var_float *))op_add3,
	(Arithmetical (*)(Var *))op_neg,
	(Arithmetical (*)(Var *, Var *))op_sub,
	(Arithmetical (*)(Var *, Var_int *))op_sub2,
	(Arithmetical (*)(Var *, Var_float *))op_sub3,
	(Arithmetical (*)(Var *, Var *))op_rsh,
	(Arithmetical (*)(Var *, Var_int *))op_rsh2,
	(Arithmetical (*)(Var *, Var_float *))op_rsh3,
	(Arithmetical (*)(Var *, Var *))op_lsh,
	(Arithmetical (*)(Var *, Var_int *))op_lsh2,
	(Arithmetical (*)(Var *, Var_float *))op_lsh3,
	(Arithmetical (*)(Var *, Var *))op_eq,
	(Arithmetical (*)(Var *, Var_int *))op_eq2,
	(Arithmetical (*)(Var *, Var_float *))op_eq3,
	(Arithmetical (*)(Var *, Var *))op_neq,
	(Arithmetical (*)(Var *, Var_int *))op_neq2,
	(Arithmetical (*)(Var *, Var_float *))op_neq3,
	(Arithmetical (*)(Var *, Var *))op_less,
	(Arithmetical (*)(Var *, Var_int *))op_less2,
	(Arithmetical (*)(Var *, Var_float *))op_less3,
	(Arithmetical (*)(Var *, Var *))op_great,
	(Arithmetical (*)(Var *, Var_int *))op_great2,
	(Arithmetical (*)(Var *, Var_float *))op_great3,
	(Arithmetical (*)(Var *, Var *))op_leq,
	(Arithmetical (*)(Var *, Var_int *))op_leq2,
	(Arithmetical (*)(Var *, Var_float *))op_leq3,
	(Arithmetical (*)(Var *, Var *))op_geq,
	(Arithmetical (*)(Var *, Var_int *))op_geq2,
	(Arithmetical (*)(Var *, Var_float *))op_geq3,
	(Arithmetical (*)(Var *, Var *))op_bor,
	(Arithmetical (*)(Var *, Var_int *))op_bor2,
	(Arithmetical (*)(Var *, Var_float *))op_bor3,
	(Arithmetical (*)(Var *, Var *))op_bxor,
	(Arithmetical (*)(Var *, Var_int *))op_bxor2,
	(Arithmetical (*)(Var *, Var_float *))op_bxor3,
	(Arithmetical (*)(Var *, Var *))op_band,
	(Arithmetical (*)(Var *, Var_int *))op_band2,
	(Arithmetical (*)(Var *, Var_float *))op_band3,
	(Arithmetical (*)(Var *, Var *))op_or,
	(Arithmetical (*)(Var *, Var_int *))op_or2,
	(Arithmetical (*)(Var *, Var_float *))op_or3,
	(Arithmetical (*)(Var *, Var *))op_and,
	(Arithmetical (*)(Var *, Var_int *))op_and2,
	(Arithmetical (*)(Var *, Var_float *))op_and3,
	(long (*)(Var *))to_long,
	(long long (*)(Var *))to_long_long,
	(float (*)(Var *))to_float,
	(double (*)(Var *))to_double,
	#ifdef X32
		(Int (*)(Var *))to_long,
		(Float (*)(Var *))to_float,
	#endif
	#ifdef X64
		(Int (*)(Var *))to_long_long,
		(Float (*)(Var *))to_double,
	#endif
	(bool (*)(Var *))to_bool
};

static Var_null constructor(const char *name)
{
	Var_null self;
	self.Var=&vtable_Var;

	self.name=name;

	return self;
}

void
	(*Var_null_set)(Var_null *self, Var *rvalue)=set,
	(*Var_null_set2)(Var_null *self, Var_null *lvalue)=set2,
	(*Var_null_set3)(Var_null *self, Var_int *lvalue)=set3,
	(*Var_null_set4)(Var_null *self, Var_float *lvalue)=(void (*)(Var_null *, Var_float *))set2;
Arithmetical
	(*Var_null_op_mod)(Var_null *self, Var *roperand)=op_mod,
	(*Var_null_op_mod2)(Var_null *self, Var_int *loperand)=op_mod2,
	(*Var_null_op_mod3)(Var_null *self, Var_float *loperand)=op_mod3,
	(*Var_null_op_div)(Var_null *self, Var *roperand)=op_div,
	(*Var_null_op_div2)(Var_null *self, Var_int *loperand)=op_div2,
	(*Var_null_op_div3)(Var_null *self, Var_float *loperand)=op_div3,
	(*Var_null_op_idiv)(Var_null *self, Var *roperand)=op_idiv,
	(*Var_null_op_idiv2)(Var_null *self, Var_int *loperand)=op_idiv2,
	(*Var_null_op_idiv3)(Var_null *self, Var_float *loperand)=op_idiv3,
	(*Var_null_op_mul)(Var_null *self, Var *roperand)=op_mul,
	(*Var_null_op_mul2)(Var_null *self, Var_int *loperand)=op_mul2,
	(*Var_null_op_mul3)(Var_null *self, Var_float *loperand)=op_mul3,
	(*Var_null_op_not)(Var_null *self)=op_not,
	(*Var_null_op_bnot)(Var_null *self)=op_bnot,
	(*Var_null_op_add)(Var_null *self, Var *roperand)=op_add,
	(*Var_null_op_add2)(Var_null *self, Var_int *loperand)=op_add2,
	(*Var_null_op_add3)(Var_null *self, Var_float *loperand)=op_add3,
	(*Var_null_op_neg)(Var_null *self)=op_neg,
	(*Var_null_op_sub)(Var_null *self, Var *roperand)=op_sub,
	(*Var_null_op_sub2)(Var_null *self, Var_int *loperand)=op_sub2,
	(*Var_null_op_sub3)(Var_null *self, Var_float *loperand)=op_sub3,
	(*Var_null_op_rsh)(Var_null *self, Var *roperand)=op_rsh,
	(*Var_null_op_rsh2)(Var_null *self, Var_int *loperand)=op_rsh2,
	(*Var_null_op_rsh3)(Var_null *self, Var_float *loperand)=op_rsh3,
	(*Var_null_op_lsh)(Var_null *self, Var *roperand)=op_lsh,
	(*Var_null_op_lsh2)(Var_null *self, Var_int *loperand)=op_lsh2,
	(*Var_null_op_lsh3)(Var_null *self, Var_float *loperand)=op_lsh3,
	(*Var_null_op_eq)(Var_null *self, Var *roperand)=op_eq,
	(*Var_null_op_eq2)(Var_null *self, Var_int *loperand)=op_eq2,
	(*Var_null_op_eq3)(Var_null *self, Var_float *loperand)=op_eq3,
	(*Var_null_op_neq)(Var_null *self, Var *roperand)=op_neq,
	(*Var_null_op_neq2)(Var_null *self, Var_int *loperand)=op_neq2,
	(*Var_null_op_neq3)(Var_null *self, Var_float *loperand)=op_neq3,
	(*Var_null_op_less)(Var_null *self, Var *roperand)=op_less,
	(*Var_null_op_less2)(Var_null *self, Var_int *loperand)=op_less2,
	(*Var_null_op_less3)(Var_null *self, Var_float *loperand)=op_less3,
	(*Var_null_op_great)(Var_null *self, Var *roperand)=op_great,
	(*Var_null_op_great2)(Var_null *self, Var_int *loperand)=op_great2,
	(*Var_null_op_great3)(Var_null *self, Var_float *loperand)=op_great3,
	(*Var_null_op_leq)(Var_null *self, Var *roperand)=op_leq,
	(*Var_null_op_leq2)(Var_null *self, Var_int *loperand)=op_leq2,
	(*Var_null_op_leq3)(Var_null *self, Var_float *loperand)=op_leq3,
	(*Var_null_op_geq)(Var_null *self, Var *roperand)=op_geq,
	(*Var_null_op_geq2)(Var_null *self, Var_int *loperand)=op_geq2,
	(*Var_null_op_geq3)(Var_null *self, Var_float *loperand)=op_geq3,
	(*Var_null_op_bor)(Var_null *self, Var *roperand)=op_bor,
	(*Var_null_op_bor2)(Var_null *self, Var_int *loperand)=op_bor2,
	(*Var_null_op_bor3)(Var_null *self, Var_float *loperand)=op_bor3,
	(*Var_null_op_bxor)(Var_null *self, Var *roperand)=op_bxor,
	(*Var_null_op_bxor2)(Var_null *self, Var_int *loperand)=op_bxor2,
	(*Var_null_op_bxor3)(Var_null *self, Var_float *loperand)=op_bxor3,
	(*Var_null_op_band)(Var_null *self, Var *roperand)=op_band,
	(*Var_null_op_band2)(Var_null *self, Var_int *loperand)=op_band2,
	(*Var_null_op_band3)(Var_null *self, Var_float *loperand)=op_band3,
	(*Var_null_op_or)(Var_null *self, Var *roperand)=op_or,
	(*Var_null_op_or2)(Var_null *self, Var_int *loperand)=op_or2,
	(*Var_null_op_or3)(Var_null *self, Var_float *loperand)=op_or3,
	(*Var_null_op_and)(Var_null *self, Var *roperand)=op_and,
	(*Var_null_op_and2)(Var_null *self, Var_int *loperand)=op_and2,
	(*Var_null_op_and3)(Var_null *self, Var_float *loperand)=op_and3;
long (*Var_null_to_long)(Var_null *self)=to_long;
long long (*Var_null_to_long_long)(Var_null *self)=to_long_long;
float (*Var_null_to_float)(Var_null *self)=to_float;
double (*Var_null_to_double)(Var_null *self)=to_double;
#ifdef X32
	Int (*Var_null_to_Int)(Var_null *self)=to_long;
	Float (*Var_null_to_Float)(Var_null *self)=to_float;
#endif
#ifdef X64
	Int (*Var_null_to_Int)(Var_null *self)=to_long_long;
	Float (*Var_null_to_Float)(Var_null *self)=to_double;
#endif
bool (*Var_null_to_bool)(Var_null *self)=to_bool;

Var_null (*Var_null_new)(const char *name)=constructor;