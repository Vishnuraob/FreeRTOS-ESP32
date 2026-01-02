#ifndef SENSOR_DRIVER_H
#define SENSOR_DRIVER_H

typedef struct
{
    float value;
} sensor_data_t;

void sensor_read(sensor_data_t *data);

#endif
