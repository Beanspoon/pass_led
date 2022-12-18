#ifndef BOARD_CFG_H
#define BOARD_CFG_H

#include "gpio_hal.h"
#include "radio_hal.h"

#include "utils.h"

// GPIO
#define BTN0    GPIO_PIN13
#define BTN1    GPIO_PIN14

#define LED0    GPIO_PIN17
#define LED1    GPIO_PIN18

// CORE
#define SYSTICK_TICK_FREQUENCY_HZ  1000u
#define CORE_CLOCK_FREQUENCY_HZ    64000000u

// RADIO
#define RADIO_BASE_FREQUENCY                RADIO_BASE_FREQUENCY_2360MHZ
#define RADIO_CHANNEL_FREQUENCY             0u

#define DATA_WHITENING_IV                   13u

#define RADIO_PRIMARY_ADDRESS_PREFIX        0xde
#define RADIO_PRIMARY_ADDRESS_BASE          0xadbeef00
#define RADIO_BASE_ADDRESS_LENGTH           RADIO_3_BYTE_BASE_ADDRESS
#define RADIO_RX_ADDRESS                    RADIO_LOGADDR_PRIMARY

#define RADIO_PACKET_PREAMBLE_LENGTH        RADIO_8_BIT_PREAMBLE
#define RADIO_PACKET_S0_LENGTH              0u
#define RADIO_PACKET_LENGTH_FIELD_LENGTH    4u
#define RADIO_PACKET_S1_LENGTH              0u
#define RADIO_S1_INCLUSION                  RADIO_AUTO_INCLUDE_S1
#define RADIO_PACKET_MAX_PAYLOAD_LENGTH     8u
#define RADIO_PACKET_STATIC_LENGTH          0u
#define RADIO_PACKET_ENDIANNESS             RADIO_LITTLE_ENDIAN

#define RADIO_CRC_LENGTH                    RADIO_3_BYTE_CRC
#define RADIO_CRC_ADDRESS_BEHAVIOUR         RADIO_CRC_SKIP_ADDRESS
#define RADIO_CRC_IV                        0x555555
#define RADIO_CRC_POLYNOMIAL                BITMASK(10u) |\
                                            BITMASK(9u) |\
                                            BITMASK(6u) |\
                                            BITMASK(4u) |\
                                            BITMASK(3u) |\
                                            BITMASK(1u) |\
                                            BITMASK(0u)

#endif