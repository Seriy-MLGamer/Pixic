#include <Pixic/core/Property.h>

#include "string.h"
#include "Pixic/core library/algorithms.h"
#include <Pixic/core/classes/Var>

Property Property_new(Hash hash)
{
	Property self;
	self.Var=Var_new2(0);

	self.hash=hash;

	return self;
}