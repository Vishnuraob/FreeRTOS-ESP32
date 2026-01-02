#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

typedef struct
{
    uint8_t *buffer;
    uint16_t size;
    uint16_t head;
    uint16_t tail;
} ring_buffer_t;

void ring_buffer_init(ring_buffer_t *rb, uint8_t *buf, uint16_t size);
uint8_t ring_buffer_write(ring_buffer_t *rb, uint8_t data);
uint8_t ring_buffer_read(ring_buffer_t *rb, uint8_t *data);

#endif
