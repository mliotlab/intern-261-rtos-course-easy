#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>

/* Cycle-accurate busy wait built on the Cortex-M3 DWT cycle counter.
 * Must NOT block and must NOT call any HAL delay. */
void dwt_init(void);
void dwt_busy_wait_us(uint32_t microseconds);

void task_a(void *argument);
void task_b(void *argument);
void task_c(void *argument);

#endif /* TASKS_H */
