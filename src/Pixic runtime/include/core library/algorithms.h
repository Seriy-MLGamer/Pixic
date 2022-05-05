#pragma once

#include "stddef.h"

typedef unsigned long Hash;

/**
 * CRC-32 IEEE 802.3 hash function.
 * @param data any data.
 * @param size size of data block in bytes.
 * @return Hash of data block.
 */
extern Hash (*hash)(const void *data, size_t size);