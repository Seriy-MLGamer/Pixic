#include <Pixic/core/variable/Var_float>

#include <Pixic/core/variable/Var>
#include <Pixic/core/variable/Var_int>
#include <Pixic/core/variable/Var_null>

static Var
	set(Var_float *self, Var *value),
	set2(Var_float *self, Var_int *value),
	set3(Var_float *self, Var_float *value),
	mod(Var_float *self, Var *operand),
	mod2(Var_float *self, Var_int *operand),
	mod3(Var_float *self, Var_float *operand),
	div(Var_float *self, Var *operand),
	div2(Var_float *self, Var_int *operand),
	div3(Var_float *self, Var_float *operand),
	idiv(Var_float *self, Var *operand),
	idiv2(Var_float *self, Var_int *operand),
	idiv3(Var_float *self, Var_float *operand),
	mul(Var_float *self, Var *operand),
	mul2(Var_float *self, Var_int *operand),
	mul3(Var_float *self, Var_float *operand),
	not(Var_float *self),
	bnot(Var_float *self),
	add(Var_float *self, Var *operand),
	add2(Var_float *self, Var_int *operand),
	add3(Var_float *self, Var_float *operand),
	neg(Var_float *self),
	sub(Var_float *self, Var *operand),
	sub2(Var_float *self, Var_int *operand),
	sub3(Var_float *self, Var_float *operand),
	rsh(Var_float *self, Var *operand),
	rsh2(Var_float *self, Var_int *operand),
	rsh3(Var_float *self, Var_float *operand),
	lsh(Var_float *self, Var *operand),
	lsh2(Var_float *self, Var_int *operand),
	lsh3(Var_float *self, Var_float *operand),
	eq(Var_float *self, Var *operand),
	eq2(Var_float *self, Var_int *operand),
	eq3(Var_float *self, Var_float *operand),
	neq(Var_float *self, Var *operand),
	neq2(Var_float *self, Var_int *operand),
	neq3(Var_float *self, Var_float *operand),
	less(Var_float *self, Var *operand),
	less2(Var_float *self, Var_int *operand),
	less3(Var_float *self, Var_float *operand),
	great(Var_float *self, Var *operand),
	great2(Var_float *self, Var_int *operand),
	great3(Var_float *self, Var_float *operand),
	leq(Var_float *self, Var *operand),
	leq2(Var_float *self, Var_int *operand),
	leq3(Var_float *self, Var_float *operand),
	geq(Var_float *self, Var *operand),
	geq2(Var_float *self, Var_int *operand),
	geq3(Var_float *self, Var_float *operand),
	bor(Var_float *self, Var *operand),
	bor2(Var_float *self, Var_int *operand),
	bor3(Var_float *self, Var_float *operand),
	bxor(Var_float *self, Var *operand),
	bxor2(Var_float *self, Var_int *operand),
	bxor3(Var_float *self, Var_float *operand),
	band(Var_float *self, Var *operand),
	band2(Var_float *self, Var_int *operand),
	band3(Var_float *self, Var_float *operand),
	or(Var_float *self, Var *operand),
	or2(Var_float *self, Var_int *operand),
	or3(Var_float *self, Var_float *operand),
	and(Var_float *self, Var *operand),
	and2(Var_float *self, Var_int *operand),
	and3(Var_float *self, Var_float *operand);
