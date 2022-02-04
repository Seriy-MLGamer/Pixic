#include "classes/tokens/String.h"

static bool String_extend_include(Token* self, Token* parent, size_t position);

String String_new(char* file, unsigned long line, char* value)
{
	String self;

	self.Token=Token_new(file, line);

	self.Token.extend_include=String_extend_include;
	self.value=value;
}

static bool String_extend_include(Token* self, Token* parent, size_t position)
{
	return false;
}