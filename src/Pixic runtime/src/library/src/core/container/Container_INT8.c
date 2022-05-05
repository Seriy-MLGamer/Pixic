#include <core/container/Container_INT8.h>

#include <string.h>
#include <Pixic/core/variable/Arithmetical.h>

void Container_INT8_set_element(Container_INT8 *self, Int x, Int y, Var *value)
{
	Int width=self->width;
	Int index=x+y*width;
	if (index>=0&&index<width*self->height) self->array[index]=((Var_f)value->f)->to_int(value);
}
Arithmetical Container_INT8_get_element(Container_INT8 *self, Int x, Int y)
{
	Int width=self->width;
	Int index=x+y*width;
	if (index>=0&&index<width*self->height) return (Arithmetical)Var_int_new(self->array[index]);
	return (Arithmetical)Var_int_new(0);
}
void Container_INT8_clean(Container_INT8 *self, Var *value)
{
	memset(self->array, ((Var_f)value->f)->to_int(value), self->width*self->height);
}
static const struct Container_f f=
{
	(void (*)(void *, Int, Int, Var *))Container_INT8_set_element,
	(Arithmetical (*)(void *, Int, Int))Container_INT8_get_element, 
	(void (*)(void *, Var *))Container_INT8_clean
};
Container_INT8 Container_INT8_new(Int width, Int height, unsigned long flags)
{
	Container_INT8 self;
	*(Container *)&self=Container_new(width, height, flags);
	self.f=&f;

	self.array=new_array(char, width*height);

	return self;
}