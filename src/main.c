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

void panic( const char filename, const uint16_t line_number)
{
    while(1)
    {
        
    }
}