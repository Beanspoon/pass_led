#include "fifo.h"

#include "utils.h"

#include <stdint-gcc.h>

/**
 * @brief Find the next location for the pointer given that it will be advanced by one element
 * This will take into account wrapping if the end of the buffer is reached
 * 
 * @param[in] pointer The pointer in question
 * @param pInstance Pointer to the FIFO buffer instance with which the pointer is associated
 * @return void* indicating the new address to which the pointer will be pointing
 */
static void* getNextLocationForPointer(const void* const pointer, const tFifo_instance* const pInstance)
{
    const uint8_t * const pByteAligned = (uint8_t *)pointer;
    const uint8_t *pNextLocation = pByteAligned + pInstance->elementSize;
    const size_t bufferSize_bytes = pInstance->elementSize * pInstance->bufferSize;
    const uint8_t * const pStart = (uint8_t *)pInstance->pBuffer;
    pNextLocation = (pNextLocation < pStart + bufferSize_bytes) ? pNextLocation : pStart;
    return (void *)pNextLocation;
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