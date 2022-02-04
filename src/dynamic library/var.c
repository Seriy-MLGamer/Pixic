#include "core/var.h"

#define set_int(var, number)\
{\
	(var).i=(number);\
	(var).type=TYPE_INT;\
}
#define set_float(var, number)\
{\
	(var).f=(number);\
	(var).type=TYPE_FLOAT;\
}

inline void denull(var* var)
{
	set_int(*var, 0)
	system_log("Variable \"%s\" is not initialized. Default value: 0.\n", var->name);
}
var ivar_mod(var* self, var* operand)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		denulled1:
		transformed:
		if (operand->type==TYPE_INT)
		{
			denulled2:
			result.i%=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			result.i%=(INT)operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			goto denulled2;
		}
	}
	if (result.type==TYPE_FLOAT)
	{
		set_int(result, result.f)
		goto transformed;
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		set_int(result, 0)
		goto denulled1;
	}
}
var ivar_div(var* self, var* operand)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		set_float(result, result.i)
		goto transformed;
	}
	if (result.type==TYPE_FLOAT)
	{
		denulled1:
		transformed:
		if (operand->type==TYPE_INT)
		{
			denulled2:
			result.f/=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			result.f/=operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			goto denulled2;
		}
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		set_float(result, 0.f)
		goto denulled1;
	}
}
var ivar_div_int(var* self, var* operand)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		denulled1:
		transformed:
		if (operand->type==TYPE_INT)
		{
			denulled2:
			result.i/=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			self->i/=operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			goto denulled2;
		}
	}
	if (result.type==TYPE_FLOAT)
	{
		set_int(result, result.f)
		goto transformed;
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		set_int(result, 0)
		goto denulled1;
	}
}
var ivar_mul(var* self, var* operand)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		denulled1:
		if (operand->type==TYPE_INT)
		{
			denulled2:
			result.i*=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			set_float(result, result.i)
			result.f*=operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			goto denulled2;
		}
	}
	if (result.type==TYPE_FLOAT)
	{
		if (operand->type==TYPE_INT)
		{
			denulled3:
			result.f*=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			result.f*=operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			goto denulled3;
		}
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		set_int(result, 0)
		goto denulled1;
	}
}
var ivar_not(var* self)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		result.i=!result.i;
		return result;
	}
	if (result.type==TYPE_FLOAT)
	{
		set_int(result, !result.f)
		return result;
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		set_int(result, 1);
		return result;
	}
}
var ivar_bnot(var* self)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		result.i=~result.i;
		return result;
	}
	if (result.type==TYPE_FLOAT)
	{
		set_int(result, ~(INT)result.f)
		return result;
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		#ifdef x32
			set_int(result, 0xFFFFFFFF);
		#endif
		#ifdef x64
			set_int(result, 0xFFFFFFFFFFFFFFFF);
		#endif
		return result;
	}
}
var ivar_add(var* self, var* operand)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		if (operand->type==TYPE_INT)
		{
			result.i+=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			set_float(result, result.i)
			result.f+=operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			return result;
		}
	}
	if (result.type==TYPE_FLOAT)
	{
		if (operand->type==TYPE_INT)
		{
			result.f+=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			result.f+=operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			return result;
		}
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		if (operand->type==TYPE_NULL) denull(operand);
		return *operand;
	}
}
var ivar_neg(var* self)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		result.i=-result.i;
		return result;
	}
	if (result.type==TYPE_FLOAT)
	{
		result.f=-result.f;
		return result;
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		return *self;
	}
}
var ivar_sub(var* self, var* operand)
{
	var pe0=ivar_neg(operand);
	return ivar_add(self, &pe0);
	/*if (self->type==TYPE_INT)
	{
		denulled1:
		if (operand->type==TYPE_INT)
		{
			denulled2:
			self->i-=self->i;
			return self;
		}
		if (operand->type==TYPE_FLOAT)
		{
			var_new5(self, self->i);
			self->f-=self->f;
			return self;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			goto denulled2;
		}
	}
	if (self->type==TYPE_FLOAT)
	{
		if (operand->type==TYPE_INT)
		{
			denulled3:
			self->f-=self->i;
			return self;
		}
		if (operand->type==TYPE_FLOAT)
		{
			self->f-=self->f;
			return self;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			goto denulled3;
		}
	}
	if (self->type==TYPE_NULL)
	{
		denull(self);
		goto denulled1;
	}*/
}
var ivar_rshift(var* self, var* operand)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		denulled:
		transformed:
		if (operand->type==TYPE_INT)
		{
			result.i>>=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			result.i>>=(INT)operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			return result;
		}
	}
	if (result.type==TYPE_FLOAT)
	{
		set_int(result, result.f)
		goto transformed;
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		goto denulled;
	}
}
var ivar_lshift(var* self, var* operand)
{
	var result=*self;
	if (result.type==TYPE_INT)
	{
		denulled:
		transformed:
		if (operand->type==TYPE_INT)
		{
			result.i<<=operand->i;
			return result;
		}
		if (operand->type==TYPE_FLOAT)
		{
			result.i<<=(INT)operand->f;
			return result;
		}
		if (operand->type==TYPE_NULL)
		{
			denull(operand);
			return result;
		}
	}
	if (result.type==TYPE_FLOAT)
	{
		set_int(result, result.f)
		goto transformed;
	}
	if (result.type==TYPE_NULL)
	{
		denull(self);
		goto denulled;
	}
}
var ivar_eq(var* self, var* operand);
var ivar_neq(var* self, var* operand);
var ivar_less(var* self, var* operand);
extern var* (*var_great)(var* self, var* operand);
extern var* (*var_lesseq)(var* self, var* operand);
extern var* (*var_greateq)(var* self, var* operand);
extern var* (*var_bor)(var* self, var* operand);
extern var* (*var_bxor)(var* self, var* operand);
extern var* (*var_band)(var* self, var* operand);
extern var* (*var_or)(var* self, var* operand);
extern var* (*var_and)(var* self, var* operand);
long var_to_long(var* self)
{
	if (self->type==TYPE_INT) denulled: return self->i;
	if (self->type==TYPE_FLOAT) return self->f;
	if (self->type==TYPE_NULL)
	{
		denull(self);
		goto denulled;
	}
}
float var_to_float(var* self)
{
	if (self->type==TYPE_INT) denulled: return self->i;
	if (self->type==TYPE_FLOAT) return self->f;
	if (self->type==TYPE_NULL)
	{
		denull(self);
		goto denulled;
	}
}
long long var_to_long_long(var* self)
{
	if (self->type==TYPE_INT) denulled: return self->i;
	if (self->type==TYPE_FLOAT) return self->f;
	if (self->type==TYPE_NULL)
	{
		denull(self);
		goto denulled;
	}
}
double var_to_double(var* self)
{
	if (self->type==TYPE_INT) denulled: return self->i;
	if (self->type==TYPE_FLOAT) return self->f;
	if (self->type==TYPE_NULL)
	{
		denull(self);
		goto denulled;
	}
}