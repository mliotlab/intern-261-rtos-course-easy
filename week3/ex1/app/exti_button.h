#ifndef EXTI_BUTTON_H
#define EXTI_BUTTON_H

#include <stdint.h>

/* Configures PB<EXTI_PIN> as EXTI falling-edge input and sets the NVIC
 * priority for its line. Call once before vTaskStartScheduler(). */
void exti_button_init(void);

/* Woken by exti_button_isr_handler() via vTaskNotifyGiveFromISR(). Toggles
 * PA<ACK_PIN> immediately on wake -- this edge is what you measure latency
 * against on the logic analyzer. */
void ack_task(void *argument);

/* Call this from HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) in
 * stm32f1xx_it.c, guarded by `if (GPIO_Pin == (1u << EXTI_PIN))`. */
void exti_button_isr_handler(void);

#endif /* EXTI_BUTTON_H */
