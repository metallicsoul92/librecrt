#include "memory.h"
#include "../../crt/include/stdbool.h"
#include "../../crt/include/string.h"

// Configuration
#define HEAP_SIZE 1024 * 1024  // 1 MB heap size
#define ALIGNMENT 8            // 8-byte alignment for all allocations

typedef struct FreeBlock {
    size_t size;
    struct FreeBlock* next;
} FreeBlock;

static unsigned char heap[HEAP_SIZE];
static size_t heap_top = 0;
static FreeBlock* free_list = NULL;
static size_t total_allocated = 0;  // Track total allocated memory

// Utility function to align memory sizes
static size_t align_size(size_t size) {
    return (size + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);
}

void* malloc(size_t size) {
    if (size == 0) {
        return NULL; // Handle zero size allocation
    }

    size = align_size(size);

    // Check if there is a suitable free block
    FreeBlock** prev = &free_list;
    FreeBlock* block = free_list;
    while (block) {
        if (block->size >= size) {
            // Found a block that is large enough
            if (block->size > size + sizeof(FreeBlock)) {
                // Split the block if it's significantly larger than needed
                FreeBlock* new_block = (FreeBlock*)((unsigned char*)block + size);
                new_block->size = block->size - size;
                new_block->next = block->next;
                *prev = new_block;
            } else {
                // Use the whole block
                *prev = block->next;
            }

            total_allocated += block->size;
            return (void*)(block);
        }
        prev = &block->next;
        block = block->next;
    }

    // No suitable block found, allocate from the heap
    if (heap_top + size > HEAP_SIZE) {
        return NULL; // Out of memory
    }

    void* ptr = &heap[heap_top];
    heap_top += size;
    total_allocated += size;

    return ptr;
}

void free(void* ptr) {
    if (!ptr) {
        return;
    }

    FreeBlock* block = (FreeBlock*)ptr;
    block->next = free_list;
    free_list = block;

    total_allocated -= block->size;

    // Coalesce adjacent free blocks to reduce fragmentation
    FreeBlock* current = free_list;
    while (current && current->next) {
        if ((unsigned char*)current + current->size == (unsigned char*)current->next) {
            current->size += current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}

void* realloc(void* ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size); // If ptr is NULL, realloc behaves like malloc
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    size = align_size(size);

    FreeBlock* old_block = (FreeBlock*)ptr;
    if (old_block->size >= size) {
        // If the current block is large enough, return the same pointer
        return ptr;
    }

    // Allocate new memory block
    void* new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL; // Out of memory
    }

    // Copy the old data to the new location
    size_t copy_size = old_block->size < size ? old_block->size : size;
    memcpy(new_ptr, ptr, copy_size);

    // Free the old block
    free(ptr);

    return new_ptr;
}

// Debugging functions
size_t get_free_memory() {
    return HEAP_SIZE - heap_top;
}

size_t get_largest_free_block() {
    size_t largest = 0;
    FreeBlock* block = free_list;
    while (block) {
        if (block->size > largest) {
            largest = block->size;
        }
        block = block->next;
    }
    return largest;
}

size_t get_total_allocated_memory() {
    return total_allocated;
}
