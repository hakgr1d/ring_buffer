#include "buffer_ring.h"


uint16_t mod(uint16_t divisible, uint16_t divider){

 /**
  * @brief initializing the buffer with an array allocated on the stack
  * @arg int16_t divisible,
  * @arg uint16_t divider
  * @retval residue of divisible % divider
  */

    while (divisible >= divider){
        divisible -= divider;
    }
    return divisible;
}

void ring_buffer_init(uint8_t *buffer, uint16_t size, ring_buffer_t *obj) {

    /**
     * @brief initializing the buffer with an array allocated on the stack
     * @arg uint8_t * buffer,
     * @arg uint16_t size,
     * @arg ring_buffer_t *obj,
     * @retval None
     */

    obj->buffer = buffer;
    obj->size_buffer = size;
    obj->head = 0;
    obj->tail = 0;

}

void ring_buffer_put(const uint8_t item, ring_buffer_t *obj) {

    /**
     * @brief write bite on buffer,
     * @arg uint8_t write_bite,
     * @arg ring_buffer_t *obj,
     * @retval None
     */

    obj->buffer[(obj->tail)++] = item;
    obj->tail = mod(obj->tail, obj->size_buffer);
}

uint8_t ring_buffer_get(ring_buffer_t *obj) {

    /**
     * @brief read byte on buffer (modifying the buffer),
     * @arg ring_buffer_t *obj,
     * @retval uint8_t
     */


    uint8_t item = obj->buffer[(obj->head)++];
    obj->head = mod(obj->head, obj->size_buffer);
    //    obj->head %= obj->size_buffer;
    return item;
}

uint8_t ring_buffer_show_byte(const ring_buffer_t *obj) {

    /**
     * @brief read byte on buffer (not modifying the buffer),
     * @arg const ring_buffer_t *obj,
     * @retval uint8_t
     */

    uint8_t item = obj->buffer[obj->head];
    return item;
}


void ring_buffer_clear(ring_buffer_t *obj) {

    /**
     * @brief clearing buffer,
     * @arg ring_buffer_t *obj,
     * @retval None
     */

    for (int i = 0; i < obj->size_buffer; ++i) {
        obj->buffer[i] = '\0';
    }
}
