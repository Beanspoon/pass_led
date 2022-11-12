#ifndef GPIO_PRV_H
#define GPIO_PRV_H

#include "gpio_hal.h"

#include "types.h"

/**
 * @brief Definition of pin cofiguration registers
 * 
 */
typedef struct
{
    tGpio_dir   DIR             : 1;    // Bit[0] Pin direction
    tGpio_inBuf INPUT_BUFFER    : 1;    // Bit[1] Pin input buffer configuration
    tGpio_pull  PULL            : 2;    // Bit[2-3] Pin pull direction
    uint8_t                     : 0;
    tGpio_drive DRIVE           : 3;    // Bit[8-10] Pin drive configuration
    uint8_t                     : 0;
    tGpio_sense SENSE           : 2;    // Bit[16-17] Pin sense configuration
    RO_reg                      : 0;
} tGpio_pinCnfReg;

/**
 * @brief Definition of GPIO register map
 *
 */
typedef struct
{
    RO_reg          RESERVED_A[0x141];
    RW_reg          OUT;           // 0x504 Write GPIO port
    RW_reg          OUTSET;        // 0x508 Set individual bits in GPIO port
    RW_reg          OUTCLR;        // 0x50C Clear individual bits in GPIO port
    RO_reg          IN;            // 0x510 Read GPIO port
    RW_reg          DIR;           // 0x514 Direction of GPIO pins
    RW_reg          DIRSET;        // 0x518 Direction set register (sets pin to output)
    RW_reg          DIRCLR;        // 0x51C Direction clear register (sets pin to input)
    RW_reg          LATCH;         // 0x520 Latch register indicating which GPIO pins have met criteria set in PIN_CNF[n].SENSE. Write '1' to clear
    RW_reg          DETECTMODE;    // 0x524 Select between default DETECT signal behaviour (0) and LDETECT mode (1)
    RO_reg          RESERVED_B[0x76];
    tGpio_pinCnfReg PINCNF[32];    // 0x700-77C Configuration of GPIO pins
} tGpio_regMap;

#define GPIO_BASE_ADDRESS   0x50000000
#define GPIO                (*((volatile tGpio_regMap *)GPIO_BASE_ADDRESS))

#endif  // GPIO_PRV_H