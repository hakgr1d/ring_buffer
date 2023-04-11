
#include "buffer_ring.h"


void ring_buffer_init(uint8_t *buffer, uint16_t size, ring_buffer_t *obj) {

    /**
    * @brief initializing the buffer with an array allocated on the stack
    * @arg uint8_t * buffer,
    * @arg uint16_t size,
    * @arg ring_buffer_t *obj,
    * 
    * @retval None
    */

    obj->buffer = buffer;
    obj->size_buffer = size;
    obj->head = 0;
    obj->tail = 0;

}

void ring_buffer_put(const uint8_t item, ring_buffer_t *obj){
    /**
    * @brief write bite on buffer,
    * @arg uint8_t write_bite,
    * @arg ring_buffer_t *obj,
    * @retval None
    */

    obj->buffer[(obj->tail)++] = item;
    obj->tail %= obj->size_buffer;
}

uint8_t ring_buffer_get(ring_buffer_t *obj) {
    /**
    * @brief read bite on buffer,
    * @arg ring_buffer_t *obj,
    * @retval uint8_t
    */
    

    uint8_t item = obj->buffer[(obj->head)++];
    obj->head %= obj->size_buffer;
    return item;
}
