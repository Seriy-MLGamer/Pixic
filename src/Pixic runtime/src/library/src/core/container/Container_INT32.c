#include <core/container/Container_INT32.h>

#include <Pixic/core/variable/Arithmetical.h>

void Container_INT32_set_element(Container_INT32 *self, Int x, Int y, Var *value)
{
	Int width=self->width;
	Int index=x+y*width;
	if (index>=0&&index<width*self->height) self->array[index]=((Var_f)value->f)->to_int(value);
}
Arithmetical Container_INT32_get_element(Container_INT32 *self, Int x, Int y)
{
	Int width=self->width;
	Int index=x+y*width;
	if (index>=0&&index<width*self->height) return (Arithmetical)Var_int_new(self->array[index]);
	return (Arithmetical)Var_int_new(0);
}
void Container_INT32_clean(Container_INT32 *self, Var *value)
{
	long result=((Var_f)value->f)->to_int(value);
	long *array=self->array;
	Int size=self->width*self->height;
	for (Int a=0; a!=size; a++) array[a]=result;
}
static const struct Container_f f=
{
	(void (*)(void *, Int, Int, Var *))Container_INT32_set_element,
	(Arithmetical (*)(void *, Int, Int))Container_INT32_get_element, 
	(void (*)(void *, Var *))Container_INT32_clean
};
Container_INT32 Container_INT32_new(Int width, Int height, unsigned long flags)
{
	Container_INT32 self;
	*(Container *)&self=Container_new(width, height, flags);
	self.f=&f;

	self.array=new_array(long, width*height);

	return self;
}