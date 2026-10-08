/* Week 1 / Ex2 — the three competing tasks.
 *
 * Each task: raise its pin, burn exactly TASK_x_WORK_US of CPU, lower its pin,
 * and loop again WITHOUT blocking. The missing block is the point of the
 * exercise, not a bug to fix in step 2.
 */
#include "FreeRTOS.h"
#include "task.h"

#include "main.h"
#include "params.h"
#include "tasks.h"

/* TODO: one helper that takes a port/pin and a work time, then three thin
 *       wrappers. Do not copy-paste the body three times. */

void task_a(void *argument)
{
    (void)argument;
    for (;;) {
        /* TODO */
    }
}

void task_b(void *argument)
{
    (void)argument;
    for (;;) {
        /* TODO */
    }
}

void task_c(void *argument)
{
    (void)argument;
    for (;;) {
        /* TODO */
    }
}