static long to_long(Var_float *self);
static long long to_long_long(Var_float *self);
static float to_float(Var_float *self);
static double to_double(Var_float *self);
static bool to_bool(Var_float *self);
static const struct vtable_Var vtable_Var=
{
	cast_offset(Var_float, Var),

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

Var_float Var_float_new(Float number)
{
	Var_float self;
	self.Var=&vtable_Var;

	self.value=number;

	return self;
}
static Var set(Var_float *self, Var *value)
{
	return (*value)->set3(value, self);
}
static Var set2(Var_float *self, Var_int *value)
{
	return (*(Var_float *)value=*self).Var;
}
static Var set3(Var_float *self, Var_float *value)
{
	value->value=self->value;
	return value->Var;
}
static Var mod(Var_float *self, Var *operand)
{
	return (*operand)->mod3(operand, self);
}
static Var mod2(Var_float *self, Var_int *operand)
{
	operand->value%=(Int)self->value;
	return operand->Var;
}
static Var mod3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new((Int)operand->value%(Int)self->value)).Var;
}
static Var div(Var_float *self, Var *operand)
{
	return (*operand)->div3(operand, self);
}
static Var div2(Var_float *self, Var_int *operand)
{
	return (*(Var_float *)operand=Var_float_new(operand->value/self->value)).Var;
}
static Var div3(Var_float *self, Var_float *operand)
{
	operand->value/=self->value;
	return operand->Var;
}
static Var idiv(Var_float *self, Var *operand)
{
	return (*operand)->idiv3(operand, self);
}
static Var idiv2(Var_float *self, Var_int *operand)
{
	operand->value/=self->value;
	return operand->Var;
}
static Var idiv3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new((Int)operand->value/(Int)self->value)).Var;
}
static Var mul(Var_float *self, Var *operand)
{
	return (*operand)->mul3(operand, self);
}
static Var mul2(Var_float *self, Var_int *operand)
{
	return (*(Var_float *)operand=Var_float_new(operand->value*self->value)).Var;
}
static Var mul3(Var_float *self, Var_float *operand)
{
	operand->value*=self->value;
	return operand->Var;
}
static Var not(Var_float *self)
{
	return (*(Var_int *)self=Var_int_new(!self->value)).Var;
}
static Var bnot(Var_float *self)
{
	return (*(Var_int *)self=Var_int_new(~(Int)self->value)).Var;
}
static Var add(Var_float *self, Var *operand)
{
	return (*operand)->add3(operand, self);
}
static Var add2(Var_float *self, Var_int *operand)
{
	return (*(Var_float *)operand=Var_float_new(operand->value+self->value)).Var;
}
static Var add3(Var_float *self, Var_float *operand)
{
	operand->value+=self->value;
	return operand->Var;
}
static Var neg(Var_float *self)
{
	self->value=-self->value;
	return self->Var;
}
static Var sub(Var_float *self, Var *operand)
{
	return (*operand)->sub3(operand, self);
}
static Var sub2(Var_float *self, Var_int *operand)
{
	return (*(Var_float *)operand=Var_float_new(operand->value-self->value)).Var;
}
static Var sub3(Var_float *self, Var_float *operand)
{
	operand->value-=self->value;
	return operand->Var;
}
static Var rsh(Var_float *self, Var *operand)
{
	return (*operand)->rsh3(operand, self);
}
static Var rsh2(Var_float *self, Var_int *operand)
{
	operand->value>>=(Int)self->value;
	return operand->Var;
}
static Var rsh3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new((Int)operand->value>>(Int)self->value)).Var;
}
static Var lsh(Var_float *self, Var *operand)
{
	return (*operand)->lsh3(operand, self);
}
static Var lsh2(Var_float *self, Var_int *operand)
{
	operand->value<<=(Int)self->value;
	return operand->Var;
}
static Var lsh3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new((Int)operand->value<<(Int)self->value)).Var;
}
static Var eq(Var_float *self, Var *operand)
{
	return (*operand)->eq3(operand, self);
}
static Var eq2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value==self->value;
	return operand->Var;
}
static Var eq3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value==self->value)).Var;
}
static Var neq(Var_float *self, Var *operand)
{
	return (*operand)->neq3(operand, self);
}
static Var neq2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value!=self->value;
	return operand->Var;
}
static Var neq3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value!=self->value)).Var;
}
static Var less(Var_float *self, Var *operand)
{
	return (*operand)->less3(operand, self);
}
static Var less2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value<self->value;
	return operand->Var;
}
static Var less3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value<self->value)).Var;
}
static Var great(Var_float *self, Var *operand)
{
	return (*operand)->great3(operand, self);
}
static Var great2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value>self->value;
	return operand->Var;
}
static Var great3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value>self->value)).Var;
}
static Var leq(Var_float *self, Var *operand)
{
	return (*operand)->leq3(operand, self);
}
static Var leq2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value<=self->value;
	return operand->Var;
}
static Var leq3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value<=self->value)).Var;
}
static Var geq(Var_float *self, Var *operand)
{
	return (*operand)->geq3(operand, self);
}
static Var geq2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value>=self->value;
	return operand->Var;
}
static Var geq3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value>=self->value)).Var;
}
static Var bor(Var_float *self, Var *operand)
{
	return (*operand)->bor3(operand, self);
}
static Var bor2(Var_float *self, Var_int *operand)
{
	operand->value|=(Int)self->value;
	return operand->Var;
}
static Var bor3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new((Int)operand->value|(Int)self->value)).Var;
}
static Var bxor(Var_float *self, Var *operand)
{
	return (*operand)->bxor3(operand, self);
}
static Var bxor2(Var_float *self, Var_int *operand)
{
	operand->value^=(Int)self->value;
	return operand->Var;
}
static Var bxor3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new((Int)operand->value^(Int)self->value)).Var;
}
static Var band(Var_float *self, Var *operand)
{
	return (*operand)->band3(operand, self);
}
static Var band2(Var_float *self, Var_int *operand)
{
	operand->value&=(Int)self->value;
	return operand->Var;
}
static Var band3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new((Int)operand->value&(Int)self->value)).Var;
}
static Var or(Var_float *self, Var *operand)
{
	return (*operand)->or3(operand, self);
}
static Var or2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value||self->value;
	return operand->Var;
}
static Var or3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value||self->value)).Var;
}
static Var and(Var_float *self, Var *operand)
{
	return (*operand)->and3(operand, self);
}
static Var and2(Var_float *self, Var_int *operand)
{
	operand->value=operand->value&&self->value;
	return operand->Var;
}
static Var and3(Var_float *self, Var_float *operand)
{
	return (*(Var_int *)operand=Var_int_new(operand->value&&self->value)).Var;
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