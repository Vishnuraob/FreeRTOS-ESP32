#include "sensor_driver.h"
#include "esp_random.h"

void sensor_read(sensor_data_t *data)
{
    data->value = (float)(esp_random() % 100);
}
