#ifndef FIFO_H
#define FIFO_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Status value returned from FIFO buffer functions indicating
 *  the status of the operation
 */
typedef enum
{
    FIFO_STATUS_OK,     // Operation completed successfully
    FIFO_STATUS_ERROR,  // Operation failed
    FIFO_STATUS_EMPTY,  // Circular buffer was empty
    FIFO_STATUS_FULL,   // Circular buffer was full
} tFifo_status;

/**
 * @brief Generic structure of a FIFO buffer instance - used by FIFO buffer
 *  functions to carry out the specified operation
 */
typedef struct
{
    const size_t    elementSize;    // Size of the elements in bytes
    const size_t    bufferSize;     // Size of the buffer in number of elements
    const bool      allowOverwrite; // Is writing to a full buffer allowed?
    void *          pRead;          // Read pointer
    void *          pWrite;         // Write pointer
    void * const    pBuffer;        // Pointer to the buffer in memory
} tFifo_instance;

#define FIFO_CREATE(pBuffer, elementSize, bufferSize, allowOverwrite)   {\
    .pBuffer = pBuffer,\
    .elementSize = elementSize,\
    .bufferSize = bufferSize,\
    .allowIverwrite = allowOverwrite\
    }

/**
 * @brief Write a new element to the FIFO buffer
 * 
 * @param[in,out] pInstance Pointer to the instance of the FIFO buffer
 * @param[in] pElement Pointer to the element to write
 * @return tFifo_status OK if operation successful
 *                      ERROR if operation failed
 *                      FULL if FIFO buffer was full
 * If allowOverwrite is true, FULL indicates that the write operation was completed, but
 * the oldest element was overwritten.
 * If allowOverwrite is false, FULL indicates that the write operation failed as the buffer
 * was already full.
 */
tFifo_status fifo_write(tFifo_instance * const pInstance, const void * const pElement);

/**
 * @brief Read oldest element from the FIFO buffer
 * 
 * @param[in,out] pInstance Pointer to the instance of the FIFO buffer
 * @param[in] pReadBuffer Pointer to buffer to copy the read element into
 * @param[in] peek If true, leave the element on the buffer. If false, remove the element 
 *  from the buffer
 * @return tFifo_status OK if successful
 *                      ERROR if failed
 *                      EMPTY if operation failed due to buffer being empty
 */
tFifo_status fifo_read(tFifo_instance * const pInstance, void * const pReadBuffer, const bool peek);

/**
 * @brief Empty the FIFO buffer
 * 
 * @param[in,out] pInstance Pointer to the instance of the FIFO buffer
 * @return tFifo_status OK if operation is successful
 *                      ERROR if operation failed
 */
tFifo_status fifo_clear(tFifo_instance * const pInstance);

/**
 * @brief Get the status of the FIFO buffer
 * 
 * @param[in,out] pInstance Pointer to the instance of the FIFO buffer
 * @return tFifo_status OK if the buffer contains data but is not full
 *                      ERROR if there was a problem retrieving the buffer status
 *                      EMPTY if the buffer is empty
 *                      FULL if the buffer is full
 */
tFifo_status fifo_getStatus(const tFifo_instance * const pInstance);

#endif  // FIFO_H