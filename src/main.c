#include "rng_hal.h"

#include "board_cfg.h"

#include "types.h"

void main( void )
{
    uint8_t nodeId;
    if(rng_generate(&nodeId, sizeof(nodeId)) != RNG_OK)
    {

    }

    while( 1 ) {}
}

void panic(const char filename, const uint16_t lineNumber)
{
    gpio_configureOutputPin(LED0, GPIO_DRIVE_S0S1);
    gpio_configureOutputPin(LED1, GPIO_DRIVE_S0S1);
    while(1)
    {
        
    }
}