#ifndef UART_RX_H
#define UART_RX_H

#include <stdint.h>
#include "FreeRTOS.h"
#include "stream_buffer.h"

extern StreamBufferHandle_t rx_stream;

/* Creates rx_stream (STREAM_BUFFER_BYTES, trigger level TRIGGER_LEVEL) and
 * arms the first HAL_UART_Receive_IT(). Call once before
 * vTaskStartScheduler(). */
void uart_rx_init(void);

/* Called from HAL_UART_RxCpltCallback(huart) for USART1. Pushes the one
 * received byte into rx_stream and re-arms HAL_UART_Receive_IT() for the
 * next byte. */
void uart_rx_isr_handler(void);

#endif /* UART_RX_H */
