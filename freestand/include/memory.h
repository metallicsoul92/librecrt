#ifndef FREESTANDING_MEMORY_H
#define FREESTANDING_MEMORY_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

// Function prototypes for the memory allocator
void* malloc(size_t size);
void free(void* ptr);
void* realloc(void* ptr, size_t size);

// Debugging functions
size_t get_free_memory();
size_t get_largest_free_block();
size_t get_total_allocated_memory();

#endif // FREESTANDING_MEMORY_H
