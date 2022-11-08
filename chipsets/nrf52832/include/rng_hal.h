#ifndef RNG_HAL_H
#define RNG_HAL_H

#include <stddef.h>

/**
 * @brief Value indicating the status of an operation
 * 
 */
typedef enum
{
    RNG_OK,
    RNG_ERROR
} tRng_status;

/**
 * @brief Generate a random value and place it in the buffer
 *  This function blocks execution until the random number is generated
 * 
 * @param[in,out]   buffer the buffer into which the value should be placed
 * @param[in]       size the size of the buffer in bytes
 * @return tRng_status indicating the success or failure of the operation
 */
tRng_status rng_generate(void *buffer, const size_t size);

#endif  // RNG_HAL_H