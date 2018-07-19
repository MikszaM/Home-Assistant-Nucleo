/*
 * control.c
 *
 *  Created on: 25.02.2018
 *      Author: Micha³M
 */
#include <stdint.h>
#include "control.h"
#include "signal_flag.h"
#include "pwm.h"
#include "feedback.h"
#include "stm32f1xx.h"

void dc_driver_init() {
	pwm_init();
	feedback_init();
	signal_flag_init();
	encoder_init();
	GPIO_CONTROL_ON;

	GPIO_InitTypeDef gpio;
	gpio.Pin = M1_D1_PIN;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(M1_D1_PORT, &gpio);

	gpio.Pin = M2_D1_PIN;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(M2_D1_PORT, &gpio);

	enable_motors();
}

void enable_motors(){
	HAL_GPIO_WritePin(M2_D1_PORT, M1_D1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_D1_PORT, M2_D1_PIN, GPIO_PIN_SET);
}

void disable_motors(){
	HAL_GPIO_WritePin(M2_D1_PORT, M1_D1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_D1_PORT, M2_D1_PIN, GPIO_PIN_RESET);
}

void m1_forward(int dc) {
	set_pwm1(dc);
	set_pwm2(0);
}
void m1_backward(int dc) {
	set_pwm2(dc);
	set_pwm1(0);
}
void m1_stop(){
	set_pwm1(0);
	set_pwm2(0);
}
void m2_forward(int dc) {
	set_pwm3(dc);
	set_pwm4(0);
}
void m2_backward(int dc) {
	set_pwm4(dc);
	set_pwm3(0);
}
void m2_stop(int dc){
	set_pwm3(0);
	set_pwm4(0);
}
uint16_t fb_read(int channel){
	return adc_read(channel);
}
