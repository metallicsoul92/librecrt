#ifndef FREESTANDING_MEMORY_H
#define FREESTANDING_MEMORY_H

#ifndef __HAS_STDDEF
#include "../../crt/include/stddef.h"
#define __HAS_STDDEF
#endif

// Function prototypes for the memory allocator

/**
 * @brief Allocates a block of memory of the specified size.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void* malloc(size_t size);

/**
 * @brief Frees a previously allocated block of memory.
 *
 * @param ptr A pointer to the memory block to be freed.
 */
void free(void* ptr);

/**
 * @brief Reallocates a block of memory to a new size.
 *
 * @param ptr A pointer to the memory block to be reallocated.
 * @param size The new size of the memory block.
 * @return A pointer to the newly allocated memory, or NULL if the reallocation fails.
 */
void* realloc(void* ptr, size_t size);

// Debugging functions

/**
 * @brief Returns the amount of free memory available.
 *
 * @return The amount of free memory, in bytes.
 */
size_t get_free_memory();

/**
 * @brief Returns the size of the largest available free memory block.
 *
 * @return The size of the largest free block, in bytes.
 */
size_t get_largest_free_block();

/**
 * @brief Returns the total amount of memory currently allocated.
 *
 * @return The total allocated memory, in bytes.
 */
size_t get_total_allocated_memory();

#endif // FREESTANDING_MEMORY_H
