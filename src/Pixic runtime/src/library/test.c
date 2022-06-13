#include <Pixic/Pixic.h>

#include <stdio.h>
#include <time.h>

/**
 * pc - Pixilang Constants and literals.
 * ps - Pixilang String IDs.
 * pv - global Pixilang Variables.
 * pf - Pixilang Functions.
 * pl - Pixilang Local functional variables and arguments.
 * pa - Pixilang Arithmetical temporary variables.
 */

static Var pc0, pc1, pc12345, pc32767, pc65536, pc999989, pc999999, pc1000000, pc1103515245;
static Var pvRAND_MAX, pvnext, pvarray, pva;

static inline void init()
{
	pc0=Var_new2(0); pc1=Var_new2(1); pc12345=Var_new2(12345); pc32767=Var_new2(32767); pc65536=Var_new2(65536); pc999989=Var_new2(999989); pc999999=Var_new2(999999); pc1000000=Var_new2(1000000); pc1103515245=Var_new2(1103515245);
	pvRAND_MAX=Var_new("RAND_MAX"); pvnext=Var_new("next"); pvarray=Var_new("array"); pva=Var_new("a");
}

//fn c_rand()
Var pfc_rand(uint32_t argument_count, ...)
{
	va_list arguments;
	//next=next*1103515245+12345
	{
		pvnext=Var_mul(&pvnext, &pc1103515245);
		pvnext=Var_add(&pvnext, &pc12345);
	}
	//ret((next div 65536)%(RAND_MAX+1))
	{
		Var pa0=Var_idiv(&pvnext, &pc65536);
		Var pa1=Var_add(&pvRAND_MAX, &pc1);
		return Var_mod(&pa0, &pa1);
	}
}

void app()
{
	init();

	//RAND_MAX=32767
	pvRAND_MAX=pc32767;
	//next=1
	pvnext=pc1;
	//array=new(1000000, 1, INT16)
	pvarray=pfnew(3, pc1000000, pc1, pcINT16);
	clock_t start=clock();
	//a=0
	pva=pc0;
	//while a!=1000000
	{
		Var pa0;
		while0:
		pa0=Var_neq(&pva, &pc1000000);
		if (Var_to_bool(&pa0))
		{
			//array[a]=c_rand()
			{
				Var pa0=pfc_rand(0);
				set_element(&pvarray, &pva, &pa0);
			}
			//a+1
			pva=Var_add(&pva, &pc1);
			goto while0;
		}
	}
	printf("%lu ms\n", (clock()-start)*1000/CLOCKS_PER_SEC);
	//a=999999
	pva=pc999999;
	//while a!=999989
	{
		Var pa0;
		while1:
		pa0=Var_neq(&pva, &pc999989);
		if (Var_to_bool(&pa0))
		{
			Var result=get_element(&pvarray, &pva);
			printf("%i\n", Var_to_int(&result));
			//a-1
			pva=Var_sub(&pva, &pc1);
			goto while1;
		}
	}
}