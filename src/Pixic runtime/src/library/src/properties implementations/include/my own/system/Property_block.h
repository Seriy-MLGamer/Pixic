#pragma once

#include <typedefs/my own/system/Property_block.h>

#include <my own/system/Node_block.h>
#include <typedefs/my own/system/Property.h>
#include <Pixic/core library/C OOP.h>

struct Property_block
{
	Node_block *nodes;
	Property **properties;
};
inline Property_block Property_block_new()
{
	Property_block self;

	self.nodes=new_array(Node_block, 3);
	clean(self.nodes);
	self.properties=new_array(Property *, 1);
	*self.properties=NULL;

	return self;
}