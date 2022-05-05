#include <Pixic/core/variable/Var_int.h>

#include <Pixic/core/variable/Arithmetical.h>

static void set(Var_int *self, Var *rvalue)
{
	((Var_f)rvalue->f)->set3(rvalue, self);
}
static void set2(Var_int *self, Var_null *lvalue)
{
	*(Var_int *)lvalue=*self;
}
static void set3(Var_int *self, Var_int *lvalue)
{
	*lvalue=*self;
}
static Arithmetical op_mod(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_mod2(roperand, self);
}
static Arithmetical op_mod2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value%self->value);
}
static Arithmetical op_mod3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value%self->value);
}
static Arithmetical op_div(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_div2(roperand, self);
}
static Arithmetical op_div2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_float_new((Float)loperand->value/self->value);
}
static Arithmetical op_div3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value/self->value);
}
static Arithmetical op_idiv(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_idiv2(roperand, self);
}
static Arithmetical op_idiv2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value/self->value);
}
static Arithmetical op_idiv3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value/self->value);
}
static Arithmetical op_mul(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_mul2(roperand, self);
}
static Arithmetical op_mul2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value*self->value);
}
static Arithmetical op_mul3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value*self->value);
}
static Arithmetical op_not(Var_int *self)
{
	return (Arithmetical)Var_int_new(!self->value);
}
static Arithmetical op_bnot(Var_int *self)
{
	return (Arithmetical)Var_int_new(~self->value);
}
static Arithmetical op_add(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_add2(roperand, self);
}
static Arithmetical op_add2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value+self->value);
}
static Arithmetical op_add3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value+self->value);
}
static Arithmetical op_neg(Var_int *self)
{
	return (Arithmetical)Var_int_new(-self->value);
}
static Arithmetical op_sub(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_sub2(roperand, self);
}
static Arithmetical op_sub2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value-self->value);
}
static Arithmetical op_sub3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value-self->value);
}
static Arithmetical op_rsh(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_rsh2(roperand, self);
}
static Arithmetical op_rsh2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>>self->value);
}
static Arithmetical op_rsh3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value>>self->value);
}
static Arithmetical op_lsh(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_lsh2(roperand, self);
}
static Arithmetical op_lsh2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<<self->value);
}
static Arithmetical op_lsh3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value<<self->value);
}
static Arithmetical op_eq(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_eq2(roperand, self);
}
static Arithmetical op_eq2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value==self->value);
}
static Arithmetical op_eq3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value==self->value);
}
static Arithmetical op_neq(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_neq2(roperand, self);
}
static Arithmetical op_neq2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value!=self->value);
}
static Arithmetical op_neq3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value!=self->value);
}
static Arithmetical op_less(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_less2(roperand, self);
}
static Arithmetical op_less2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<self->value);
}
static Arithmetical op_less3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<self->value);
}
static Arithmetical op_great(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_great2(roperand, self);
}
static Arithmetical op_great2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>self->value);
}
static Arithmetical op_great3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>self->value);
}
static Arithmetical op_leq(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_leq2(roperand, self);
}
static Arithmetical op_leq2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<=self->value);
}
static Arithmetical op_leq3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<=self->value);
}
static Arithmetical op_geq(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_geq2(roperand, self);
}
static Arithmetical op_geq2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>=self->value);
}
static Arithmetical op_geq3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>=self->value);
}
static Arithmetical op_bor(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_bor2(roperand, self);
}
static Arithmetical op_bor2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value|self->value);
}
static Arithmetical op_bor3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value|self->value);
}
static Arithmetical op_bxor(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_bxor2(roperand, self);
}
static Arithmetical op_bxor2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value^self->value);
}
static Arithmetical op_bxor3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value^self->value);
}
static Arithmetical op_band(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_band2(roperand, self);
}
static Arithmetical op_band2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&self->value);
}
static Arithmetical op_band3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value&self->value);
}
static Arithmetical op_or(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_or2(roperand, self);
}
static Arithmetical op_or2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value||self->value);
}
static Arithmetical op_or3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value||self->value);
}
static Arithmetical op_and(Var_int *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_and2(roperand, self);
}
static Arithmetical op_and2(Var_int *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&&self->value);
}
static Arithmetical op_and3(Var_int *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&&self->value);
}
static Int to_int(Var_int *self)
{
	return self->value;
}
static Float to_float(Var_int *self)
{
	return self->value;
}
static const struct Var_f f=
{
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
	(Int (*)(void *))to_int,
	(Float (*)(void *))to_float
};
static Var_int constructor(Int number)
{
	Var_int self;
	self.f=&f;

	self.value=number;

	return self;
}

void
	(*Var_int_set)(Var_int *self, Var *rvalue)=set,
	(*Var_int_set2)(Var_int *self, Var_null *lvalue)=set2,
	(*Var_int_set3)(Var_int *self, Var_int *lvalue)=set3,
	(*Var_int_set4)(Var_int *self, Var_float *lvalue)=(void (*)(Var_int *, Var_float *))set2;
