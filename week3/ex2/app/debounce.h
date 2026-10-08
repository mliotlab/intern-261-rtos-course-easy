#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include <stdint.h>

/* Creates debounce_timer (one-shot, DEBOUNCE_MS) and longpress_timer
 * (auto-reload, LONGPRESS_MS). Call once before vTaskStartScheduler(). */
void debounce_init(void);

/* Call from HAL_GPIO_EXTI_Callback() for the button pin, on EVERY edge
 * (including bounce) with the new pin level. */
void debounce_on_edge(uint8_t pin_is_high);

#endif /* DEBOUNCE_H */
