#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE

#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "esp_adc/adc_oneshot.h"

#include "adc_driver.h"

// DHT timer precision in microseconds
#define DHT_TIMER_INTERVAL 2
#define DHT_DATA_BITS 40
#define DHT_DATA_BYTES (DHT_DATA_BITS / 8)

// == global defines =============================================

static const char *TAG = "ADC_driver";

int adc_value = 0;
adc_oneshot_unit_handle_t adc1_handle;

static portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
#define PORT_ENTER_CRITICAL() portENTER_CRITICAL(&mux)
#define PORT_EXIT_CRITICAL() portEXIT_CRITICAL(&mux)

/**
 * Initializes ADC1_CH0 on GPIO1 (H2-board)
 */
void adc1_ch0_init()
{
    const adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
        .ulp_mode = ADC_ULP_MODE_DISABLE,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    adc_oneshot_chan_cfg_t channel_config = {
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL_4, &channel_config));
}

/**
 * Get the ADC value
 */
float getAdc()
{
    return adc_value;
}

esp_err_t read_adc_data()
{
    esp_err_t res = ESP_OK;
    int adc_meas = 0;

    ESP_ERROR_CHECK(adc_oneshot_read(adc1_handle, ADC_CHANNEL_4, &adc_meas));

    adc_value = adc_meas + 0; 

    ESP_LOGE(TAG, "################################### Sensor data: temp=%d, temp2=%X", adc_meas, adc_meas);

    if (res != ESP_OK)
    {
        return res;
    }

    return ESP_OK;
}