#include <Pixic/core/Var>

#include "stdarg.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

/**
 * pc - Pixilang Constants and literals.
 * ps - Pixilang String IDs.
 * pv - global Pixilang Variables.
 * pf - Pixilang Functions.
 * pl - Pixilang Local functional variables and arguments.
 * pa - Pixilang Arithmetical temporary variables.
 */

static Var pc0, pc1, pc12345, pc32767, pc65536, pc9999989, pc9999999, pc10000000, pc1103515245;
static Var pvRAND_MAX, pvnext, pva;

//fn c_rand()
Var pfc_rand(unsigned long argument_count, ...)
{
	va_list argument_list;
	va_start(argument_list, argument_count);
	//next=next*1103515245+12345
	{
		Var pa1=Var_mul(&pvnext, &pc1103515245);
		Var pa0=Var_add(&pa1, &pc12345);
		Var_set(&pvnext, &pa0);
	}
	//ret((next div 65536)%(RAND_MAX+1))
	{
		Var pa2=Var_idiv(&pvnext, &pc65536);
		Var pa1=Var_add(&pvRAND_MAX, &pc1);
		Var pa0=Var_mod(&pa2, &pa1);
		va_end(argument_list);
		return pa0;
	}
}

static void Pixic_vars_init()
{
	pc0=Var_new2(0); pc1=Var_new2(1); pc12345=Var_new2(12345); pc32767=Var_new2(32767); pc65536=Var_new2(65536); pc9999989=Var_new2(9999989); pc9999999=Var_new2(9999999); pc10000000=Var_new2(10000000); pc1103515245=Var_new2(1103515245);
	pvRAND_MAX=Var_new("RAND_MAX"); pvnext=Var_new("next"); pva=Var_new("a");
}

int main()
{
	Pixic_vars_init();

	//RAND_MAX=32767
	Var_set(&pvRAND_MAX, &pc32767);
	//next=1
	Var_set(&pvnext, &pc1);
	short *array=malloc(20000000);
	clock_t start=clock();
	//a=0
	Var_set(&pva, &pc0);
	//while a!=1000000
	{
		Var pa0;
		while0:
		pa0=Var_neq(&pva, &pc10000000);
		if (Var_to_bool(&pa0))
		{
			{
				Var pa0=pfc_rand(0);
				array[Var_to_Int(&pva)]=Var_to_long(&pa0);
			}
			//a+1
			{
				Var pa0=Var_add(&pva, &pc1);
				Var_set(&pva, &pa0);
			}
			goto while0;
		}
	}
	printf("%lu ms\n", clock()-start);
	//a=999999
	Var_set(&pva, &pc9999999);
	//while a!=999989
	{
		Var pa0;
		while1:
		pa0=Var_neq(&pva, &pc9999989);
		if (Var_to_bool(&pa0))
		{
			printf("%hi\n", array[Var_to_Int(&pva)]);
			//a-1
			{
				Var pa0=Var_sub(&pva, &pc1);
				Var_set(&pva, &pa0);
			}
			goto while1;
		}
	}
}