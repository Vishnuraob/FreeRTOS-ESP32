#include "sensor_task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "sensor_driver.h"

extern QueueHandle_t sensor_queue;

void sensor_task(void *pvParameters)
{
    sensor_data_t data;

    while (1)
    {
        sensor_read(&data);
        xQueueSend(sensor_queue, &data, portMAX_DELAY);
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}
