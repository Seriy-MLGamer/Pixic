#include <core/container/Container_INT16.h>

#include <wchar.h>
#include <Pixic/core/variable/Arithmetical.h>

void Container_INT16_set_element(Container_INT16 *self, Int x, Int y, Var *value)
{
	Int width=self->width;
	Int index=x+y*width;
	if (index>=0&&index<width*self->height) self->array[index]=((Var_f)value->f)->to_int(value);
}
Arithmetical Container_INT16_get_element(Container_INT16 *self, Int x, Int y)
{
	Int width=self->width;
	Int index=x+y*width;
	if (index>=0&&index<width*self->height) return (Arithmetical)Var_int_new(self->array[index]);
	return (Arithmetical)Var_int_new(0);
}
void Container_INT16_clean(Container_INT16 *self, Var *value)
{
	wmemset(self->array, ((Var_f)value->f)->to_int(value), self->width*self->height);
}
static const struct Container_f f=
{
	(void (*)(void *, Int, Int, Var *))Container_INT16_set_element,
	(Arithmetical (*)(void *, Int, Int))Container_INT16_get_element, 
	(void (*)(void *, Var *))Container_INT16_clean
};
Container_INT16 Container_INT16_new(Int width, Int height, unsigned long flags)
{
	Container_INT16 self;
	*(Container *)&self=Container_new(width, height, flags);
	self.f=&f;

	self.array=new_array(short, width*height);

	return self;
}