/* Week 1 / Ex4 — FreeRTOS hooks.
 *
 * Both hooks must be observable from outside the chip. A breakpoint is not a
 * deliverable: you need a UART line or a distinct LED pattern you can photograph.
 */
#include "FreeRTOS.h"
#include "task.h"

#include "main.h"
#include "params.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    /* TODO 1: report xTask / pcTaskName out of the chip, then stop.
     *
     * Careful: the stack of the offending task is already corrupt. Think about
     * what you are allowed to call here, and write the reasoning in REPORT.md.
     * Hint: this hook runs from the scheduler's context, not the task's.
     */
    (void)xTask;
    (void)pcTaskName;
    for (;;) {
    }
}

void vApplicationMallocFailedHook(void)
{
    /* TODO 2: report, then stop. */
    for (;;) {
    }
}

/* configSUPPORT_STATIC_ALLOCATION = 1 makes these two callbacks mandatory.
 * Provide the memory for the idle task and the timer task here. */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize)
{
    /* TODO 3: static buffers. Note the size is in WORDS, not bytes —
     *         getting this wrong is a silent overflow. */
    (void)ppxIdleTaskTCBBuffer;
    (void)ppxIdleTaskStackBuffer;
    (void)pulIdleTaskStackSize;
}

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
                                    StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize)
{
    /* TODO 4: same, for the software timer task. */
    (void)ppxTimerTaskTCBBuffer;
    (void)ppxTimerTaskStackBuffer;
    (void)pulTimerTaskStackSize;
}
