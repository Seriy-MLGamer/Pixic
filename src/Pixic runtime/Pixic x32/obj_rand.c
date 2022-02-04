#include <Pixic/core/variable/Var_null>
#include <Pixic/core/variable/Var_int>
#include <Pixic/core/variable/Var_float>
#include <Pixic/core/variable/Arithmetical>
#include <Pixic/core/variable/Var>

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
 * pa - Pixilang Arithmetical pointers to registers.
 */

static Arithmetical registers[32];
static size_t register_position=0;
static Var_int pc0, pc1, pc12345, pc32767, pc65536, pc9999989, pc9999999, pc10000000, pc1103515245;
static Arithmetical pvRAND_MAX, pvnext, pva;

//fn c_rand()
Arithmetical pfc_rand(Arithmetical *registers, size_t *position, unsigned long argument_count, ...)
{
	va_list argument_list;
	va_start(argument_list, argument_count);
	Var *pa0=&registers[*position].n.Var;
	Var *pa1=&registers[*position+1].n.Var;

	//next=next*1103515245+12345
	*position++;
	(*pa0)
		->set(pa0, &pvnext.n.Var)
		->mul(pa0, &pc1103515245.Var)
		->add(pa0, &pc12345.Var);
	*position--;
	pvnext.n.Var->set(&pvnext.n.Var, pa0);
	//ret((next div 65536)%(RAND_MAX+1))
	*position++;
	(*pa0)
		->set(pa0, &pvnext.n.Var)
		->idiv(pa0, &pc65536.Var);
	*position++;
	(*pa1)
		->set(pa1, &pvRAND_MAX.n.Var)
		->add(pa1, &pc1.Var);
	*position--;
	(*pa0)->mod(pa0, pa1);
	*position--;
	va_end(argument_list);
	return *(Arithmetical *)pa0;
}

static void Pixic_vars_init()
{
	for (size_t a=0; a!=32; a++) registers[a].i=Var_int_new(0);
	pc0=Var_int_new(0); pc1=Var_int_new(1); pc12345=Var_int_new(12345); pc32767=Var_int_new(32767); pc65536=Var_int_new(65536); pc9999989=Var_int_new(9999989); pc9999999=Var_int_new(9999999); pc10000000=Var_int_new(10000000); pc1103515245=Var_int_new(1103515245);
	pvRAND_MAX.n=Var_null_new("RAND_MAX"); pvnext.n=Var_null_new("next"); pva.n=Var_null_new("a");
}

int main()
{
	Pixic_vars_init();

	Var *pa0=&registers[0].n.Var;

	//RAND_MAX=32767
	pvRAND_MAX.i=pc32767;
	//next=1
	pvnext.i=pc1;
	short *array=malloc(20000000);
	clock_t start=clock();
	//a=0
	pva.i=pc0;
	//while a!=10000000
	while0:
	register_position++;
	(*pa0)
		->set(pa0, &pva.n.Var)
		->neq(pa0, &pc10000000.Var);
	register_position--;
	if ((*pa0)->to_bool(pa0))
	{
		register_position++;
		*(Arithmetical *)pa0=pfc_rand(registers, &register_position, 0);
		register_position--;
		array[pva.n.Var->to_Int(&pva.n.Var)]=(*pa0)->to_long(pa0);
		//a+1
		pva.n.Var->add(&pva.n.Var, &pc1.Var);
		goto while0;
	}
	printf("%lu ms\n", clock()-start);
	//a=9999999
	pva.i=pc9999999;
	//while a!=9999989
	while1:
	register_position++;
	(*pa0)
		->set(pa0, &pva.n.Var)
		->neq(pa0, &pc9999989.Var);
	register_position--;
	if ((*pa0)->to_bool(pa0))
	{
		printf("%hi\n", array[pva.n.Var->to_Int(&pva.n.Var)]);
		//a-1
		pva.n.Var->sub(&pva.n.Var, &pc1.Var);
		goto while1;
	}
}