#include "radio_ctrl.h"

#include "radio_hal.h"
#include "clock_hal.h"

#include "board_cfg.h"

void radioCtrl_init(void)
{
    clock_startHFClock();

    radio_configureFrequency(RADIO_CHANNEL_FREQUENCY,
                                RADIO_BASE_FREQUENCY);

    radio_configurePacket(RADIO_PACKET_PREAMBLE_LENGTH,
                            RADIO_PACKET_S0_LENGTH,
                            RADIO_PACKET_LENGTH_FIELD_LENGTH,
                            RADIO_PACKET_S1_LENGTH,
                            RADIO_PACKET_S1_INCLUSION,
                            RADIO_PACKET_MAX_PAYLOAD_LENGTH,
                            RADIO_PACKET_STATIC_LENGTH,
                            RADIO_PACKET_ENDIANNESS);

    radio_configureCrc(RADIO_CRC_LENGTH,
                        RADIO_CRC_IV,
                        RADIO_CRC_POLYNOMIAL,
                        RADIO_CRC_ADDRESS_BEHAVIOUR);

    radio_configureDataWhitening(RADIO_DATA_WHITENING_IV,
                                    ENABLED);

    radio_setBaseAddressLength(RADIO_BASE_ADDRESS_LENGTH);
    radio_setPrimaryAddress(RADIO_PRIMARY_ADDRESS_PREFIX,
                            RADIO_PRIMARY_ADDRESS_BASE);
    radio_configureTxAddress(RADIO_LOGADDR_PRIMARY);
    radio_configureRxAddress(RADIO_LOGADDR_PRIMARY, ENABLED);
}