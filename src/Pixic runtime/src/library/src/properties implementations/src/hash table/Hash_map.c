/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#include <hash table/Hash_map.h>

#include <stdio.h>
#include <hash table/system/Pair.h>

#define fill_coeff_min .25f
#define fill_coeff_max .5f

static const struct Map_f f=
{
	(void (*)(void *, const char *, char *))Hash_map_set,
	(char *(*)(void *, const char *))Hash_map_get,
	(void (*)(void *, const char *))Hash_map_unset,
	(void (*)(void *))Hash_map_show,
	(void (*)(void *))Hash_map_remove
};

Hash_map Hash_map_new()
{
	Hash_map self;
	self.f=&f;

	self.pairs=NULL;
	self.pair_count=0;

	return self;
}
inline bool compare_strings(const char *left, const char *right)
{
	while ((*left||*right)&&*left==*right) left++, right++;
	return !(*left||*right);
}
void Hash_map_set(Hash_map *self, const char *key, char *value)
{
	Hash_map_set2(self, hash(key), value);
}
void Hash_map_set2(Hash_map *self, Hash key, char *value)
{
	size_t array_size;
	if (self->pairs)
	{
		array_size=length(self->pairs);
		Pair **pair=self->pairs+key%array_size;
		for (Pair *a=*pair; a; a=a->next) if (a->key==key)
		{
			a->value=value;
			return;
		}
		size_t pair_count=self->pair_count;
		self->pair_count++;
		if ((float)(pair_count+1)/array_size>=fill_coeff_max)
		{
			array_size=(pair_count+1)/fill_coeff_min;
			Pair **new_pairs=new_array(Pair *, array_size);
			clean(new_pairs);
			for (Pair **a=self->pairs; pair_count; a++)
			{
				Pair *b=*a;
				while (b)
				{
					Pair *next=b->next;
					Linked_list_set((Linked_list *)b, (Linked_list **)new_pairs+b->key%array_size);
					pair_count--;
					b=next;
				}
			}
			delete(self->pairs);
			self->pairs=new_pairs;
			pair=new_pairs+key%array_size;
		}
		Pair *new_pair=new(Pair);
		*new_pair=(Pair){.key=key, .value=value};
		Linked_list_set((Linked_list *)new_pair, (Linked_list **)pair);
	}
	else
	{
		array_size=1/fill_coeff_min;
		self->pairs=new_array(Pair *, array_size); 
		Pair *pair=new(Pair);
		*pair=(Pair){NULL, NULL, key, value};
		self->pairs[key%array_size]=pair;
		self->pair_count=1;
	}
}
char *Hash_map_get(Hash_map *self, const char *key)
{
	Hash key_hash=hash(key);
	if (self->pairs) for (Pair *a=self->pairs[key_hash%length(self->pairs)]; a; a=a->next) if (a->key==key_hash) return a->value;
	return "";
}
char *Hash_map_get2(Hash_map *self, Hash key)
{
	if (self->pairs) for (Pair *a=self->pairs[key%length(self->pairs)]; a; a=a->next) if (a->key==key) return a->value;
	return "";
}
void Hash_map_unset(Hash_map *self, const char *key)
{
	Hash_map_unset2(self, hash(key));
}
void Hash_map_unset2(Hash_map *self, Hash key)
{
	if (self->pairs)
	{
		Pair **pair=self->pairs+key%length(self->pairs);
		for (Pair *a=*pair; a; a=a->next) if (a->key==key)
		{
			self->pair_count--;
			if (self->pair_count)
			{
				Linked_list_unset((Linked_list *)a, (Linked_list **)pair);
				size_t pair_count=self->pair_count;
				if ((float)pair_count/length(self->pairs)<fill_coeff_min)
				{
					size_t array_size=pair_count/fill_coeff_max;
					Pair **new_pairs=new_array(Pair *, array_size);
					clean(new_pairs);
					for (Pair **a=self->pairs; pair_count; a++)
					{
						Pair *b=*a;
						while (b)
						{
							Pair *next=b->next;
							Linked_list_set((Linked_list *)b, (Linked_list **)new_pairs+b->key%array_size);
							pair_count--;
							b=next;
						}
					}
					delete(self->pairs);
					self->pairs=new_pairs;
				}
			}
			else
			{
				delete(pair);
				self->pairs=NULL;
			}
			delete(a);
			return;
		}
	}
}
void Hash_map_show(Hash_map *self)
{
	printf("\
{\n\
  \"hash map\": ");
	if (self->pairs)
	{
		printf("[\n");
		Pair **pairs=self->pairs;
		size_t array_size=length(pairs);
		for (size_t a=0; a!=array_size; a++)
		{
			printf("\
    {\n\
      \"pointer\": %p,\n\
      \"data\": ", pairs[a]);
			size_t b=0;
			for (Pair *c=pairs[a]; c; c=c->next, b++)
			{
				printf("{\n");
				/*for (size_t a=-2; a!=b; a++) printf("    ");
				printf("\"hash\": 0x%08X,\n", c->hash);
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("\"key\": \"%s\",\n", c->key);*/
				printf("\"key\": 0x%08X,\n", c->key);
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("\"value\": \"%s\",\n", c->value);
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("\"prev\": {\n");
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("  \"pointer\": %p,\n", c->prev);
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("  \"data\": null\n");
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("},\n");
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("\"next\": {\n");
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("  \"pointer\": %p,\n", c->next);
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("  \"data\": ");
			}
			printf("null");
			for (; b!=0; b--)
			{
				putchar('\n');
				for (size_t a=-1; a!=b; a++) printf("    ");
				printf("}\n");
				for (size_t a=0; a!=b; a++) printf("    ");
				printf("  }");
			}
			printf("\n\
    }");
			if (a!=array_size-1) putchar(',');
			putchar('\n');
		}
		printf("\
  ]");
	}
	else printf("null");
	printf("\n\
}\n");
}
void Hash_map_remove(Hash_map *self)
{
	if (self->pairs)
	{
		size_t pair_count=self->pair_count;
		for (Pair **a=self->pairs; pair_count; a++)
		{
			Pair *b=*a;
			while (b)
			{
				Pair *next=b->next;
				delete(b);
				pair_count--;
				b=next;
			}
		}
		delete(self->pairs);
	}
}