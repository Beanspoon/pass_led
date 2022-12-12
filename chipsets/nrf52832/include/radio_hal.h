#ifndef RADIO_HAL_H
#define RADIO_HAL_H

#include <stdint-gcc.h>

/**
 * @brief Radio base frequency setting
 * 
 */
typedef enum 
{
    RADIO_BASE_FREQUENCY_2400MHZ,
    RADIO_BASE_FREQUENCY_2360MHZ
} tRadio_baseFrequency;

void radio_configureFrequency(const uint8_t channelFrequency, const tRadio_baseFrequency baseFrequency);

#endif  // RADIO_HAL_H