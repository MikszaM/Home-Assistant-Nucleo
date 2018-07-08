/*
 * control.c
 *
 *  Created on: 25.02.2018
 *      Author: Micha³M
 */

#include "control.h"
#include "pwm.h"
#include "feedback.h"
#include "stm32f1xx.h"

void driver_init() {
	pwm_init();
	feedback_init();

	GPIO_CONTROL_ON;

	GPIO_InitTypeDef gpio;
	gpio.Pin = M1_IN1_PIN;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(M1_IN1_PORT, &gpio);

	gpio.Pin = M1_IN2_PIN;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(M1_IN2_PORT, &gpio);

	gpio.Pin = M2_IN1_PIN;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(M2_IN1_PORT, &gpio);

	gpio.Pin = M2_IN2_PIN;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(M2_IN2_PORT, &gpio);

}

void m1_forward() {
	HAL_GPIO_WritePin(M1_IN1_PORT, M1_IN1_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN2_PORT, M1_IN2_PIN,GPIO_PIN_SET);
}
void m1_backward() {
	HAL_GPIO_WritePin(M1_IN1_PORT, M1_IN1_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN2_PORT, M1_IN2_PIN,GPIO_PIN_RESET);
}
void m1_stop(){
	HAL_GPIO_WritePin(M1_IN1_PORT, M1_IN1_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN2_PORT, M1_IN2_PIN,GPIO_PIN_SET);
}
void m2_forward() {
	HAL_GPIO_WritePin(M2_IN1_PORT, M2_IN1_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN2_PORT, M2_IN2_PIN,GPIO_PIN_SET);
}
void m2_backward() {
	HAL_GPIO_WritePin(M2_IN1_PORT, M2_IN1_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN2_PORT, M2_IN2_PIN,GPIO_PIN_RESET);
}
void m2_stop(){
	HAL_GPIO_WritePin(M2_IN1_PORT, M2_IN1_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN2_PORT, M2_IN2_PIN,GPIO_PIN_SET);
}
void m1_pwm(int dc){
	set_pwm1(dc);
}
void m2_pwm(int dc){
	set_pwm2(dc);
}
int fb_read(int channel){
	return adc_read(channel);
}
