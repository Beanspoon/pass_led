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
 * 
 * @param[in,out] buffer the buffer into which the value should be placed
 * @return tRng_status 
 */
tRng_status (rng_generate)(void *buffer, const size_t size);
#define rng_generate(buffer)  rng_generate(buffer, sizeof(buffer))

#endif  // RNG_HAL_H