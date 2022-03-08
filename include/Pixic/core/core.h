#pragma once

#include <Pixic/core/typedefs/variable/Arithmetical>
#include <Pixic/core/typedefs/container/Container>

extern Arithmetical (**functions)(unsigned long argument_count, ...);

int Pixic_init();
int Pixic_deinit();