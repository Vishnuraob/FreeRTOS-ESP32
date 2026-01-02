#include "system_init.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "sensor_task.h"
#include "processing_task.h"
#include "logger_task.h"
#include "comm_task.h"
#include "health_task.h"

void system_init(void)
{
    xTaskCreate(sensor_task, "sensor_task", 4096, NULL, 5, NULL);
    xTaskCreate(processing_task, "processing_task", 4096, NULL, 4, NULL);
    xTaskCreate(logger_task, "logger_task", 4096, NULL, 2, NULL);
    xTaskCreate(comm_task, "comm_task", 4096, NULL, 2, NULL);
    xTaskCreate(health_task, "health_task", 4096, NULL, 6, NULL);
}
