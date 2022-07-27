#include <my own/Tree_map.h>

#include <stdio.h>
#include <string.h>
#include <my own/system/Node_block.h>
#include <my own/system/Property.h>
#include <my own/system/Property_block.h>

static const struct Map_f f=
{
	(void (*)(void *, const char *, char *))Tree_map_set,
	(char *(*)(void *, const char *))Tree_map_get,
	//(void (*)(void *, const char *))Tree_map_unset,
	.show=(void (*)(void *))Tree_map_show
	//(void (*)(void *))Tree_map_remove
};

Tree_map Tree_map_new()
{
	Tree_map self;
	self.f=&f;

	self.zero=NULL;
	self.one=NULL;

	return self;
}
void Tree_map_set(Tree_map *self, const char *key, char *value)
{
	Property_block *branch;
	Property *property=NULL;
	for (; *key; key++)
	{
		int symbol=*key;
		if (symbol&1)
		{
			if (property)
			{
				if (property->one) branch=property->one;
				else
				{
					branch=new(Property_block);
					*branch=Property_block_new();
					property->one=branch;
				}
			}
			else if (self->one) branch=self->one;
			else
			{
				branch=new(Property_block);
				*branch=Property_block_new();
				self->one=branch;
			}
		}
		else if (property)
		{
			if (property->zero) branch=property->zero;
			else
			{
				branch=new(Property_block);
				*branch=Property_block_new();
				property->zero=branch;
			}
		}
		else if (self->zero) branch=self->zero;
		else
		{
			branch=new(Property_block);
			*branch=Property_block_new();
			self->zero=branch;
		}
		Node *block=*branch->nodes;
		Node *node;
		for (int a=0; a!=2; a++)
		{
			node=block;
			for (int b=1+a*3; b!=4+a*3; b++)
			{
				if (symbol&1<<b)
				{
					if (*node&0xF) node=block+(*node&0xF);
					else
					{
						int a=1;
						while (block[a]||block+a==node) a++;
						*node=(*node&0xF0)|a;
						node=block+a;
					}
				}
				else if (*node>>4) node=block+(*node>>4);
				else
				{
					int a=1;
					while (block[a]||block+a==node) a++;
					*node=(a<<4)|(*node&0xF);
					node=block+a;
				}
			}
			if (*node) block=branch->nodes[*node];
			else
			{
				Node_block *nodes=branch->nodes;
				int size=length(nodes);
				int a=1;
				for (; a!=size; a++) if (!*nodes[a]) break;
				*node=a;
				if (a!=size) block=nodes[a];
				else
				{
					resize(branch->nodes, size+1);
					block=branch->nodes[a];
					memset(block, 0, sizeof(Node_block));
				}
			}
		}
		node=block;
		if (symbol&1<<7)
		{
			if (*node&0xF) node=block+(*node&0xF);
			else
			{
				int a=1;
				while (block[a]||block+a==node) a++;
				*node=(*node&0xF0)|a;
				node=block+a;
			}
		}
		else
		{
			if (*node>>4) node=block+(*node>>4);
			else
			{
				int a=1;
				while (block[a]||block+a==node) a++;
				*node=(a<<4)|(*node&0xF);
				node=block+a;
			}
		}
		if (*node) property=branch->properties[*node-1];
		else
		{
			Property **properties=branch->properties;
			int size=length(properties);
			int a=0;
			for (; a!=size; a++) if (!properties[a]) break;
			property=new(Property);
			clean(property);
			if (a!=size) properties[a]=property;
			else
			{
				resize(branch->properties, size+1);
				branch->properties[a]=property;
			}
			*node=a+1;
		}
	}
	if (property) property->value=value;
}
char *Tree_map_get(Tree_map *self, const char *key)
{
	Property_block branch;
	Property *property=NULL;
	for (; *key; key++)
	{
		int symbol=*key;
		if (symbol&1)
		{
			if (property)
			{
				if (property->one) branch=*property->one;
				else return "";
			}
			else if (self->one) branch=*self->one;
			else return "";
		}
		else if (property)
		{
			if (property->zero) branch=*property->zero;
			else return "";
		}
		else if (self->zero) branch=*self->zero;
		else return "";
		Node *block=*branch.nodes;
		Node node;
		for (int a=0; a!=2; a++)
		{
			node=*block;
			for (int b=1+a*3; b!=4+a*3; b++)
			{
				if (symbol&1<<b)
				{
					if (node&0xF) node=block[node&0xF];
					else return "";
				}
				else if (node>>4) node=block[node>>4];
				else return "";
			}
			if (node) block=branch.nodes[node];
			else return "";
		}
		node=*block;
		if (symbol&1<<7)
		{
			if (node&0xF) node=block[node&0xF];
			else return "";
		}
		else if (node>>4) node=block[node>>4];
		else return "";
		if (node) property=branch.properties[node-1];
		else return "";
	}
	if (property) if (property->value) return property->value;
	return "";
}
static void show_property_block(Property_block *block, size_t depth)
{
	printf("{\n");
	for (size_t a=0; a!=depth; a++) printf("  ");
	printf("\"nodes\": [\n");
	int size=length(block->nodes);
	for (int a=0; a!=size; a++)
	{
		for (size_t a=0; a!=depth; a++) printf("  ");
		printf("  [");
		for (int b=0; b!=15; b++)
		{
			printf("0x%02hhX", block->nodes[a][b]);
			if (b!=14) printf(", ");
		}
		putchar(']');
		if (a!=size-1) putchar(',');
		putchar('\n');
	}
	for (size_t a=0; a!=depth; a++) printf("  ");
	printf("],\n");
	for (size_t a=0; a!=depth; a++) printf("  ");
	printf("\"properties\": [\n");
	size=length(block->properties);
	for (int a=0; a!=size; a++)
	{
		for (size_t a=0; a!=depth; a++) printf("  ");
		if (block->properties[a])
		{
			printf("  {\n");
			for (size_t a=0; a!=depth; a++) printf("  ");
			printf("    \"value\": ");
			if (block->properties[a]->value) printf("\"%s\"", block->properties[a]->value);
			else printf("null");
			printf(",\n");
			for (size_t a=0; a!=depth; a++) printf("  ");
			printf("    \"zero\": ");
			if (block->properties[a]->zero) show_property_block(block->properties[a]->zero, depth+3);
			else printf("null");
			printf(",\n");
			for (size_t a=0; a!=depth; a++) printf("  ");
			printf("    \"one\": ");
			if (block->properties[a]->one) show_property_block(block->properties[a]->one, depth+3);
			else printf("null");
			putchar('\n');
			for (size_t a=0; a!=depth; a++) printf("  ");
			printf("  }");
		}
		else printf("null");
		if (a!=size-1) putchar(',');
		putchar('\n');
	}
	for (size_t a=0; a!=depth; a++) printf("  ");
	printf("]\n");
	for (size_t a=1; a!=depth; a++) printf("  ");
	putchar('}');
}
void Tree_map_show(Tree_map *self)
{
	printf("\
{\n\
  \"tree map\": ");
	if (self->zero||self->one)
	{
		printf("{\n\
    \"zero\": ");
		if (self->zero) show_property_block(self->zero, 3);
		else printf("null");
		printf(",\n\
    \"one\": ");
		if (self->one) show_property_block(self->one, 3);
		else printf("null");
		printf("\n\
  }");
	}
	else printf("null");
	printf("\n\
}\n");
}