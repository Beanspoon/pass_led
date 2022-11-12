#include "gpio_prv.h"

void gpio_configureInputPin(const tGpio_pin pin)
{
    GPIO.PINCNF[pin].DIR = GPIO_DIR_INPUT;
    GPIO.PINCNF[pin].INPUT_BUFFER = GPIO_INBUF_CONNECT;
    GPIO.PINCNF[pin].PULL = GPIO_PULL_UP;
    GPIO.PINCNF[pin].SENSE = GPIO_SENSE_DISABLED;
}

void gpio_customiseInputPin(const tGpio_pin pin,
                                const tGpio_pull pull,
                                const tGpio_sense sense_type)
{
    GPIO.PINCNF[pin].DIR = GPIO_DIR_INPUT;
    GPIO.PINCNF[pin].INPUT_BUFFER = GPIO_INBUF_CONNECT;
    GPIO.PINCNF[pin].PULL = pull;
    GPIO.PINCNF[pin].SENSE = sense_type;
}

void gpio_configureOutputPin(const tGpio_pin pin)
{
    GPIO.PINCNF[pin].DIR = GPIO_DIR_OUTPUT;
    GPIO.PINCNF[pin].INPUT_BUFFER = GPIO_INBUF_DISCONNECT;
    GPIO.PINCNF[pin].DRIVE = GPIO_DRIVE_S0S1;
}

void gpio_customiseOutputPin(const tGpio_pin pin,
                                const tGpio_drive drive)
{
    GPIO.PINCNF[pin].DIR = GPIO_DIR_OUTPUT;
    GPIO.PINCNF[pin].INPUT_BUFFER = GPIO_INBUF_DISCONNECT;
    GPIO.PINCNF[pin].DRIVE = drive;
}