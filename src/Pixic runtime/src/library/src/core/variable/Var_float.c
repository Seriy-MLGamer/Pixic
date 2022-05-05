#include <Pixic/core/variable/Var_float.h>

#include <Pixic/core/variable/Arithmetical.h>

static void set(Var_float *self, Var *rvalue)
{
	((Var_f)rvalue->f)->set4(rvalue, self);
}
static void set2(Var_float *self, Var_null *lvalue)
{
	*(Var_float *)lvalue=*self;
}
static void set4(Var_float *self, Var_float *lvalue)
{
	*lvalue=*self;
}
static Arithmetical op_mod(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_mod3(roperand, self);
}
static Arithmetical op_mod2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value%(Int)self->value);
}
static Arithmetical op_mod3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value%(Int)self->value);
}
static Arithmetical op_div(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_div3(roperand, self);
}
static Arithmetical op_div2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value/self->value);
}
static Arithmetical op_div3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value/self->value);
}
static Arithmetical op_idiv(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_idiv3(roperand, self);
}
static Arithmetical op_idiv2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value/(Int)self->value);
}
static Arithmetical op_idiv3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value/(Int)self->value);
}
static Arithmetical op_mul(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_mul3(roperand, self);
}
static Arithmetical op_mul2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value*self->value);
}
static Arithmetical op_mul3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value*self->value);
}
static Arithmetical op_not(Var_float *self)
{
	return (Arithmetical)Var_int_new(!self->value);
}
static Arithmetical op_bnot(Var_float *self)
{
	return (Arithmetical)Var_int_new(~(Int)self->value);
}
static Arithmetical op_add(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_add3(roperand, self);
}
static Arithmetical op_add2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value+self->value);
}
static Arithmetical op_add3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value+self->value);
}
static Arithmetical op_neg(Var_float *self)
{
	return (Arithmetical)Var_float_new(-self->value);
}
static Arithmetical op_sub(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_sub3(roperand, self);
}
static Arithmetical op_sub2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value-self->value);
}
static Arithmetical op_sub3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_float_new(loperand->value-self->value);
}
static Arithmetical op_rsh(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_rsh3(roperand, self);
}
static Arithmetical op_rsh2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>>(Int)self->value);
}
static Arithmetical op_rsh3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value>>(Int)self->value);
}
static Arithmetical op_lsh(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_lsh3(roperand, self);
}
static Arithmetical op_lsh2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<<(Int)self->value);
}
static Arithmetical op_lsh3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value<<(Int)self->value);
}
static Arithmetical op_eq(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_eq3(roperand, self);
}
static Arithmetical op_eq2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value==self->value);
}
static Arithmetical op_eq3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value==self->value);
}
static Arithmetical op_neq(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_neq3(roperand, self);
}
static Arithmetical op_neq2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value!=self->value);
}
static Arithmetical op_neq3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value!=self->value);
}
static Arithmetical op_less(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_less3(roperand, self);
}
static Arithmetical op_less2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<self->value);
}
static Arithmetical op_less3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<self->value);
}
static Arithmetical op_great(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_great3(roperand, self);
}
static Arithmetical op_great2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>self->value);
}
static Arithmetical op_great3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>self->value);
}
static Arithmetical op_leq(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_leq3(roperand, self);
}
static Arithmetical op_leq2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<=self->value);
}
static Arithmetical op_leq3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value<=self->value);
}
static Arithmetical op_geq(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_geq3(roperand, self);
}
static Arithmetical op_geq2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>=self->value);
}
static Arithmetical op_geq3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value>=self->value);
}
static Arithmetical op_bor(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_bor3(roperand, self);
}
static Arithmetical op_bor2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value|(Int)self->value);
}
static Arithmetical op_bor3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value|(Int)self->value);
}
static Arithmetical op_bxor(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_bxor3(roperand, self);
}
static Arithmetical op_bxor2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value^(Int)self->value);
}
static Arithmetical op_bxor3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value^(Int)self->value);
}
static Arithmetical op_band(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_band3(roperand, self);
}
static Arithmetical op_band2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&(Int)self->value);
}
static Arithmetical op_band3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new((Int)loperand->value&(Int)self->value);
}
static Arithmetical op_or(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_or3(roperand, self);
}
static Arithmetical op_or2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value||self->value);
}
static Arithmetical op_or3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value||self->value);
}
static Arithmetical op_and(Var_float *self, Var *roperand)
{
	return ((Var_f)roperand->f)->op_and3(roperand, self);
}
static Arithmetical op_and2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&&self->value);
}
static Arithmetical op_and3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&&self->value);
}
static Int to_int(Var_float *self)
{
	return self->value;
}
static Float to_float(Var_float *self)
{
	return self->value;
}
static const struct Var_f f=
{
	(void (*)(void *, Var *))set,
	(void (*)(void *, Var_null *))set2,
	(void (*)(void *, Var_int *))set2,
	(void (*)(void *, Var_float *))set4,
	(Arithmetical (*)(void *, Var *))op_mod,
	(Arithmetical (*)(void *, Var_int *))op_mod2,
	(Arithmetical (*)(void *, Var_float *))op_mod3,
	(Arithmetical (*)(void *, Var *))op_div,
	(Arithmetical (*)(void *, Var_int *))op_div2,
	(Arithmetical (*)(void *, Var_float *))op_div3,
	(Arithmetical (*)(void *, Var *))op_idiv,
	(Arithmetical (*)(void *, Var_int *))op_idiv2,
	(Arithmetical (*)(void *, Var_float *))op_idiv3,
	(Arithmetical (*)(void *, Var *))op_mul,
	(Arithmetical (*)(void *, Var_int *))op_mul2,
	(Arithmetical (*)(void *, Var_float *))op_mul3,
	(Arithmetical (*)(void *))op_not,
	(Arithmetical (*)(void *))op_bnot,
	(Arithmetical (*)(void *, Var *))op_add,
	(Arithmetical (*)(void *, Var_int *))op_add2,
	(Arithmetical (*)(void *, Var_float *))op_add3,
	(Arithmetical (*)(void *))op_neg,
	(Arithmetical (*)(void *, Var *))op_sub,
	(Arithmetical (*)(void *, Var_int *))op_sub2,
	(Arithmetical (*)(void *, Var_float *))op_sub3,
	(Arithmetical (*)(void *, Var *))op_rsh,
	(Arithmetical (*)(void *, Var_int *))op_rsh2,
	(Arithmetical (*)(void *, Var_float *))op_rsh3,
	(Arithmetical (*)(void *, Var *))op_lsh,
	(Arithmetical (*)(void *, Var_int *))op_lsh2,
	(Arithmetical (*)(void *, Var_float *))op_lsh3,
	(Arithmetical (*)(void *, Var *))op_eq,
	(Arithmetical (*)(void *, Var_int *))op_eq2,
	(Arithmetical (*)(void *, Var_float *))op_eq3,
	(Arithmetical (*)(void *, Var *))op_neq,
	(Arithmetical (*)(void *, Var_int *))op_neq2,
	(Arithmetical (*)(void *, Var_float *))op_neq3,
	(Arithmetical (*)(void *, Var *))op_less,
	(Arithmetical (*)(void *, Var_int *))op_less2,
	(Arithmetical (*)(void *, Var_float *))op_less3,
	(Arithmetical (*)(void *, Var *))op_great,
	(Arithmetical (*)(void *, Var_int *))op_great2,
	(Arithmetical (*)(void *, Var_float *))op_great3,
	(Arithmetical (*)(void *, Var *))op_leq,
	(Arithmetical (*)(void *, Var_int *))op_leq2,
	(Arithmetical (*)(void *, Var_float *))op_leq3,
	(Arithmetical (*)(void *, Var *))op_geq,
	(Arithmetical (*)(void *, Var_int *))op_geq2,
	(Arithmetical (*)(void *, Var_float *))op_geq3,
	(Arithmetical (*)(void *, Var *))op_bor,
	(Arithmetical (*)(void *, Var_int *))op_bor2,
	(Arithmetical (*)(void *, Var_float *))op_bor3,
	(Arithmetical (*)(void *, Var *))op_bxor,
	(Arithmetical (*)(void *, Var_int *))op_bxor2,
	(Arithmetical (*)(void *, Var_float *))op_bxor3,
	(Arithmetical (*)(void *, Var *))op_band,
	(Arithmetical (*)(void *, Var_int *))op_band2,
	(Arithmetical (*)(void *, Var_float *))op_band3,
	(Arithmetical (*)(void *, Var *))op_or,
	(Arithmetical (*)(void *, Var_int *))op_or2,
	(Arithmetical (*)(void *, Var_float *))op_or3,
	(Arithmetical (*)(void *, Var *))op_and,
	(Arithmetical (*)(void *, Var_int *))op_and2,
	(Arithmetical (*)(void *, Var_float *))op_and3,
	(Int (*)(void *))to_int,
	(Float (*)(void *))to_float
};
static Var_float constructor(Float number)
{
	Var_float self;
	self.f=&f;

	self.value=number;

	return self;
}

