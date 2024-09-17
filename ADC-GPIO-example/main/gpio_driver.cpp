#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE

#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "driver/gpio.h"

#include "gpio_driver.h"

// DHT timer precision in microseconds
#define DHT_TIMER_INTERVAL 2
#define DHT_DATA_BITS 40
#define DHT_DATA_BYTES (DHT_DATA_BITS / 8)

// == global defines =============================================

static const char *TAG = "GPIO_driver";

int gpio_value = 0;

static portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
#define PORT_ENTER_CRITICAL() portENTER_CRITICAL(&mux)
#define PORT_EXIT_CRITICAL() portEXIT_CRITICAL(&mux)

/**
 * Get the GPIO value
 */
float getGpio()
{
    return gpio_value;
}

esp_err_t read_gpio_data()
{
    esp_err_t res = ESP_OK;

    gpio_set_direction(DHT_GPIO, GPIO_MODE_INPUT);

    gpio_value = gpio_get_level(DHT_GPIO);

    ESP_LOGE(TAG, "################################### Read data: gpio_value=%i", gpio_value);

    if (res != ESP_OK)
    {
        return res;
    }

    return ESP_OK;
}