Arithmetical
	(*Var_int_op_mod)(Var_int *self, Var *roperand)=op_mod,
	(*Var_int_op_mod2)(Var_int *self, Var_int *loperand)=op_mod2,
	(*Var_int_op_mod3)(Var_int *self, Var_float *loperand)=op_mod3,
	(*Var_int_op_div)(Var_int *self, Var *roperand)=op_div,
	(*Var_int_op_div2)(Var_int *self, Var_int *loperand)=op_div2,
	(*Var_int_op_div3)(Var_int *self, Var_float *loperand)=op_div3,
	(*Var_int_op_idiv)(Var_int *self, Var *roperand)=op_idiv,
	(*Var_int_op_idiv2)(Var_int *self, Var_int *loperand)=op_idiv2,
	(*Var_int_op_idiv3)(Var_int *self, Var_float *loperand)=op_idiv3,
	(*Var_int_op_mul)(Var_int *self, Var *roperand)=op_mul,
	(*Var_int_op_mul2)(Var_int *self, Var_int *loperand)=op_mul2,
	(*Var_int_op_mul3)(Var_int *self, Var_float *loperand)=op_mul3,
	(*Var_int_op_not)(Var_int *self)=op_not,
	(*Var_int_op_bnot)(Var_int *self)=op_bnot,
	(*Var_int_op_add)(Var_int *self, Var *roperand)=op_add,
	(*Var_int_op_add2)(Var_int *self, Var_int *loperand)=op_add2,
	(*Var_int_op_add3)(Var_int *self, Var_float *loperand)=op_add3,
	(*Var_int_op_neg)(Var_int *self)=op_neg,
	(*Var_int_op_sub)(Var_int *self, Var *roperand)=op_sub,
	(*Var_int_op_sub2)(Var_int *self, Var_int *loperand)=op_sub2,
	(*Var_int_op_sub3)(Var_int *self, Var_float *loperand)=op_sub3,
	(*Var_int_op_rsh)(Var_int *self, Var *roperand)=op_rsh,
	(*Var_int_op_rsh2)(Var_int *self, Var_int *loperand)=op_rsh2,
	(*Var_int_op_rsh3)(Var_int *self, Var_float *loperand)=op_rsh3,
	(*Var_int_op_lsh)(Var_int *self, Var *roperand)=op_lsh,
	(*Var_int_op_lsh2)(Var_int *self, Var_int *loperand)=op_lsh2,
	(*Var_int_op_lsh3)(Var_int *self, Var_float *loperand)=op_lsh3,
	(*Var_int_op_eq)(Var_int *self, Var *roperand)=op_eq,
	(*Var_int_op_eq2)(Var_int *self, Var_int *loperand)=op_eq2,
	(*Var_int_op_eq3)(Var_int *self, Var_float *loperand)=op_eq3,
	(*Var_int_op_neq)(Var_int *self, Var *roperand)=op_neq,
	(*Var_int_op_neq2)(Var_int *self, Var_int *loperand)=op_neq2,
	(*Var_int_op_neq3)(Var_int *self, Var_float *loperand)=op_neq3,
	(*Var_int_op_less)(Var_int *self, Var *roperand)=op_less,
	(*Var_int_op_less2)(Var_int *self, Var_int *loperand)=op_less2,
	(*Var_int_op_less3)(Var_int *self, Var_float *loperand)=op_less3,
	(*Var_int_op_great)(Var_int *self, Var *roperand)=op_great,
	(*Var_int_op_great2)(Var_int *self, Var_int *loperand)=op_great2,
	(*Var_int_op_great3)(Var_int *self, Var_float *loperand)=op_great3,
	(*Var_int_op_leq)(Var_int *self, Var *roperand)=op_leq,
	(*Var_int_op_leq2)(Var_int *self, Var_int *loperand)=op_leq2,
	(*Var_int_op_leq3)(Var_int *self, Var_float *loperand)=op_leq3,
	(*Var_int_op_geq)(Var_int *self, Var *roperand)=op_geq,
	(*Var_int_op_geq2)(Var_int *self, Var_int *loperand)=op_geq2,
	(*Var_int_op_geq3)(Var_int *self, Var_float *loperand)=op_geq3,
	(*Var_int_op_bor)(Var_int *self, Var *roperand)=op_bor,
	(*Var_int_op_bor2)(Var_int *self, Var_int *loperand)=op_bor2,
	(*Var_int_op_bor3)(Var_int *self, Var_float *loperand)=op_bor3,
	(*Var_int_op_bxor)(Var_int *self, Var *roperand)=op_bxor,
	(*Var_int_op_bxor2)(Var_int *self, Var_int *loperand)=op_bxor2,
	(*Var_int_op_bxor3)(Var_int *self, Var_float *loperand)=op_bxor3,
	(*Var_int_op_band)(Var_int *self, Var *roperand)=op_band,
	(*Var_int_op_band2)(Var_int *self, Var_int *loperand)=op_band2,
	(*Var_int_op_band3)(Var_int *self, Var_float *loperand)=op_band3,
	(*Var_int_op_or)(Var_int *self, Var *roperand)=op_or,
	(*Var_int_op_or2)(Var_int *self, Var_int *loperand)=op_or2,
	(*Var_int_op_or3)(Var_int *self, Var_float *loperand)=op_or3,
	(*Var_int_op_and)(Var_int *self, Var *roperand)=op_and,
	(*Var_int_op_and2)(Var_int *self, Var_int *loperand)=op_and2,
	(*Var_int_op_and3)(Var_int *self, Var_float *loperand)=op_and3;
Int (*Var_int_to_int)(Var_int *self)=to_int;
Float (*Var_int_to_float)(Var_int *self)=to_float;

Var_int (*Var_int_new)(Int number)=constructor;