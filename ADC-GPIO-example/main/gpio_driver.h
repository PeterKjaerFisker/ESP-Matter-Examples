#include <driver/gpio.h>
#include <esp_err.h>

#ifndef __GPIODRIVER_H__
#define __GPIODRIVER_H__

// DHT22 Sensor Task
#define DHT22_TASK_STACK_SIZE 4096
#define DHT22_TASK_PRIORITY 4
#define DHT22_TASK_CORE_ID 1

#define DHT_GPIO GPIO_NUM_3 // GPIO pin connected to the DHT22

#define DHT_OK 0
#define DHT_CHECKSUM_ERROR -1
#define DHT_TIMEOUT_ERROR -2

// /**
//  * Starts DHT22 sensor task
//  * @return DHT_OK if successful, otherwise error code
//  */
// void DHT22_task_start(void);

/**
 * Get the GPIO data
 * @return GPIO data
 */
float getGpio();

/**
 * @brief Read from GPIO 
 *
 * 
 * GPIO values are returned as ????.
 *
 * @return `ESP_OK` on success
 */
esp_err_t read_gpio_data();

#endif // __GPIODRIVER_H__