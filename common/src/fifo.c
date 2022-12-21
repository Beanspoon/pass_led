#include "fifo.h"

#include "utils.h"

#include <stdint-gcc.h>

static void UpdatePointer(const void * pointer, const tFifo_instance * const pInstance)
{
    
}

tFifo_status fifo_write(tFifo_instance * const pInstance, const void * const pElement)
{
    if(pInstance == NULL ||
        pElement == NULL ||
        pInstance->pBuffer == NULL ||
        pInstance->pWrite == NULL)
    {
        return FIFO_STATUS_ERROR;
    }

    const uint8_t *pRead = pInstance->pRead;
    uint8_t *pWrite = pInstance->pWrite;
    bool isFull = (pRead == (pWrite + pInstance->elementSize));

    if(isFull && !pInstance->allowOverwrite)
    {
        return FIFO_STATUS_FULL;
    }

    memcpy(pWrite, pElement, pInstance->elementSize);

    uint8_t *pNextWrite = pWrite + pInstance->elementSize;
    uint8_t *pStart = pInstance->pBuffer;
    size_t bufferSize_bytes = pInstance->bufferSize * pInstance->elementSize;
    pInstance->pWrite = (pNextWrite >= pStart + bufferSize_bytes) ? pStart : pNextWrite;

    if(isFull)
    {
        // Read pointer must also be updated
        uint8_t *pNextRead = pRead + 
    }
}