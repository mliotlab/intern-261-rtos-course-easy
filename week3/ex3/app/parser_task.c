/* Week 3 / Ex3 -- command parser: rx_stream -> change demo_task's
 * period/priority/suspend state at runtime.
 *
 * Commands (each terminated by '\r', max MAX_CMD_LEN bytes):
 *   P<ms>\r   -- set demo_task period to <ms>
 *   S<prio>\r -- vTaskPrioritySet(demo_task, <prio>)
 *   T<0|1>\r  -- 0 = vTaskSuspend(demo_task), 1 = vTaskResume(demo_task)
 */
#include <stdint.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "stream_buffer.h"

#include "main.h"
#include "params.h"
#include "uart_rx.h"
#include "parser_task.h"

static TaskHandle_t s_demo_task_handle;
static volatile uint32_t s_demo_period_ms = 200;

static void apply_command(const char *cmd, size_t len)
{
    /* TODO 1: switch on cmd[0]: 'P' -> parse decimal into s_demo_period_ms
     *         (demo_task reads this every loop, no restart needed);
     *         'S' -> parse decimal, vTaskPrioritySet(s_demo_task_handle, n);
     *         'T' -> cmd[1]=='0' ? vTaskSuspend(...) : vTaskResume(...).
     *         Ignore anything malformed -- do not crash on bad input. */
    (void)cmd;
    (void)len;
}

void parser_task(void *argument)
{
    (void)argument;
    char cmd[MAX_CMD_LEN];
    size_t idx = 0;

    for (;;) {
        uint8_t byte;

        /* TODO 2: xStreamBufferReceive(rx_stream, &byte, 1, portMAX_DELAY). */

        /* TODO 3: if byte == '\r', call apply_command(cmd, idx), idx = 0.
         *         else if idx < MAX_CMD_LEN - 1, cmd[idx++] = byte.
         *         else (overflow): discard the whole partial command, idx = 0
         *         -- explain in REPORT.md why silently truncating instead
         *         would be worse. */
        (void)byte;
        (void)cmd;
        (void)idx;
    }
}

void demo_task(void *argument)
{
    (void)argument;
    s_demo_task_handle = xTaskGetCurrentTaskHandle();

    for (;;) {
        /* TODO 4: toggle a GPIO pin here. */
        vTaskDelay(pdMS_TO_TICKS(s_demo_period_ms));
    }
}
