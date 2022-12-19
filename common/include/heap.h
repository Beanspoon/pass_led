#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

/**
 * @brief Initialises the heap memory allocator
 * 
 */
void heap_init(void);

/**
 * @brief Allocates heap memory
 * 
 * @param[in] size The size of the memory to be allocated in bytes
 * @return void* pointer to the allocated memory
 */
void* malloc(const size_t size);

/**
 * @brief Free allocated memory
 * 
 * @param[in] ptr Pointer to the memory to be freed
 */
void free(void *ptr);

#endif // HEAP_H