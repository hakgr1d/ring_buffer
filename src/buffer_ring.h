
#ifndef STM32F103UART_BUFFER_RING_H
#define STM32F103UART_BUFFER_RING_H

#include <stdio.h>
#include <inttypes.h>
#include "stm32f1xx_hal.h"


typedef struct  {

    volatile size_t head;
    volatile size_t tail;
    volatile size_t size_buffer;
    uint8_t *buffer;

}ring_buffer_t;

void ring_buffer_init(uint8_t *buffer, uint16_t size, ring_buffer_t *obj);

void ring_buffer_put(uint8_t item, ring_buffer_t *obj);

uint8_t ring_buffer_get(ring_buffer_t *obj);

#endif //STM32F103UART_BUFFER_RING_H
