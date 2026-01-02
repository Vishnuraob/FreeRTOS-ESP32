#include "system_init.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "sensor_task.h"
#include "processing_task.h"
#include "logger_task.h"
#include "comm_task.h"
#include "health_task.h"
#include "sensor_driver.h"

QueueHandle_t sensor_queue = NULL;
QueueHandle_t processed_queue = NULL;

void system_init(void)
{
    sensor_queue = xQueueCreate(10, sizeof(sensor_data_t));
    processed_queue = xQueueCreate(10, sizeof(sensor_data_t));

    if (sensor_queue == NULL || processed_queue == NULL)
    {
        while (1);
    }

    xTaskCreate(sensor_task, "sensor_task", 4096, NULL, 5, NULL);
    xTaskCreate(processing_task, "processing_task", 4096, NULL, 4, NULL);
    xTaskCreate(logger_task, "logger_task", 4096, NULL, 2, NULL);
    xTaskCreate(comm_task, "comm_task", 4096, NULL, 2, NULL);
    xTaskCreate(health_task, "health_task", 4096, NULL, 6, NULL);
}
