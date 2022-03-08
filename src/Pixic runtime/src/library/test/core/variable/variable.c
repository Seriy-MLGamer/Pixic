#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include <Pixic/core/variable/Arithmetical>
#include <Pixic/core/variable/Var>

/*
pc - Pixilang Constants and literals.
ps - Pixilang String IDs.
pv - global Pixilang Variables.
pf - Pixilang Functions.
pl - Pixilang Local functional variables and arguments.
pa - Pixilang Arithmetical temporary variables.
*/

static Var_int pc2000, pc4000, pc5, pc1, pc0, pc2, pc3, pc4;
static Var_float pc10_4, pc2_86, pc20_1m, pc4_84m;
static Arithmetical pvwidth, pvheight, pvpattern_length, pvpattern_number, pvstart, pvy, pvx, pvend;

static void Pixic_vars_init()
{
	pc2000=Var_int_new(2000);
	pc4000=Var_int_new(4000);
	pc5=Var_int_new(5);
	pc1=Var_int_new(1);
	pc0=Var_int_new(0);
	pc10_4=Var_float_new(10.4);
	pc2_86=Var_float_new(2.86);
	pc2=Var_int_new(2);
	pc20_1m=Var_float_new(-20.1);
	pc3=Var_int_new(3);
	pc4_84m=Var_float_new(-4.84);
	pc4=Var_int_new(4);

	pvwidth.n=Var_null_new("width");
	pvheight.n=Var_null_new("height");
	pvpattern_length.n=Var_null_new("pattern_length");
	pvpattern_number.n=Var_null_new("pattern_number");
	pvstart.n=Var_null_new("start");
	pvy.n=Var_null_new("y");
	pvx.n=Var_null_new("x");
	pvend.n=Var_null_new("end");
}
int main()
{
	Pixic_vars_init();

	//width=2000
	pvwidth.i=pc2000;
	//height=4000
	pvheight.i=pc4000;
	//array=new(width, height, FLOAT32)
	float *array=malloc(sizeof(float)*(pvwidth.n.Var->to_Int(&pvwidth.n.Var)*pvheight.n.Var->to_Int(&pvheight.n.Var)));
	//pattern=new(5, 1, FLOAT32)
	float *pattern=malloc(sizeof(float)*(pc5.value*pc1.value));
	//pattern[0]=10.4
	pattern[pc0.value]=pc10_4.value;
	//pattern[1]=2.86
	pattern[pc1.value]=pc2_86.value;
	//pattern[2]=-20.1
	pattern[pc2.value]=pc20_1m.value;
	//pattern[3]=-4.84
	pattern[pc3.value]=pc4_84m.value;
	//pattern[4]=2
	pattern[pc4.value]=pc2.value;
	//pattern_length=get_size(pattern)
	pvpattern_length.i=pc5;
	//pattern_number=0
	pvpattern_number.i=pc0;
	//start=get_timer()
	pvstart.i=Var_int_new(clock());
	//for (y=0; y!=height; y+1)
	pvy.i=pc0;
	for1:
	{
		Arithmetical pa1=pvy.n.Var->op_neq(&pvy.n.Var, &pvheight.n.Var);
		if (pa1.i.value)
		{
			//for (x=0; x!=width; x+1)
			pvx.i=pc0;
			for2:
			{
				Arithmetical pa1=pvx.n.Var->op_neq(&pvx.n.Var, &pvwidth.n.Var);
				if (pa1.i.value)
				{
					//array[x, y]=pattern[pattern_number]
					array[pvx.n.Var->to_Int(&pvx.n.Var)+pvy.n.Var->to_Int(&pvy.n.Var)*2000]=pattern[pvpattern_number.n.Var->to_Int(&pvpattern_number.n.Var)];
					//pattern_number+1
					pvpattern_number=pvpattern_number.n.Var->op_add2(&pvpattern_number.n.Var, &pc1);
					//pattern_number%pattern_length
					pvpattern_number=pvpattern_number.n.Var->op_mod(&pvpattern_number.n.Var, &pvpattern_length.n.Var);
					for_continue2:
					pvx=pvx.n.Var->op_add2(&pvx.n.Var, &pc1);
					goto for2;
				}
			}
			for_continue1:
			pvy=pvy.n.Var->op_add2(&pvy.n.Var, &pc1);
			goto for1;
		}
	}
	//end=get_timer()-start
	{
		Var_int end=Var_int_new(clock());
		pvend=Var_int_op_sub(&end, &pvstart.n.Var);
	}
	//logf(
	//"%f %f
	//%f %f
	//Speed: %li op/ms.\n",
	//array[0, 0], array[width-1, 0], array[0, height-1], array[width-1, height-1], (width*height) div end)
	printf(
		"%f %f\n"
		"%f %f\n"
		"Speed: %li op/ms.\n",
	array[0+0*2000], array[1999+0*2000], array[0+3999*2000], array[1999+3999*2000], (2000*4000)/pvend.i.value);
	free(array);
	free(pattern);
	return 0;
}