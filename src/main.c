#include "rng_hal.h"
#include "gpio_hal.h"

#include "panic.h"

#include "board_cfg.h"

#include <stdint-gcc.h>

void main( void )
{
    // Generate ID
    uint32_t nodeId;
    if(rng_generate(&nodeId, sizeof(nodeId)) != RNG_OK)
    {
        panic();
    }

    // Configure GPIO
    gpio_configureInputPin(BTN0, GPIO_PULL_UP, GPIO_SENSE_DISABLED);
    gpio_configureInputPin(BTN1, GPIO_PULL_UP, GPIO_SENSE_DISABLED);

    gpio_configureOutputPin(LED0, GPIO_DRIVE_S0S1);
    gpio_configureOutputPin(LED1, GPIO_DRIVE_S0S1);

    while( 1 ) {}
}