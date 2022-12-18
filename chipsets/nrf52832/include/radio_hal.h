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

/**
 * @brief Logical address enum
 *
 */
typedef enum
{
    RADIO_LOGADDR_PRIMARY,
    RADIO_LOGADDR1,
    RADIO_LOGADDR2,
    RADIO_LOGADDR3,
    RADIO_LOGADDR4,
    RADIO_LOGADDR5,
    RADIO_LOGADDR6,
    RADIO_LOGADDR7
} tRadio_logicalAddress;

/**
 * @brief Radio base address length enum
 * 
 */
typedef enum
{
    RADIO_2_BYTE_BASE_ADDRESS = 2,
    RADIO_3_BYTE_BASE_ADDRESS = 3,
    RADIO_4_BYTE_BASE_ADDRESS = 4
} tRadio_baseAddressLength;

typedef enum
{
    RADIO_LITTLE_ENDIAN,
    RADIO_BIG_ENDIAN
} tRadio_endianness;

typedef enum
{
    RADIO_CRC_DISABLED,
    RADIO_1_BYTE_CRC,
    RADIO_2_BYTE_CRC,
    RADIO_3_BYTE_CRC
} tRadio_crcLength;

typedef enum
{
    RADIO_CRC_INCLUDE_ADDRESS,
    RADIO_CRC_SKIP_ADDRESS
} tRadio_crcAddressBehaviour;

void radio_configureFrequency(const uint8_t channelFrequency, const tRadio_baseFrequency baseFrequency);

#endif  // RADIO_HAL_H