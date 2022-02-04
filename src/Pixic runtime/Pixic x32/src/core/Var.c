#include <Pixic/core/Var>

#include "stdio.h"

#define Var_set_int(var, number)\
{\
	(var).i=(number);\
	(var).type=Type_int;\
}
#define Var_set_float(var, number)\
{\
	(var).f=(number);\
	(var).type=Type_float;\
}
#define Var_denull(var)\
{\
	Var_set_int(*(var), 0)\
	printf("Variable \"%s\" is not initialized. Default value: 0.\n", (var)->name);\
}
#define Var_convert\
	if (self->type==Type_int) return self->i;\
	if (self->type==Type_float) return self->f;\
	if (self->type==Type_null)\
	{\
		Var_denull(self)\
		return self->i;\
	}

Var Var_mod(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		denulled:
		transformed:
		if (operand->type==Type_int)
		{
			result.i%=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i%=(Int)operand->f;
			return result;
		}
		Var_denull(operand)
		result.i%=0;
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, result.f)
		goto transformed;
	}
	Var_denull(self)
	Var_set_int(result, 0)
	goto denulled;
}
Var Var_div(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		Var_set_float(result, result.i)
		goto transformed;
	}
	if (result.type==Type_float)
	{
		denulled:
		transformed:
		if (operand->type==Type_int)
		{
			result.f/=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.f/=operand->f;
			return result;
		}
		Var_denull(operand)
		result.f/=0;
		return result;
	}
	Var_denull(self)
	Var_set_float(result, 0)
	goto denulled;
}
Var Var_idiv(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		denulled:
		transformed:
		if (operand->type==Type_int)
		{
			result.i/=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i/=operand->f;
			return result;
		}
		Var_denull(operand)
		result.i/=0;
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, result.f)
		goto transformed;
	}
	Var_denull(self)
	Var_set_int(result, 0)
	goto denulled;
}
Var Var_mul(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		denulled:
		if (operand->type==Type_int)
		{
			result.i*=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_float(result, result.i)
			result.f*=operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=0;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			result.f*=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.f*=operand->f;
			return result;
		}
		Var_denull(operand)
		result.f*=0;
		return result;
	}
	Var_denull(self)
	Var_set_int(result, 0)
	goto denulled;
}
Var Var_not(Var *self)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		result.i=!result.i;
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, !result.f)
		return result;
	}
	Var_denull(self)
	Var_set_int(result, 1)
	return result;
}
Var Var_bnot(Var *self)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		result.i=~result.i;
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, ~(Int)result.f)
		return result;
	}
	Var_denull(self)
	Var_set_int(result, -1)
	return result;
}
Var Var_add(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i+=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_float(result, result.i)
			result.f+=operand->f;
			return result;
		}
		Var_denull(operand)
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			result.f+=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.f+=operand->f;
			return result;
		}
		Var_denull(operand)
		result.f+=0;
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_null) Var_denull(operand)
	return *operand;
}
Var Var_neg(Var *self)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		result.i=-result.i;
		return result;
	}
	if (result.type==Type_float)
	{
		result.f=-result.f;
		return result;
	}
	Var_denull(self)
	return *self;
}
Var Var_sub(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		denulled:
		if (operand->type==Type_int)
		{
			result.i-=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_float(result, result.i)
			result.f-=operand->f;
			return result;
		}
		Var_denull(operand)
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			result.f-=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.f-=operand->f;
			return result;
		}
		Var_denull(operand)
		result.f-=0;
		return result;
	}
	Var_denull(self)
	Var_set_int(result, 0)
	goto denulled;
}
Var Var_rshift(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		transformed:
		if (operand->type==Type_int)
		{
			result.i>>=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i>>=(Int)operand->f;
			return result;
		}
		Var_denull(operand)
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, result.f)
		goto transformed;
	}
	Var_denull(self)
	return *self;
}
Var Var_lshift(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		transformed:
		if (operand->type==Type_int)
		{
			result.i<<=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i<<=(Int)operand->f;
			return result;
		}
		Var_denull(operand)
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, result.f)
		goto transformed;
	}
	Var_denull(self)
	return *self;
}
Var Var_eq(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i=result.i==operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i==operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=!result.i;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f==operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f==operand->f)
			return result;
		}
		Var_denull(operand)
		Var_set_int(result, result.f==0)
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_int)
	{
		Var_set_int(result, !operand->i)
		return result;
	}
	if (operand->type==Type_float)
	{
		Var_set_int(result, 0==operand->f)
		return result;
	}
	Var_denull(operand)
	Var_set_int(result, 1)
	return result;
}
Var Var_neq(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		denulled:
		if (operand->type==Type_int)
		{
			result.i=result.i!=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i!=operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=result.i!=0;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f!=operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f!=operand->f)
			return result;
		}
		Var_denull(operand)
		Var_set_int(result, result.f!=0)
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_int)
	{
		Var_set_int(result, 0!=operand->i)
		return result;
	}
	if (operand->type==Type_float)
	{
		Var_set_int(result, 0!=operand->f)
		return result;
	}
	Var_denull(operand)
	Var_set_int(result, 0)
	return result;
}
Var Var_less(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i=result.i<operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i<operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=result.i<0;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f<operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f<operand->f)
			return result;
		}
		Var_denull(operand)
		Var_set_int(result, result.f<0)
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_int)
	{
		Var_set_int(result, 0<operand->i)
		return result;
	}
	if (operand->type==Type_float)
	{
		Var_set_int(result, 0<operand->f)
		return result;
	}
	Var_denull(operand)
	Var_set_int(result, 0)
	return result;
}
Var Var_great(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i=result.i>operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i>operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=result.i>0;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f>operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f>operand->f)
			return result;
		}
		Var_denull(operand)
		Var_set_int(result, result.f>0)
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_int)
	{
		Var_set_int(result, 0>operand->i)
		return result;
	}
	if (operand->type==Type_float)
	{
		Var_set_int(result, 0>operand->f)
		return result;
	}
	Var_denull(operand)
	Var_set_int(result, 0)
	return result;
}
Var Var_leq(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i=result.i<=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i<=operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=result.i<=0;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f<=operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f<=operand->f)
			return result;
		}
		Var_denull(operand)
		Var_set_int(result, result.f<=0)
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_int)
	{
		Var_set_int(result, 0<=operand->i)
		return result;
	}
	if (operand->type==Type_float)
	{
		Var_set_int(result, 0<=operand->f)
		return result;
	}
	Var_denull(operand)
	Var_set_int(result, 1)
	return result;
}
Var Var_geq(Var* self, Var* operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i=result.i>=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i>=operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=result.i>=0;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f>=operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f>=operand->f)
			return result;
		}
		Var_denull(operand)
		Var_set_int(result, result.f>=0)
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_int)
	{
		Var_set_int(result, 0>=operand->i)
		return result;
	}
	if (operand->type==Type_float)
	{
		Var_set_int(result, 0>=operand->f)
		return result;
	}
	Var_denull(operand)
	Var_set_int(result, 1)
	return result;
}
Var Var_bor(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		transformed:
		if (operand->type==Type_int)
		{
			result.i|=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i|=(Int)operand->f;
			return result;
		}
		Var_denull(operand)
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, result.f)
		goto transformed;
	}
	Var_denull(self)
	if (operand->type==Type_int) return *operand;
	if (operand->type==Type_float)
	{
		Var_set_int(result, operand->f)
		return result;
	}
	Var_denull(operand)
	return *self;
}
Var Var_bxor(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		transformed:
		if (operand->type==Type_int)
		{
			result.i^=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i^=(Int)operand->f;
			return result;
		}
		Var_denull(operand)
		return result;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, result.f)
		goto transformed;
	}
	Var_denull(self)
	if (operand->type==Type_int) return *operand;
	if (operand->type==Type_float)
	{
		Var_set_int(result, operand->f)
		return result;
	}
	Var_denull(operand)
	return *self;
}
Var Var_band(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		transformed:
		if (operand->type==Type_int)
		{
			result.i&=operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i&=(Int)operand->f;
			return result;
		}
		Var_denull(operand)
		return *operand;
	}
	if (result.type==Type_float)
	{
		Var_set_int(result, result.f)
		goto transformed;
	}
	Var_denull(self)
	return *self;
}
Var Var_or(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i=result.i||operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i||operand->f;
			return result;
		}
		Var_denull(operand)
		result.i=result.i||0;
		return result;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f||operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f||operand->f)
			return result;
		}
		Var_denull(operand)
		Var_set_int(result, result.f||0)
		return result;
	}
	Var_denull(self)
	if (operand->type==Type_int)
	{
		Var_set_int(result, 0||operand->i)
		return result;
	}
	if (operand->type==Type_float)
	{
		Var_set_int(result, 0||operand->f)
		return result;
	}
	Var_denull(operand)
	return *self;
}
Var Var_and(Var *self, Var *operand)
{
	Var result=*self;
	if (result.type==Type_int)
	{
		if (operand->type==Type_int)
		{
			result.i=result.i&&operand->i;
			return result;
		}
		if (operand->type==Type_float)
		{
			result.i=result.i&&operand->f;
			return result;
		}
		Var_denull(operand)
		return *operand;
	}
	if (result.type==Type_float)
	{
		if (operand->type==Type_int)
		{
			Var_set_int(result, result.f&&operand->i)
			return result;
		}
		if (operand->type==Type_float)
		{
			Var_set_int(result, result.f&&operand->f)
			return result;
		}
		Var_denull(operand)
		return *operand;
	}
	Var_denull(self)
	return *self;
}
long Var_to_long(Var *self)
{
	Var_convert
}
float Var_to_float(Var *self)
{
	Var_convert
}
long long Var_to_long_long(Var *self)
{
	Var_convert
}
double Var_to_double(Var *self)
{
	Var_convert
}
bool Var_to_bool(Var *self)
{
	if (self->type==Type_int) return !!self->i;
	if (self->type==Type_float) return !!self->f;
	if (self->type==Type_null)
	{
		Var_denull(self)
		return self->i;
	}
}