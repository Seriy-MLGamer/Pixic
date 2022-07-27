#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t Hash;

/**
 * CRC-32 IEEE 802.3 hash function.
 * @param data any data.
 * @param size size of the data block in bytes.
 * @return Hash of data block.
 */
Hash hash(const char *data);