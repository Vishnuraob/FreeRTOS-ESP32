#include "ring_buffer.h"

void ring_buffer_init(ring_buffer_t *rb, uint8_t *buf, uint16_t size)
{
    rb->buffer = buf;
    rb->size = size;
    rb->head = rb->tail = 0;
}

uint8_t ring_buffer_write(ring_buffer_t *rb, uint8_t data)
{
    uint16_t next = (rb->head + 1) % rb->size;
    if (next == rb->tail) return 0;
    rb->buffer[rb->head] = data;
    rb->head = next;
    return 1;
}

uint8_t ring_buffer_read(ring_buffer_t *rb, uint8_t *data)
{
    if (rb->head == rb->tail) return 0;
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->size;
    return 1;
}
