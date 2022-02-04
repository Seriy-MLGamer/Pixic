#include <Pixic/core/variable/Var_null>

#include "stdio.h"
#include <Pixic/core/variable/Var>
#include <Pixic/core/variable/Var_int>
#include <Pixic/core/variable/Var_float>

#define denull(function)\
	printf("Variable \"%s\" is not defined. Default value: 0.\n", self->name);\
	return (*(Var_int *)self=Var_int_new(0)).Var->function;

static Var
	set(Var_null *self, Var *value),
	set2(Var_null *self, Var_int *value),
	set3(Var_null *self, Var_float *value),
	mod(Var_null *self, Var *operand),
	mod2(Var_null *self, Var_int *operand),
	mod3(Var_null *self, Var_float *operand),
	div(Var_null *self, Var *operand),
	div2(Var_null *self, Var_int *operand),
	div3(Var_null *self, Var_float *operand),
	idiv(Var_null *self, Var *operand),
	idiv2(Var_null *self, Var_int *operand),
	idiv3(Var_null *self, Var_float *operand),
	mul(Var_null *self, Var *operand),
	mul2(Var_null *self, Var_int *operand),
	mul3(Var_null *self, Var_float *operand),
	not(Var_null *self),
	bnot(Var_null *self),
	add(Var_null *self, Var *operand),
	add2(Var_null *self, Var_int *operand),
	add3(Var_null *self, Var_float *operand),
	neg(Var_null *self),
	sub(Var_null *self, Var *operand),
	sub2(Var_null *self, Var_int *operand),
	sub3(Var_null *self, Var_float *operand),
	rsh(Var_null *self, Var *operand),
	rsh2(Var_null *self, Var_int *operand),
	rsh3(Var_null *self, Var_float *operand),
	lsh(Var_null *self, Var *operand),
	lsh2(Var_null *self, Var_int *operand),
	lsh3(Var_null *self, Var_float *operand),
	eq(Var_null *self, Var *operand),
	eq2(Var_null *self, Var_int *operand),
	eq3(Var_null *self, Var_float *operand),
	neq(Var_null *self, Var *operand),
	neq2(Var_null *self, Var_int *operand),
	neq3(Var_null *self, Var_float *operand),
	less(Var_null *self, Var *operand),
	less2(Var_null *self, Var_int *operand),
	less3(Var_null *self, Var_float *operand),
	great(Var_null *self, Var *operand),
	great2(Var_null *self, Var_int *operand),
	great3(Var_null *self, Var_float *operand),
	leq(Var_null *self, Var *operand),
	leq2(Var_null *self, Var_int *operand),
	leq3(Var_null *self, Var_float *operand),
	geq(Var_null *self, Var *operand),
	geq2(Var_null *self, Var_int *operand),
	geq3(Var_null *self, Var_float *operand),
	bor(Var_null *self, Var *operand),
	bor2(Var_null *self, Var_int *operand),
	bor3(Var_null *self, Var_float *operand),
	bxor(Var_null *self, Var *operand),
	bxor2(Var_null *self, Var_int *operand),
	bxor3(Var_null *self, Var_float *operand),
	band(Var_null *self, Var *operand),
	band2(Var_null *self, Var_int *operand),
	band3(Var_null *self, Var_float *operand),
	or(Var_null *self, Var *operand),
	or2(Var_null *self, Var_int *operand),
	or3(Var_null *self, Var_float *operand),
	and(Var_null *self, Var *operand),
	and2(Var_null *self, Var_int *operand),
	and3(Var_null *self, Var_float *operand);
