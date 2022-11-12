#include "rng_hal.h"

#include "types.h"

void main( void )
{
    uint8_t node_id;
    if(rng_generate(&node_id, sizeof(node_id)) != RNG_OK)
    {

    }

    while( 1 ) {}
}