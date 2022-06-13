#pragma once

#include <Pixic/core/Int.h>

typedef enum Language Language;
enum Language
{
	Russian,
	English
};
typedef struct Settings Settings;
struct Settings
{
	Language language;
	Int container_count;
};

extern Settings settings;