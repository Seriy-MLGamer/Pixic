#include <hash table/Hash_map.h>

#include <stdio.h>
#include <hash table/system/Pair.h>

#define min_fill_coeff .25f
#define max_fill_coeff .5f

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
	if (self->pairs)
	{
		size_t array_size=length(self->pairs);
		Hash key_hash=hash(key);
		Pair **pair=self->pairs+key_hash%array_size;
		for (Pair *a=*pair; a; a=a->next) if (compare_strings(a->key, key))
		{
			a->value=value;
			return;
		}
		size_t pair_count=self->pair_count;
		self->pair_count++;
		if ((float)(pair_count+1)/array_size>=max_fill_coeff)
		{
			array_size=(pair_count+1)/min_fill_coeff;
			Pair **new_pairs=new_array(Pair *, array_size);
			clean(new_pairs);
			for (Pair **a=self->pairs; pair_count; a++)
			{
				Pair *b=*a;
				while (b)
				{
					Pair *next=b->next;
					Pair **pair=new_pairs+b->hash%array_size;
					b->prev=NULL;
					if (*pair)
					{
						(*pair)->prev=b;
						b->next=*pair;
					}
					else b->next=NULL;
					*pair=b;
					pair_count--;
					b=next;
				}
			}
			delete(self->pairs);
			self->pairs=new_pairs;
			pair=new_pairs+key_hash%array_size;
		}
		Pair *new_pair=new(Pair);
		*new_pair=(Pair){key_hash, key, value, NULL};
		if (*pair)
		{
			(*pair)->prev=new_pair;
			new_pair->next=*pair;
		}
		else new_pair->next=NULL;
		*pair=new_pair;
	}
	else
	{
		self->pairs=new_array(Pair *, 1); 
		Pair *pair=new(Pair);
		*pair=(Pair){hash(key), key, value, NULL, NULL};
		*self->pairs=pair;
		self->pair_count=1;
	}
}
char *Hash_map_get(Hash_map *self, const char *key)
{
	if (self->pairs) for (Pair *a=self->pairs[hash(key)%length(self->pairs)]; a; a=a->next) if (compare_strings(a->key, key)) return a->value;
	return "";
}
void Hash_map_unset(Hash_map *self, const char *key)
{
	if (self->pairs)
	{
		Pair **pair=self->pairs+hash(key)%length(self->pairs);
		for (Pair *a=*pair; a; a=a->next) if (compare_strings(a->key, key))
		{
			self->pair_count--;
			if (self->pair_count)
			{
				if (self->pair_count!=1)
				{
					if (a->prev)
					{
						if (a->next)
						{
							a->prev->next=a->next;
							a->next->prev=a->prev;
						}
						else a->prev->next=NULL;
					}
					else if (a->next)
					{
						a->next->prev=NULL;
						*pair=a->next;
					}
					else *pair=NULL;
					size_t pair_count=self->pair_count;
					if ((float)pair_count/length(self->pairs)<min_fill_coeff)
					{
						size_t array_size=pair_count/max_fill_coeff;
						Pair **new_pairs=new_array(Pair *, array_size);
						clean(new_pairs);
						for (Pair **a=self->pairs; pair_count; a++)
						{
							Pair *b=*a;
							while (b)
							{
								Pair *next=b->next;
								Pair **pair=new_pairs+b->hash%array_size;
								b->prev=NULL;
								if (*pair)
								{
									(*pair)->prev=b;
									b->next=*pair;
								}
								else b->next=NULL;
								*pair=b;
								pair_count--;
								b=next;
							}
						}
						delete(self->pairs);
						self->pairs=new_pairs;
					}
				}
				else if (a->prev)
				{
					a->prev->next=NULL;
					delete(self->pairs);
					self->pairs=new_array(Pair *, 1);
					*self->pairs=a->prev;
				}
				else if (a->next)
				{
					a->next->prev=NULL;
					delete(self->pairs);
					self->pairs=new_array(Pair *, 1);
					*self->pairs=a->next;
				}
				else
				{
					pair=self->pairs;
					while (!*pair) pair++;
					Pair *found=*pair;
					delete(self->pairs);
					self->pairs=new_array(Pair *, 1);
					*self->pairs=found;
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
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("\"hash\": 0x%08X,\n", c->hash);
				for (size_t a=-2; a!=b; a++) printf("    ");
				printf("\"key\": \"%s\",\n", c->key);
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