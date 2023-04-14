#include <inttypes.h>

typedef struct {

    volatile uint16_t head;
    volatile uint16_t tail;
    volatile uint16_t size_buffer;
    uint8_t *buffer;

} ring_buffer_t;

void ring_buffer_init(uint8_t *buffer, uint16_t size, ring_buffer_t *obj);

void ring_buffer_put(uint8_t item, ring_buffer_t *obj);

uint8_t ring_buffer_get(ring_buffer_t *obj);

uint8_t ring_buffer_show_byte(const ring_buffer_t *obj);

void ring_buffer_clear(ring_buffer_t *obj);