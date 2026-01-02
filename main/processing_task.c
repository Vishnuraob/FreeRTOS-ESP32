#include "processing_task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

extern QueueHandle_t sensor_queue;
extern QueueHandle_t processed_queue;

void processing_task(void *pvParameters)
{
    sensor_data_t raw;
    sensor_data_t processed;

    while (1)
    {
        if (xQueueReceive(sensor_queue, &raw, portMAX_DELAY))
        {
            processed.value = raw.value * 0.98f;  // simple filter
            xQueueSend(processed_queue, &processed, portMAX_DELAY);
        }
    }
}
