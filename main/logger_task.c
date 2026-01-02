#include "logger_task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "esp_log.h"

static const char *TAG = "LOGGER";

extern QueueHandle_t processed_queue;

void logger_task(void *pvParameters)
{
    sensor_data_t data;

    while (1)
    {
        if (xQueueReceive(processed_queue, &data, portMAX_DELAY))
        {
            ESP_LOGI(TAG, "Processed value: %.2f", data.value);
        }
    }
}
