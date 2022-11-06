#include "rng_hal.h"
#include "rng_prv.h"

#include "utils.h"

void rng_init(void)
{
    RNG.CONFIG.DERCEN = ENABLED;
    RNG.INTENSET = BITMASK(RNG_INTERRUPT_VALRDY);
}

tRng_status (rng_generate)(void *pBuffer, const size_t size)
{
    uint8_t *pBufferByte = pBuffer;
    RNG.TASKS_START = ENABLED;

    for(size_t byteCount = 0U; byteCount < size; ++byteCount)
    {
        
    }
}