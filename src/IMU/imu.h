/*
 * imu.h
 *
 *  Created on: 25.07.2018
 *      Author: Micha³M
 */

#include "stm32f1xx.h"

#ifndef IMU_H_
#define IMU_H_



#endif /* IMU_H_ */


#define IMU_I2C I2C2
#define I2C_CLOCK_ON __HAL_RCC_I2C2_CLK_ENABLE()

#define SCL_PORT GPIOB
#define SCL_PIN GPIO_PIN_10

#define SDA_PORT GPIOB
#define SDA_PIN GPIO_PIN_11

#define I2C_GPIO_CLOCK_ON __HAL_RCC_GPIOB_CLK_ENABLE()

//#define RTC_ADDRESS 0x68<<1
#define ACC_AND_GYRO_ADDRESS 0x6B<<1
#define MAGNETOMETER_ADDRESS 0x1E<<1
#define BAROMETER_ADDRESS 0x5D<<1

#define ACC_MAX 2.0f
#define ACC_BITS 32678.0f

#define GYRO_MAX 500.0f
#define GYRO_BITS 32678.0f

#define MAGN_MAX 4.0f
#define MAGN_BITS 32678.0f

#define BARO_BITS 4096.0f

void imu_init();
void gyro_init();
void magn_init();
void baro_init();


uint8_t read_register8(uint8_t dev_addr, uint8_t reg_aggr);
uint16_t read_register16(uint8_t dev_addr, uint8_t reg_addr);
uint32_t read_register24(uint8_t dev_addr, uint8_t reg_addr);
//uint8_t read_hour();
//void write_hour(uint8_t hour);
void acc_init();
void write_register(uint8_t dev_addr, uint8_t reg_aggr, uint8_t data);
int16_t read_acc(char dir);
int16_t read_gyro(char dir);
int16_t read_magn(char dir);
uint32_t read_baro();
