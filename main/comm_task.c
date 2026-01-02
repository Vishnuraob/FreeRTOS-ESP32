#include "comm_task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "COMM";

void comm_task(void *pvParameters)
{
    while (1)
    {
        ESP_LOGI(TAG, "System alive");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
