#include "health_task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "HEALTH";

void health_task(void *pvParameters)
{
    while (1)
    {
        ESP_LOGI(TAG, "Health check OK");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
