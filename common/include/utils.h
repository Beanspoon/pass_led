#ifndef UTILS_H
#define UTILS_H

#include <stdint-gcc.h>

#define ONE_SECOND_IN_MS    1000u

#define BITMASK(val)    (1U << val)

/**
 * @brief Copy data from source memory to destination memory
 * 
 * @param pDest Pointer to the destination memory
 * @param pSource Pointer to the source memory
 * @param length Length of the data to be transferred
 */
void memcpy( void *pDest, const void *pSource, uint32_t length );

#endif  // UTILS_H