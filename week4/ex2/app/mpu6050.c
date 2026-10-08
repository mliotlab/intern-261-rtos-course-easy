/* Week 4 / Ex2 -- MPU6050 over I2C1.
 * Native FreeRTOS API only.
 */
#include "main.h"
#include "mpu6050.h"

#define MPU6050_ADDR        (0x68 << 1)
#define REG_PWR_MGMT_1       0x6B
#define REG_ACCEL_XOUT_H     0x3B

void mpu6050_init(void)
{
    /* TODO 1: HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, REG_PWR_MGMT_1, 1,
     *         &(uint8_t){0}, 1, 100) -- wake the sensor up out of sleep. */
}

void mpu6050_read_sample(sensor_sample_t *out)
{
    /* TODO 2: HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, REG_ACCEL_XOUT_H, 1,
     *         buf, 14, 100) -- 14 bytes: accel x/y/z, temp, gyro x/y/z,
     *         big-endian. Fill out->timestamp with the DWT cycle counter
     *         (reuse runtime_stats_timer_value() style from week3/ex4) and
     *         the fields you added to sensor_sample_t in week4/ex1. */
    (void)out;
}
