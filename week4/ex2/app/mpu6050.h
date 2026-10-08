#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>
#include "datalogger_types.h"

/* I2C1 init + MPU6050 wake-up (PWR_MGMT_1 = 0). */
void mpu6050_init(void);

/* Blocking read of one sample (accel + gyro), called from sampler_isr's
 * timer callback context -- keep this SHORT, it runs with interrupts of
 * lower priority masked. If a full I2C transaction is too slow to fit in
 * ISR_TO_PROC_DEADLINE_US, say so in REPORT.md and switch to DMA or to a
 * lower-priority polling task instead -- do not silently block forever. */
void mpu6050_read_sample(sensor_sample_t *out);

#endif /* MPU6050_H */
