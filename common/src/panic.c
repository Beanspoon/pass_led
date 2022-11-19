#include "panic.h"

#include "core_systick_hal.h"
#include "board_cfg.h"
#include "gpio_hal.h"

void panic_handler(const char *filename, const uint16_t lineNumber)
{
    systick_init();
    gpio_configureOutputPin(LED0, GPIO_DRIVE_S0S1);
    gpio_configureOutputPin(LED1, GPIO_DRIVE_S0S1);
    while(1)
    {
        gpio_writePin(LED0, LOW);
        gpio_writePin(LED1, LOW);
        systick_busyWait(1000u);
        gpio_writePin(LED0, HIGH);
        gpio_writePin(LED1, HIGH);
        systick_busyWait(1000u);
    }
}