static long to_long(Var_null *self);
static long long to_long_long(Var_null *self);
static float to_float(Var_null *self);
static double to_double(Var_null *self);
static bool to_bool(Var_null *self);
static const struct vtable_Var vtable_Var=
{
	cast_offset(Var_null, Var),

	(Var (*)(Var *, Var *))set,
	(Var (*)(Var *, Var_int *))set2,
	(Var (*)(Var *, Var_float *))set3,
	(Var (*)(Var *, Var *))mod,
	(Var (*)(Var *, Var_int *))mod2,
	(Var (*)(Var *, Var_float *))mod3,
	(Var (*)(Var *, Var *))div,
	(Var (*)(Var *, Var_int *))div2,
	(Var (*)(Var *, Var_float *))div3,
	(Var (*)(Var *, Var *))idiv,
	(Var (*)(Var *, Var_int *))idiv2,
	(Var (*)(Var *, Var_float *))idiv3,
	(Var (*)(Var *, Var *))mul,
	(Var (*)(Var *, Var_int *))mul2,
	(Var (*)(Var *, Var_float *))mul3,
	(Var (*)(Var *))not,
	(Var (*)(Var *))bnot,
	(Var (*)(Var *, Var *))add,
	(Var (*)(Var *, Var_int *))add2,
	(Var (*)(Var *, Var_float *))add3,
	(Var (*)(Var *))neg,
	(Var (*)(Var *, Var *))sub,
	(Var (*)(Var *, Var_int *))sub2,
	(Var (*)(Var *, Var_float *))sub3,
	(Var (*)(Var *, Var *))rsh,
	(Var (*)(Var *, Var_int *))rsh2,
	(Var (*)(Var *, Var_float *))rsh3,
	(Var (*)(Var *, Var *))lsh,
	(Var (*)(Var *, Var_int *))lsh2,
	(Var (*)(Var *, Var_float *))lsh3,
	(Var (*)(Var *, Var *))eq,
	(Var (*)(Var *, Var_int *))eq2,
	(Var (*)(Var *, Var_float *))eq3,
	(Var (*)(Var *, Var *))neq,
	(Var (*)(Var *, Var_int *))neq2,
	(Var (*)(Var *, Var_float *))neq3,
	(Var (*)(Var *, Var *))less,
	(Var (*)(Var *, Var_int *))less2,
	(Var (*)(Var *, Var_float *))less3,
	(Var (*)(Var *, Var *))great,
	(Var (*)(Var *, Var_int *))great2,
	(Var (*)(Var *, Var_float *))great3,
	(Var (*)(Var *, Var *))leq,
	(Var (*)(Var *, Var_int *))leq2,
	(Var (*)(Var *, Var_float *))leq3,
	(Var (*)(Var *, Var *))geq,
	(Var (*)(Var *, Var_int *))geq2,
	(Var (*)(Var *, Var_float *))geq3,
	(Var (*)(Var *, Var *))bor,
	(Var (*)(Var *, Var_int *))bor2,
	(Var (*)(Var *, Var_float *))bor3,
	(Var (*)(Var *, Var *))bxor,
	(Var (*)(Var *, Var_int *))bxor2,
	(Var (*)(Var *, Var_float *))bxor3,
	(Var (*)(Var *, Var *))band,
	(Var (*)(Var *, Var_int *))band2,
	(Var (*)(Var *, Var_float *))band3,
	(Var (*)(Var *, Var *))or,
	(Var (*)(Var *, Var_int *))or2,
	(Var (*)(Var *, Var_float *))or3,
	(Var (*)(Var *, Var *))and,
	(Var (*)(Var *, Var_int *))and2,
	(Var (*)(Var *, Var_float *))and3,
	(long (*)(Var *))to_long,
	(long long (*)(Var *))to_long_long,
	(float (*)(Var *))to_float,
	(double (*)(Var *))to_double,
	#ifdef x32
		(Int (*)(Var *))to_long,
		(Float (*)(Var *))to_float,
	#endif
	#ifdef x64
		(Int (*)(Var *))to_long_long,
		(Float (*)(Var *))to_double,
	#endif
	(bool (*)(Var *))to_bool
};
Var_null Var_null_new(const char *name)
{
	Var_null self;
	self.Var=&vtable_Var;

	self.name=name;

	return self;
}
static Var set(Var_null *self, Var *value)
{
	denull(set(&self->Var, value))
}
static Var set2(Var_null *self, Var_int *value)
{
	denull(set2(&self->Var, value))
}
static Var set3(Var_null *self, Var_float *value)
{
	denull(set3(&self->Var, value))
}
static Var mod(Var_null *self, Var *operand)
{
	denull(mod(&self->Var, operand))
}
static Var mod2(Var_null *self, Var_int *operand)
{
	denull(mod2(&self->Var, operand))
}
static Var mod3(Var_null *self, Var_float *operand)
{
	denull(mod3(&self->Var, operand))
}
static Var div(Var_null *self, Var *operand)
{
	denull(div(&self->Var, operand))
}
static Var div2(Var_null *self, Var_int *operand)
{
	denull(div2(&self->Var, operand))
}
static Var div3(Var_null *self, Var_float *operand)
{
	denull(div3(&self->Var, operand))
}
static Var idiv(Var_null *self, Var *operand)
{
	denull(idiv(&self->Var, operand))
}
static Var idiv2(Var_null *self, Var_int *operand)
{
	denull(idiv2(&self->Var, operand))
}
static Var idiv3(Var_null *self, Var_float *operand)
{
	denull(idiv3(&self->Var, operand))
}
static Var mul(Var_null *self, Var *operand)
{
	denull(mul(&self->Var, operand))
}
static Var mul2(Var_null *self, Var_int *operand)
{
	denull(mul2(&self->Var, operand))
}
static Var mul3(Var_null *self, Var_float *operand)
{
	denull(mul3(&self->Var, operand))
}
static Var not(Var_null *self)
{
	denull(not(&self->Var))
}
static Var bnot(Var_null *self)
{
	denull(bnot(&self->Var))
}
static Var add(Var_null *self, Var *operand)
{
	denull(add(&self->Var, operand))
}
static Var add2(Var_null *self, Var_int *operand)
{
	denull(add2(&self->Var, operand))
}
static Var add3(Var_null *self, Var_float *operand)
{
	denull(add3(&self->Var, operand))
}
static Var neg(Var_null *self)
{
	denull(neg(&self->Var))
}
static Var sub(Var_null *self, Var *operand)
{
	denull(sub(&self->Var, operand))
}
static Var sub2(Var_null *self, Var_int *operand)
{
	denull(sub2(&self->Var, operand))
}
static Var sub3(Var_null *self, Var_float *operand)
{
	denull(sub3(&self->Var, operand))
}
static Var rsh(Var_null *self, Var *operand)
{
	denull(rsh(&self->Var, operand))
}
static Var rsh2(Var_null *self, Var_int *operand)
{
	denull(rsh2(&self->Var, operand))
}
static Var rsh3(Var_null *self, Var_float *operand)
{
	denull(rsh3(&self->Var, operand))
}
static Var lsh(Var_null *self, Var *operand)
{
	denull(lsh(&self->Var, operand))
}
static Var lsh2(Var_null *self, Var_int *operand)
{
	denull(lsh2(&self->Var, operand))
}
static Var lsh3(Var_null *self, Var_float *operand)
{
	denull(lsh3(&self->Var, operand))
}
static Var eq(Var_null *self, Var *operand)
{
	denull(eq(&self->Var, operand))
}
static Var eq2(Var_null *self, Var_int *operand)
{
	denull(eq2(&self->Var, operand))
}
static Var eq3(Var_null *self, Var_float *operand)
{
	denull(eq3(&self->Var, operand))
}
static Var neq(Var_null *self, Var *operand)
{
	denull(neq(&self->Var, operand))
}
static Var neq2(Var_null *self, Var_int *operand)
{
	denull(neq2(&self->Var, operand))
}
static Var neq3(Var_null *self, Var_float *operand)
{
	denull(neq3(&self->Var, operand))
}
static Var less(Var_null *self, Var *operand)
{
	denull(less(&self->Var, operand))
}
static Var less2(Var_null *self, Var_int *operand)
{
	denull(less2(&self->Var, operand))
}
static Var less3(Var_null *self, Var_float *operand)
{
	denull(less3(&self->Var, operand))
}
static Var great(Var_null *self, Var *operand)
{
	denull(great(&self->Var, operand))
}
static Var great2(Var_null *self, Var_int *operand)
{
	denull(great2(&self->Var, operand))
}
static Var great3(Var_null *self, Var_float *operand)
{
	denull(great3(&self->Var, operand))
}
static Var leq(Var_null *self, Var *operand)
{
	denull(leq(&self->Var, operand))
}
static Var leq2(Var_null *self, Var_int *operand)
{
	denull(leq2(&self->Var, operand))
}
static Var leq3(Var_null *self, Var_float *operand)
{
	denull(leq3(&self->Var, operand))
}
static Var geq(Var_null *self, Var *operand)
{
	denull(geq(&self->Var, operand))
}
static Var geq2(Var_null *self, Var_int *operand)
{
	denull(geq2(&self->Var, operand))
}
static Var geq3(Var_null *self, Var_float *operand)
{
	denull(geq3(&self->Var, operand))
}
static Var bor(Var_null *self, Var *operand)
{
	denull(bor(&self->Var, operand))
}
static Var bor2(Var_null *self, Var_int *operand)
{
	denull(bor2(&self->Var, operand))
}
static Var bor3(Var_null *self, Var_float *operand)
{
	denull(bor3(&self->Var, operand))
}
static Var bxor(Var_null *self, Var *operand)
{
	denull(bxor(&self->Var, operand))
}
static Var bxor2(Var_null *self, Var_int *operand)
{
	denull(bxor2(&self->Var, operand))
}
static Var bxor3(Var_null *self, Var_float *operand)
{
	denull(bxor3(&self->Var, operand))
}
static Var band(Var_null *self, Var *operand)
{
	denull(band(&self->Var, operand))
}
static Var band2(Var_null *self, Var_int *operand)
{
	denull(band2(&self->Var, operand))
}
static Var band3(Var_null *self, Var_float *operand)
{
	denull(band3(&self->Var, operand))
}
static Var or(Var_null *self, Var *operand)
{
	denull(or(&self->Var, operand))
}
static Var or2(Var_null *self, Var_int *operand)
{
	denull(or2(&self->Var, operand))
}
static Var or3(Var_null *self, Var_float *operand)
{
	denull(or3(&self->Var, operand))
}
static Var and(Var_null *self, Var *operand)
{
	denull(and(&self->Var, operand))
}
static Var and2(Var_null *self, Var_int *operand)
{
	denull(and2(&self->Var, operand))
}
static Var and3(Var_null *self, Var_float *operand)
{
	denull(and3(&self->Var, operand))
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