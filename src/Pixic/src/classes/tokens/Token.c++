#include "classes/tokens/Token.h"

#include "stdio.h"
#include "Pixic.h"

static bool Token_extend_include(Token* self, Token* parent, size_t position);

Token Token_new(char* file, unsigned long line)
{
	Token self;

	self.file=file;
	self.line=line;

	self.childs=0;
	self.child_count=0;
	self.extend_include=Token_extend_include;

	return self;
}

static bool Token_extend_include(Token* self, Token* parent, size_t position)
{
	fprintf(stderr, "%s: warning: bool extend_include(Token* parent, size_t position) in Token %p isn't defined.\n", *arguments, self);
	return false;
}