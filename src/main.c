#include "rng_hal.h"

#include "panic.h"

#include <stdint-gcc.h>

void main( void )
{
    uint32_t nodeId;
    if(rng_generate(&nodeId, sizeof(nodeId)) != RNG_OK)
    {
        panic();
    }
    while( 1 ) {}
}