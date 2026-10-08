#ifndef LOGGER_TASK_H
#define LOGGER_TASK_H

/* Consumes sample_queue, batches LOG_BLOCK_SAMPLES samples, writes one
 * UART block (UART_BAUD) at a time. Must finish processing each sample
 * well inside ISR_TO_PROC_DEADLINE_US on average -- the worst case is
 * measured for real in week4/ex3. */
void logger_task(void *argument);

#endif /* LOGGER_TASK_H */
