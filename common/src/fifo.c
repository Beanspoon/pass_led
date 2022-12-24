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
    const size_t bufferSize_bytes = pInstance->elementSize * pInstance->numElements;
    const uint8_t * const pStart = (uint8_t *)pInstance->pBuffer;
    pNextLocation = (pNextLocation < pStart + bufferSize_bytes) ? pNextLocation : pStart;
    return (void *)pNextLocation;
}

tFifo_status fifo_write(tFifo_instance* const pInstance, const void* const pElement)
{
    const tFifo_status bufferStatus = fifo_getStatus(pInstance);
    if(bufferStatus == FIFO_STATUS_ERROR)
    {
        // Early return for error state
        return FIFO_STATUS_ERROR;
    }

    const bool isFull = (bufferStatus == FIFO_STATUS_FULL);
    if(isFull && !pInstance->allowOverwrite)
    {
        // Early return if buffer is full and overwriting is forbidden
        return FIFO_STATUS_FULL;
    }

    memcpy(pInstance->pWrite, pElement, pInstance->elementSize);

    pInstance->pWrite = getNextLocationForPointer(pInstance->pWrite, pInstance);

    if(isFull)
    {
        // Read pointer must also be updated as oldest element has been overwritten
        pInstance->pRead = getNextLocationForPointer(pInstance->pRead, pInstance);
    }

    return FIFO_STATUS_OK;
}

tFifo_status fifo_read(tFifo_instance* const pInstance, void * const pReadBuffer, const bool peek)
{
    const tFifo_status instanceStatus = fifo_getStatus(pInstance);
    if(instanceStatus == FIFO_STATUS_ERROR ||
        pReadBuffer == NULL)
    {
        // Early return due to invalid arguments
        return FIFO_STATUS_ERROR;
    }
    else if(instanceStatus == FIFO_STATUS_EMPTY)
    {
        // Early return as there is nothing to read
        return FIFO_STATUS_EMPTY;
    }

    memcpy(pReadBuffer, pInstance->pRead, pInstance->elementSize);

    if(!peek)
    {
        pInstance->pRead = getNextLocationForPointer(pInstance->pRead, pInstance);
    }
}

tFifo_status fifo_getStatus(const tFifo_instance* const pInstance)
{
    // Early return for invalid argument
    if(pInstance == NULL ||
        pInstance->pRead == NULL ||
        pInstance->pWrite == NULL)
    {
        return FIFO_STATUS_ERROR;
    }

    if(pInstance->pRead == pInstance->pWrite)
    {
        // If the pointers point to the same element, the buffer is empty
        return FIFO_STATUS_EMPTY;
    }
    else if(getNextLocationForPointer(pInstance->pWrite, pInstance) == pInstance->pRead)
    {
        // If the read pointer is one element ahead of the write pointer, the buffer is full
        return FIFO_STATUS_FULL;
    }
    else
    {
        return FIFO_STATUS_OK;
    }
}