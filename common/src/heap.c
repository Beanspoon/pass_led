#include "heap.h"

#include <stdint-gcc.h>
#include <stdbool.h>

extern uint32_t __estack;
extern uint8_t  __ram_end;

/**
 * @brief Structure for heap memory metadata
 * 
 */
typedef struct
{
    tHeap_metadata* pPrevious;      // Pointer to the previous allocation's metadata
    tHeap_metadata* pNext;          // Pointer to the next allocation's metadata
    size_t          sizeAllocated;           // Size of the allocated memory
    uint8_t         memoryStart[];  // Variable length array acting as a pointer to the start of the allocated memory
} tHeap_metadata;

#define HEAP_METADATA_SIZE  (sizeof(tHeap_metadata))

// /**
//  * @brief Context structure for the heap memory allocator
//  * 
//  */
// typedef struct
// {

// } tHeap_context;

// /**
//  * @brief Get the Context object
//  * 
//  * @return tHeap_context* pointer to the context struct
//  */
// static tHeap_context* getContext(void)
// {
//     static tHeap_context context = { 0 };

//     return &context;
// }

void heap_init(void)
{
    tHeap_metadata *pStart = &__estack;
    pStart->sizeAllocated = 0u;
    pStart->pPrevious = NULL;
    pStart->pNext = NULL;
}

/**
 * @brief Returns the number of contiguous free bytes after this memory allocation
 * 
 * @param[in] pReadPosition Pointer to the current memory allocation being read
 * @return size_t indicating how much contiguous free memory there is after this memory allocation
 */
size_t getSizeOfFreeMemoryGap(const tHeap_metadata *pReadPosition)
{
    uint8_t *nextAlloc = (pReadPosition->pNext == NULL) ? &__ram_end : pReadPosition->pNext;
    ptrdiff_t gapToNextAllocation = nextAlloc - pReadPosition->memoryStart;
    return gapToNextAllocation - pReadPosition->sizeAllocated;
}

void* malloc(const size_t size)
{
    size_t requiredSize = size + HEAP_METADATA_SIZE;
    tHeap_metadata *pReadPosition = __estack;
    tHeap_metadata *pNewAlloc = NULL;
    bool searchIncomplete = true;

    while((pReadPosition != NULL) && searchIncomplete)
    {
        size_t freeMemorySize = getSizeOfFreeMemoryGap(pReadPosition);
        // TODO: from here, code is placeholder
        if(requiredSize < freeMemorySize)
        {
            // There is enough free memory to fit the new allocation between this allocation and the next
            // Set up the new allocation
            tHeap_metadata *pNewAlloc = (tHeap_metadata *)(pReadPosition->memoryStart + pReadPosition->sizeAllocated);
            pNewAlloc->pPrevious = pReadPosition;
            pNewAlloc->pNext = pReadPosition->pNext;
            pNewAlloc->sizeAllocated = size;

            // Update the metadata on either side
            pReadPosition->pNext = pNewAlloc;
            tHeap_metadata *pNextAlloc = pNewAlloc->pNext;
            pNextAlloc->pPrevious = pNewAlloc;

            searchIncomplete = false;
        }
        
        pReadPosition = pReadPosition->pNext;
    }
    
    if(searchIncomplete)
    {
        // This is the last allocation in the heap
        ptrdiff_t gapToHeapEnd = &__ram_end - pReadPosition->memoryStart;
        size_t freeMemorySize = gapToHeapEnd - pReadPosition->sizeAllocated;
        if(requiredSize < freeMemorySize)
        {

        }
    }
}