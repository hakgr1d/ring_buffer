
#include "buffer_ring.h"


void ring_buffer_init(uint8_t *buffer, uint16_t size, ring_buffer_t *obj) {
    obj->buffer = buffer;
    obj->size_buffer = size;
    obj->head = 0;
    obj->tail = 0;
}
void ring_buffer_put(uint8_t item, ring_buffer_t *obj){
    obj->buffer[(obj->tail)++] = item;
    obj->tail %= obj->size_buffer;
}

uint8_t ring_buffer_get(ring_buffer_t *obj) {
    uint8_t item = obj->buffer[(obj->head)++];
    obj->head %= obj->size_buffer;
    return item;
}

