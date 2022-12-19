#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

/**
 * @brief Allocates heap memory
 * 
 * @param[in] size The size of the memory to be allocated in bytes
 * @return void* pointer to the allocated memory
 */
void* malloc(const size_t size);

#endif // HEAP_H