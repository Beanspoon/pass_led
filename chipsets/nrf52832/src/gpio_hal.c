#include "gpio_prv.h"

#include "utils.h"

void gpio_configureInputPin(const tGpio_pin pin,
                            const tGpio_pull pullDir,
                            const tGpio_sense sense)
{
    GPIO.PINCNF[pin].DIR = GPIO_DIR_INPUT;
    GPIO.PINCNF[pin].INPUT_BUFFER = GPIO_INBUF_CONNECT;
    GPIO.PINCNF[pin].PULL = pullDir;
    GPIO.PINCNF[pin].SENSE = sense;
}

void gpio_configureOutputPin(const tGpio_pin pin,
                                const tGpio_drive drive)
{
    GPIO.PINCNF[pin].DIR = GPIO_DIR_OUTPUT;
    GPIO.PINCNF[pin].INPUT_BUFFER = GPIO_INBUF_DISCONNECT;
    GPIO.PINCNF[pin].DRIVE = drive;
}

void gpio_writePin(const tGpio_pin pin,
                    const tGpio_pinState state)
{
    *(&GPIO.OUTSET + state) = BITMASK(pin);
}