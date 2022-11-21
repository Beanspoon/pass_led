#ifndef BOARD_CFG_H
#define BOARD_CFG_H

#include "gpio_hal.h"

#define LED0    GPIO_PIN17
#define LED1    GPIO_PIN18

#define SYSTICK_TICK_FREQUENCY_HZ  1000u
#define CORE_CLOCK_FREQUENCY_HZ    64000000u

#endif