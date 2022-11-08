#include "rng_hal.h"
#include "rng_prv.h"

#include "utils.h"

void rng_init(void)
{
    RNG.CONFIG.DERCEN = ENABLED;
}

tRng_status rng_generate(void *pBuffer, const size_t size)
{
    rng_init();
    
    tRng_status operation_status = RNG_ERROR;
    uint8_t *pBufferByte = pBuffer;
    RNG.EVENTS_VALRDY = 0U;
    RNG.TASKS_START = ENABLED;

    for(size_t bufferOffset = 0U; bufferOffset < size; ++bufferOffset)
    {
        while(!RNG.EVENTS_VALRDY) { /* Block execution until value is ready */ }
        pBufferByte[bufferOffset] = RNG.VALUE.VALUE;
        RNG.EVENTS_VALRDY = 0u;
    }
}