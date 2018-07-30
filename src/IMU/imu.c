/*
 * imu.c
 *
 *  Created on: 25.07.2018
 *      Author: Micha³M
 */

#include "imu.h"
#include "stm32f1xx.h"

I2C_HandleTypeDef i2c;

void imu_init(){
	GPIO_InitTypeDef gpio;

	I2C_GPIO_CLOCK_ON;
	I2C_CLOCK_ON;

	gpio.Mode = GPIO_MODE_AF_OD;
	gpio.Pin = SCL_PIN;
	gpio.Pull = GPIO_PULLUP;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(SCL_PORT, &gpio);

	gpio.Pin = SDA_PIN;
	HAL_GPIO_Init(SDA_PORT, &gpio);


	i2c.Instance = IMU_I2C;
	i2c.Init.ClockSpeed = 100000;
	i2c.Init.DutyCycle = I2C_DUTYCYCLE_2;
	i2c.Init.OwnAddress1 = 0xff;
	i2c.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	i2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	i2c.Init.OwnAddress2 = 0xff;
	i2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	i2c.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	HAL_I2C_Init(&i2c);
}


uint8_t read_register8(uint8_t dev_addr, uint8_t reg_addr){
	uint8_t read_value;
	HAL_I2C_Mem_Read(&i2c, dev_addr, reg_addr, 1, (uint8_t*)&read_value, sizeof(read_value), HAL_MAX_DELAY);
	return read_value;
}
uint16_t read_register16(uint8_t dev_addr, uint8_t reg_addr){
	uint16_t read_value;
	HAL_I2C_Mem_Read(&i2c, dev_addr, reg_addr, 1, (uint8_t*)&read_value, sizeof(read_value), HAL_MAX_DELAY);

	return read_value;
}
uint32_t read_register24(uint8_t dev_addr, uint8_t reg_addr){
	uint32_t read_value;
	HAL_I2C_Mem_Read(&i2c, dev_addr, reg_addr, 1, (uint8_t*)&read_value, 3, HAL_MAX_DELAY);

	return read_value;
}

void write_register(uint8_t dev_addr, uint8_t reg_aggr, uint8_t data){
	HAL_I2C_Mem_Write(&i2c, dev_addr, reg_aggr, 1, (uint8_t*)&data, sizeof(data), HAL_MAX_DELAY);
}


uint8_t read_hour(){
	uint8_t hour;

	hour = read_register8(RTC_ADDRESS, 0x02);
	hour=((hour>>4)*10)+(hour&0x0F);

	return hour;
}
void write_hour(uint8_t hour){
	uint8_t hourh,hourl,hourbcd;
	hourh=(hour-(hour%10))/10;
	hourl=hour%10;
	hourbcd=(hourh<<4)|hourl;
	write_register(RTC_ADDRESS, 0x02,hourbcd);
}
void acc_init(){
	uint8_t limit = (uint8_t)ACC_MAX;
	switch (limit){
	case 2:
		write_register(ACC_AND_GYRO_ADDRESS,0x10,0x20);
		break;
	case 4:
		write_register(ACC_AND_GYRO_ADDRESS,0x10,0x28);
		break;
	case 8:
		write_register(ACC_AND_GYRO_ADDRESS,0x10,0x2C);
		break;
	case 16:
		write_register(ACC_AND_GYRO_ADDRESS,0x10,0x24);
		break;
	}
}
void gyro_init(){
	uint16_t limit = (uint16_t)GYRO_MAX;
	switch (limit){
	case 245:
		write_register(ACC_AND_GYRO_ADDRESS,0x11,0x20);
		break;
	case 500:
		write_register(ACC_AND_GYRO_ADDRESS,0x11,0x24);
		break;
	case 1000:
		write_register(ACC_AND_GYRO_ADDRESS,0x11,0x28);
		break;
	case 2000:
		write_register(ACC_AND_GYRO_ADDRESS,0x11,0x2C);
		break;
	}
}
void magn_init(){
	uint8_t limit = (uint8_t)MAGN_MAX;
	write_register(MAGNETOMETER_ADDRESS,0x22,0x00);
	write_register(MAGNETOMETER_ADDRESS,0x20,0x14);
	switch (limit){
	case 4:
		write_register(MAGNETOMETER_ADDRESS,0x21,0x00);
		break;
	case 8:
		write_register(MAGNETOMETER_ADDRESS,0x21,0x20);
		break;
	case 12:
		write_register(MAGNETOMETER_ADDRESS,0x21,0x40);
		break;
	case 16:
		write_register(MAGNETOMETER_ADDRESS,0x21,0x60);
		break;
	}
}
void baro_init(){
	write_register(BAROMETER_ADDRESS,0x20,0xC0);
}
int16_t read_acc(char dir){
	switch (dir){
	case 'x':
		return read_register16(ACC_AND_GYRO_ADDRESS,0x28);
		break;
	case 'y':
		return read_register16(ACC_AND_GYRO_ADDRESS,0x2A);
		break;
	case 'z':
		return read_register16(ACC_AND_GYRO_ADDRESS,0x2C);
		break;
	default:
		return -1;
	}
}
int16_t read_gyro(char dir){
	switch (dir){
	case 'x':
		return read_register16(ACC_AND_GYRO_ADDRESS,0x22);
		break;
	case 'y':
		return read_register16(ACC_AND_GYRO_ADDRESS,0x24);
		break;
	case 'z':
		return read_register16(ACC_AND_GYRO_ADDRESS,0x26);
		break;
	default:
		return -1;
	}
}
int16_t read_magn(char dir){
	switch (dir){
	case 'x':
		return read_register16(MAGNETOMETER_ADDRESS,0x28|0x80);
		break;
	case 'y':
		return read_register16(MAGNETOMETER_ADDRESS,0x2A|0x80);
		break;
	case 'z':
		return read_register16(MAGNETOMETER_ADDRESS,0x2C|0x80);
		break;
	default:
		return -1;
	}
}
uint32_t read_baro(){
	return read_register24(BAROMETER_ADDRESS,0x28|0x80);
}
