/* Week 4 / Ex2 -- timer ISR that samples MPU6050 at SAMPLE_RATE_HZ and
 * feeds sample_queue.
 * Native FreeRTOS API only.
 */
#include "FreeRTOS.h"
#include "queue.h"

#include "main.h"
#include "params.h"
#include "datalogger_types.h"
#include "mpu6050.h"
#include "sampler_isr.h"

QueueHandle_t sample_queue;

void sampler_isr_init(void)
{
    /* TODO 1: create sample_queue = xQueueCreate(N, sizeof(sensor_sample_t))
     *         before the scheduler starts -- pick N from your ex1 RAM
     *         budget, not an arbitrary number.
     *
     * TODO 2: configure a free-running timer (NOT TIM4) to interrupt at
     *         SAMPLE_RATE_HZ and call sampler_timer_callback() from its
     *         IRQ handler. Set its NVIC priority numerically AT OR BELOW
     *         configMAX_SYSCALL_INTERRUPT_PRIORITY (i.e. a priority value
     *         that is numerically >= the threshold) so FromISR calls are
     *         legal -- see week3/ex1 if you need a refresher on why. */
}

void sampler_timer_callback(void)
{
    sensor_sample_t s;
    mpu6050_read_sample(&s);

    /* BUG (seeded, you must find and fix this): xQueueSend() is the
     * task-context API. Calling it from an ISR is undefined behavior --
     * it can call the scheduler directly instead of deferring via
     * xHigherPriorityTaskWoken, which configASSERT will catch (or, if
     * asserts are compiled out, it can corrupt the scheduler's internal
     * state silently). Replace with xQueueSendFromISR() and the
     * xHigherPriorityTaskWoken + portYIELD_FROM_ISR() pattern from
     * week3/ex1's ack_task wake-up. */
    xQueueSend(sample_queue, &s, 0);
}
