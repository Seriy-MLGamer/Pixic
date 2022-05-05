#include <Pixic/core/Container_data.h>

#include <Pixic/core/Property.h>
#include <Pixic/core/Var.h>

inline Property *search_property(Container_data *container_data, Hash property)
{
	for (Property *a=container_data->last_property; a; a=a->prev) if (a->hash==property) return a;
	return NULL;
}
Container_data Container_data_new()
{
	Container_data self;

	self.last_property=NULL;

	return self;
}
void Container_data_new_property(Container_data *self, const char *name)
{
	Property *property=new(Property, 1);
	*property=Property_new(name);
	property->prev=self->last_property;
	property->next=NULL;
	if (self->last_property) self->last_property->next=property;
	self->last_property=property;
}
void Container_data_delete_property(Container_data *self, Hash property)
{
	Property *property=search_property(self, property);
	if (property) delete(property);
}