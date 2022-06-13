#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <Pixic/core/Int.h>
#include <Pixic/core/Float.h>

#define denull(var)\
	case type_null:\
		printf("Variable \"%s\" is not initialized. Default value: 0.\n", (var)->name);\
		*(var)=Var_new2(0);

typedef enum Var_type Var_type;
enum Var_type
{
	type_null,
	type_int,
	type_float
};
/**
 * Dynamic Pixilang variable that can have 2 types: int and float.
 */
typedef struct Var Var;
struct Var
{
	Var_type type;
	union
	{
		const char *name;
		Int i;
		Float f;
	};
};
inline Var Var_new(const char *name)
{
	Var self;

	self.type=type_null;
	self.name=name;

	return self;
}
inline Var Var_new2(Int number)
{
	Var self;

	self.type=type_int;
	self.i=number;

	return self;
}
inline Var Var_new3(Float number)
{
	Var self;

	self.type=type_float;
	self.f=number;

	return self;
}
inline void Var_denull(Var *self)
{
	if (self->type==type_null)
	{
		printf("Variable \"%s\" is not initialized. Default value: 0.\n", self->name);
		*self=Var_new2(0);
	}
}
inline void Var_set(Var *self, Var *value)
{
	Var_denull(value);
	*self=*value;
}
inline Int Var_to_int(Var *self)
{
	switch (self->type)
	{
		denull(self)
		return 0;
		case type_int: return self->i;
		case type_float: return self->f;
	}
}
inline Float Var_to_float(Var *self)
{
	switch (self->type)
	{
		denull(self)
		return 0;
		case type_int: return self->i;
		case type_float: return self->f;
	}
}
inline bool Var_to_bool(Var *self)
{
	switch (self->type)
	{
		denull(self);
		return false;
		case type_int: return self->i;
		case type_float: return self->f;
	}
}
inline Var Var_mod(Var *self, Var *operand)
{
	return Var_new2(Var_to_int(self)%Var_to_int(operand));
}
inline Var Var_div(Var *self, Var *operand)
{
	return Var_new3(Var_to_float(self)/Var_to_float(operand));
}
inline Var Var_idiv(Var *self, Var *operand)
{
	return Var_new2(Var_to_int(self)/Var_to_int(operand));
}
inline Var Var_mul(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i*operand->i);
				case type_float: return Var_new3(self->i*operand->f);
			}
		case type_float: return Var_new3(self->f*Var_to_float(operand));
	}
}
inline Var Var_not(Var *self)
{
	return Var_new2(!Var_to_bool(self));
}
inline Var Var_bnot(Var *self)
{
	return Var_new2(~Var_to_int(self));
}
inline Var Var_add(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i+operand->i);
				case type_float: return Var_new3(self->i+operand->f);
			}
		case type_float: return Var_new3(self->f+Var_to_float(operand));
	}
}
inline Var Var_neg(Var *self)
{
	switch (self->type)
	{
		denull(self)
		case type_int: return Var_new2(-self->i);
		case type_float: return Var_new3(-self->f);
	}
}
inline Var Var_sub(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i-operand->i);
				case type_float: return Var_new3(self->i-operand->f);
			}
		case type_float: return Var_new3(self->f-Var_to_float(operand));
	}
}
inline Var Var_rsh(Var *self, Var *operand)
{
	return Var_new2(Var_to_int(self)>>Var_to_int(operand));
}
inline Var Var_lsh(Var *self, Var *operand)
{
	return Var_new2(Var_to_int(self)<<Var_to_int(operand));
}
inline Var Var_eq(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i==operand->i);
				case type_float: return Var_new2(self->i==operand->f);
			}
		case type_float:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->f==operand->i);
				case type_float: return Var_new2(self->f==operand->f);
			}
	}
}
inline Var Var_neq(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i!=operand->i);
				case type_float: return Var_new2(self->i!=operand->f);
			}
		case type_float:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->f!=operand->i);
				case type_float: return Var_new2(self->f!=operand->f);
			}
	}
}
inline Var Var_l(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i<operand->i);
				case type_float: return Var_new2(self->i<operand->f);
			}
		case type_float:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->f<operand->i);
				case type_float: return Var_new2(self->f<operand->f);
			}
	}
}
inline Var Var_g(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i>operand->i);
				case type_float: return Var_new2(self->i>operand->f);
			}
		case type_float:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->f>operand->i);
				case type_float: return Var_new2(self->f>operand->f);
			}
	}
}
inline Var Var_leq(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i<=operand->i);
				case type_float: return Var_new2(self->i<=operand->f);
			}
		case type_float:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->f<=operand->i);
				case type_float: return Var_new2(self->f<=operand->f);
			}
	}
}
inline Var Var_geq(Var *self, Var *operand)
{
	switch (self->type)
	{
		denull(self)
		case type_int:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->i>=operand->i);
				case type_float: return Var_new2(self->i>=operand->f);
			}
		case type_float:
			switch (operand->type)
			{
				denull(operand)
				case type_int: return Var_new2(self->f>=operand->i);
				case type_float: return Var_new2(self->f>=operand->f);
			}
	}
}
inline Var Var_bor(Var *self, Var *operand)
{
	return Var_new2(Var_to_int(self)|Var_to_int(operand));
}
inline Var Var_bxor(Var *self, Var *operand)
{
	return Var_new2(Var_to_int(self)^Var_to_int(operand));
}
inline Var Var_band(Var *self, Var *operand)
{
	return Var_new2(Var_to_int(self)&Var_to_int(operand));
}
inline Var Var_or(Var *self, Var *operand)
{
	return Var_new2(Var_to_bool(self)||Var_to_bool(operand));
}
inline Var Var_and(Var *self, Var *operand)
{
	return Var_new2(Var_to_bool(self)&&Var_to_bool(operand));
}

#undef denull