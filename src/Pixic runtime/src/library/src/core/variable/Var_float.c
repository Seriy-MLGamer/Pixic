#include <Pixic/core/variable/Var_float>

#include <Pixic/core/variable/Var>
#include <Pixic/core/variable/Arithmetical>

static void set(Var_float *self, Var *rvalue)
{
	(*rvalue)->set4(rvalue, self);
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
	return (*roperand)->op_mod3(roperand, self);
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
	return (*roperand)->op_div3(roperand, self);
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
	return (*roperand)->op_idiv3(roperand, self);
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
	return (*roperand)->op_mul3(roperand, self);
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
	return (*roperand)->op_add3(roperand, self);
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
	return (*roperand)->op_sub3(roperand, self);
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
	return (*roperand)->op_rsh3(roperand, self);
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
	return (*roperand)->op_lsh3(roperand, self);
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
	return (*roperand)->op_eq3(roperand, self);
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
	return (*roperand)->op_neq3(roperand, self);
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
	return (*roperand)->op_less3(roperand, self);
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
	return (*roperand)->op_great3(roperand, self);
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
	return (*roperand)->op_leq3(roperand, self);
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
	return (*roperand)->op_geq3(roperand, self);
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
	return (*roperand)->op_bor3(roperand, self);
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
	return (*roperand)->op_bxor3(roperand, self);
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
	return (*roperand)->op_band3(roperand, self);
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
	return (*roperand)->op_or3(roperand, self);
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
	return (*roperand)->op_and3(roperand, self);
}
static Arithmetical op_and2(Var_float *self, Var_int *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&&self->value);
}
static Arithmetical op_and3(Var_float *self, Var_float *loperand)
{
	return (Arithmetical)Var_int_new(loperand->value&&self->value);
}
static long to_long(Var_float *self)
{
	return self->value;
}
static long long to_long_long(Var_float *self)
{
	return self->value;
}
static float to_float(Var_float *self)
{
	return self->value;
}
static double to_double(Var_float *self)
{
	return self->value;
}
static bool to_bool(Var_float *self)
{
	return !!self->value;
}

static const struct vtable_Var vtable_Var=
{
	cast_offset(Var_float, Var),

	(void (*)(Var *, Var *))set,
	(void (*)(Var *, Var_null *))set2,
	(void (*)(Var *, Var_int *))set2,
	(void (*)(Var *, Var_float *))set4,
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

static Var_float constructor(Float number)
{
	Var_float self;
	self.Var=&vtable_Var;

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
long (*Var_float_to_long)(Var_float *self)=to_long;
long long (*Var_float_to_long_long)(Var_float *self)=to_long_long;
float (*Var_float_to_float)(Var_float *self)=to_float;
double (*Var_float_to_double)(Var_float *self)=to_double;
#ifdef X32
	Int (*Var_float_to_Int)(Var_float *self)=to_long;
	Float (*Var_float_to_Float)(Var_float *self)=to_float;
#endif
#ifdef X64
	Int (*Var_float_to_Int)(Var_float *self)=to_long_long;
	Float (*Var_float_to_Float)(Var_float *self)=to_double;
#endif
bool (*Var_float_to_bool)(Var_float *self)=to_bool;

Var_float (*Var_float_new)(Float number)=constructor;