#ifndef GPIO_HAL_H
#define GPIO_HAL_H

/**
 * @brief Pin state enum
 *
 */
typedef enum
{
    LOW,
    HIGH
} tGpio_pinState;

/**
 * @brief GPIO operation status enum
 *
 */
typedef enum
{
    GPIO_STATUS_OK,
    GPIO_STATUS_INVALID
} tGpio_status;

/**
 * @brief GPIO pin enum
 *
 */
typedef enum
{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15,
    GPIO_PIN16,
    GPIO_PIN17,
    GPIO_PIN18,
    GPIO_PIN19,
    GPIO_PIN20,
    GPIO_PIN21,
    GPIO_PIN22,
    GPIO_PIN23,
    GPIO_PIN24,
    GPIO_PIN25,
    GPIO_PIN26,
    GPIO_PIN27,
    GPIO_PIN28,
    GPIO_PIN29,
    GPIO_PIN30,
    GPIO_PIN31,
    GPIO_PIN_MAX
} tGpio_pin;


/**
 * @brief Pin direction enum
 *
 */
typedef enum
{
    GPIO_DIR_INPUT,
    GPIO_DIR_OUTPUT
} tGpio_dir;

/**
 * @brief Input buffer setting enum
 *
 */
typedef enum
{
    GPIO_INBUF_CONNECT,
    GPIO_INBUF_DISCONNECT
} tGpio_inBuf;

/**
 * @brief Pin pull direction enum (input)
 *
 */
typedef enum
{
    GPIO_PULL_DISABLED,
    GPIO_PULL_DOWN,
    GPIO_PULL_UP = 3
} tGpio_pull;

/**
 * @brief Pin drive configuration enum (output)
 *
 */
typedef enum
{
    GPIO_DRIVE_S0S1,    // Standard '0', standard '1'
    GPIO_DRIVE_H0S1,    // High drive '0', standard '1'
    GPIO_DRIVE_S0H1,    // Standard '0', high drive '1'
    GPIO_DRIVE_H0H1,    // High drive '0', high drive '1'
    GPIO_DRIVE_D0S1,    // Disconnect '0', standard '1' (wired-or)
    GPIO_DRIVE_D0H1,    // Disconnect '0', high drive '1' (wired-or)
    GPIO_DRIVE_S0D1,    // Standard '0', disconnect '1' (wired-and)
    GPIO_DRIVE_H0D1,    // High drive '0', disconnect '1' (wired-and)
} tGpio_drive;

/**
 * @brief Pin sense configuration enum (input)
 *
 */
typedef enum
{
    GPIO_SENSE_DISABLED,    // Pin sensing mechanism disabled
    GPIO_SENSE_HIGH = 2,    // Sense for high level
    GPIO_SENSE_LOW          // Sense for low level
} tGpio_sense;

/**
 * @brief Configures a pin as a standard input
 * 
 * @param[in] pin The pin to configure
 */
void gpio_configureInputPin(const tGpio_pin pin);

/**
 * @brief Configures a pin as a customised input
 * 
 * @param[in] pin The pin to be configured
 * @param[in] pull The pull direction for the pin
 * @param[in] sense_type The sensing configuration to use
 */
void gpio_customiseInputPin(const tGpio_pin pin,
                                const tGpio_pull pull,
                                const tGpio_sense sense_type);

/**
 * @brief Configure pin as a standard output
 * 
 * @param[in] pin The pin to be configured
 */
void gpio_configureOutputPin(const tGpio_pin pin);

/**
 * @brief Configure pin as a customised output
 * 
 * @param[in] pin The pin to be configured
 * @param[in] drive The pin drive setting
 */
void gpio_customiseOutputPin(const tGpio_pin pin,
                                const tGpio_drive drive);

#endif  // GPIO_HAL_H