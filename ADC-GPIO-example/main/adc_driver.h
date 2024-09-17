#include "esp_adc/adc_oneshot.h"
#include <esp_err.h>

#ifndef __ADCDRIVER_H__
#define __ADCDRIVER_H__

// DHT22 Sensor Task
#define DHT22_TASK_STACK_SIZE 4096
#define DHT22_TASK_PRIORITY 4
#define DHT22_TASK_CORE_ID 1

#define DHT_OK 0
#define DHT_CHECKSUM_ERROR -1
#define DHT_TIMEOUT_ERROR -2

/**
 * Initializes ADC1_CH0 on GPIO1 (H2-board)
 */
void adc1_ch0_init();

// /**
//  * Starts DHT22 sensor task
//  * @return DHT_OK if successful, otherwise error code
//  */
// void DHT22_task_start(void);

/**
 * Get the ADC Value
 * @return ADC Value
 */
float getAdc();

/**
 * @brief Read from ADC 
 *
 * 
 * ADC values are returned as ????.
 *
 * @return `ESP_OK` on success
 */
esp_err_t read_adc_data();

#endif // __ADCDRIVER_H__