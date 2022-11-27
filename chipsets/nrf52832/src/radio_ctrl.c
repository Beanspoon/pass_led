#include "radio_ctrl.h"

#include "clock_hal.h"

void radioCtrl_init(void)
{
    clock_startHFClock();
}