void
	(*Var_float_set)(Var_float *self, Var *rvalue)=set,
	(*Var_float_set2)(Var_float *self, Var_null *lvalue)=set2,
	(*Var_float_set3)(Var_float *self, Var_int *lvalue)=(void (*)(Var_float *, Var_int *))set2,
	(*Var_float_set4)(Var_float *self, Var_float *lvalue)=set4;
Arithmetical
	(*Var_float_op_mod)(Var_float *self, Var *roperand)=op_mod,
	(*Var_float_op_mod2)(Var_float *self, Var_int *loperand)=op_mod2,
	(*Var_float_op_mod3)(Var_float *self, Var_float *loperand)=op_mod3,
	(*Var_float_op_div)(Var_float *self, Var *roperand)=op_div,
	(*Var_float_op_div2)(Var_float *self, Var_int *loperand)=op_div2,
	(*Var_float_op_div3)(Var_float *self, Var_float *loperand)=op_div3,
	(*Var_float_op_idiv)(Var_float *self, Var *roperand)=op_idiv,
	(*Var_float_op_idiv2)(Var_float *self, Var_int *loperand)=op_idiv2,
	(*Var_float_op_idiv3)(Var_float *self, Var_float *loperand)=op_idiv3,
	(*Var_float_op_mul)(Var_float *self, Var *roperand)=op_mul,
	(*Var_float_op_mul2)(Var_float *self, Var_int *loperand)=op_mul2,
	(*Var_float_op_mul3)(Var_float *self, Var_float *loperand)=op_mul3,
	(*Var_float_op_not)(Var_float *self)=op_not,
	(*Var_float_op_bnot)(Var_float *self)=op_bnot,
	(*Var_float_op_add)(Var_float *self, Var *roperand)=op_add,
	(*Var_float_op_add2)(Var_float *self, Var_int *loperand)=op_add2,
	(*Var_float_op_add3)(Var_float *self, Var_float *loperand)=op_add3,
	(*Var_float_op_neg)(Var_float *self)=op_neg,
	(*Var_float_op_sub)(Var_float *self, Var *roperand)=op_sub,
	(*Var_float_op_sub2)(Var_float *self, Var_int *loperand)=op_sub2,
	(*Var_float_op_sub3)(Var_float *self, Var_float *loperand)=op_sub3,
	(*Var_float_op_rsh)(Var_float *self, Var *roperand)=op_rsh,
	(*Var_float_op_rsh2)(Var_float *self, Var_int *loperand)=op_rsh2,
	(*Var_float_op_rsh3)(Var_float *self, Var_float *loperand)=op_rsh3,
	(*Var_float_op_lsh)(Var_float *self, Var *roperand)=op_lsh,
	(*Var_float_op_lsh2)(Var_float *self, Var_int *loperand)=op_lsh2,
	(*Var_float_op_lsh3)(Var_float *self, Var_float *loperand)=op_lsh3,
	(*Var_float_op_eq)(Var_float *self, Var *roperand)=op_eq,
	(*Var_float_op_eq2)(Var_float *self, Var_int *loperand)=op_eq2,
	(*Var_float_op_eq3)(Var_float *self, Var_float *loperand)=op_eq3,
	(*Var_float_op_neq)(Var_float *self, Var *roperand)=op_neq,
	(*Var_float_op_neq2)(Var_float *self, Var_int *loperand)=op_neq2,
	(*Var_float_op_neq3)(Var_float *self, Var_float *loperand)=op_neq3,
	(*Var_float_op_less)(Var_float *self, Var *roperand)=op_less,
	(*Var_float_op_less2)(Var_float *self, Var_int *loperand)=op_less2,
	(*Var_float_op_less3)(Var_float *self, Var_float *loperand)=op_less3,
	(*Var_float_op_great)(Var_float *self, Var *roperand)=op_great,
	(*Var_float_op_great2)(Var_float *self, Var_int *loperand)=op_great2,
	(*Var_float_op_great3)(Var_float *self, Var_float *loperand)=op_great3,
	(*Var_float_op_leq)(Var_float *self, Var *roperand)=op_leq,
	(*Var_float_op_leq2)(Var_float *self, Var_int *loperand)=op_leq2,
	(*Var_float_op_leq3)(Var_float *self, Var_float *loperand)=op_leq3,
	(*Var_float_op_geq)(Var_float *self, Var *roperand)=op_geq,
	(*Var_float_op_geq2)(Var_float *self, Var_int *loperand)=op_geq2,
	(*Var_float_op_geq3)(Var_float *self, Var_float *loperand)=op_geq3,
	(*Var_float_op_bor)(Var_float *self, Var *roperand)=op_bor,
	(*Var_float_op_bor2)(Var_float *self, Var_int *loperand)=op_bor2,
	(*Var_float_op_bor3)(Var_float *self, Var_float *loperand)=op_bor3,
	(*Var_float_op_bxor)(Var_float *self, Var *roperand)=op_bxor,
	(*Var_float_op_bxor2)(Var_float *self, Var_int *loperand)=op_bxor2,
	(*Var_float_op_bxor3)(Var_float *self, Var_float *loperand)=op_bxor3,
	(*Var_float_op_band)(Var_float *self, Var *roperand)=op_band,
	(*Var_float_op_band2)(Var_float *self, Var_int *loperand)=op_band2,
	(*Var_float_op_band3)(Var_float *self, Var_float *loperand)=op_band3,
	(*Var_float_op_or)(Var_float *self, Var *roperand)=op_or,
	(*Var_float_op_or2)(Var_float *self, Var_int *loperand)=op_or2,
	(*Var_float_op_or3)(Var_float *self, Var_float *loperand)=op_or3,
	(*Var_float_op_and)(Var_float *self, Var *roperand)=op_and,
	(*Var_float_op_and2)(Var_float *self, Var_int *loperand)=op_and2,
	(*Var_float_op_and3)(Var_float *self, Var_float *loperand)=op_and3;
Int (*Var_float_to_int)(Var_float *self)=to_int;
Float (*Var_float_to_float)(Var_float *self)=to_float;

Var_float (*Var_float_new)(Float number)=constructor;